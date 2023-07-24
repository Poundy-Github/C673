"""
 Copyright (C) Elektrobit Automotive GmbH
 All rights exclusively reserved for Elektrobit Automotive GmbH,
 unless expressly agreed to otherwise.
"""

"""
    What does the diagram show?
    The diagram shows the generated tasks and all runnables running in that task which are either directly mapped
    i.e. via an event-to-task mapping or directly called from another runnable (direct calling chain).
    In addition, it shows if a runnable needs an explicit or implicit waitpoint and is thus of category 2. An explicit
    waitpoint is a waitpoint that is explicitly configured in the model e.g. to configure a blocking API whereas an
    implicit waitpoint is shown if the Rte implementation requires a WaitEvent() call.
    If a runnable has such a waitpoint it is colored red, otherwise green.
    
    What is the purpose of the diagram?
    With the help of the diagram, it is possible to better understand if a task needs to be an extended task. If at least one runnable
    which is running in that task needs a waitpoint, then it is of category 2 and thus the whole task needs a wait state, too (extended task).
    By looking at the diagram, it is possible to easily identify such runnables and to know which one caused the task to be extended.
    Please note: There are many more conditions that need to be checked whether a task is basic or extended. This diagram mainly focuses on
    the calling chains and possible wait points.

    Disclaimer: This script for generating the diagram is only an example and does not claim to be complete or correct. It is only
    a support to better understand the internal data model of the generator and the decisions made during the code generation. 
"""




from rtegraph import graph_generator
from rtegraph.constants import *
from collections import OrderedDict
def add_executable(graph_generator, cluster, executable):
    category = executable.findtext("category")
    executable_node = graph_generator.get_or_create_node(cluster, executable, "{{name}}\nsymbol: {{entryPoint}}", style=(
        RUNNABLE_CAT2_STYLE if category == "CAT2" else RUNNABLE_CAT1_STYLE))
    if executable.findtext("waitPoints") == "true":
        waitpoint_node = graph_generator.get_or_create_node_with_customized_id(
            cluster.id+"_"+executable.get("id")+"_wpExplicit", cluster, text="Explicit\nWaitpoint", style=WAITPOINT_STYLE)        
        graph_generator.connect(executable_node, waitpoint_node, cluster)
    for api in graph_generator.find_and_resolve_references(executable, "apis/apiRef"):
        found_direct_call_executable = False
        for direct_called_executable in graph_generator.find_and_resolve_references(api, "directCalledExecutables/executableRef"):
            found_direct_call_executable = True
            api_node = graph_generator.get_or_create_node(
                cluster, api, "{{externalName}}", style=API_STYLE)
            direct_executable_node = add_executable(
                graph_generator, cluster, direct_called_executable)
            graph_generator.connect(executable_node, api_node, cluster)
            graph_generator.connect(api_node, direct_executable_node, cluster)
        oi = graph_generator.find_and_resolve_reference(
            api, "operationInstanceRef")
        if oi != None and not found_direct_call_executable: #ignore waitpoint if inherited from directly called runnable
            if oi.findtext("synchronousWaitPointRequired") == "true": 
                api_node = graph_generator.get_or_create_node(
                    cluster, api, "{{externalName}}", style=API_STYLE)
                waitpoint_node = graph_generator.get_or_create_node_with_customized_id(
                    cluster.id+"_"+api_node.id+"_wpImplicit", cluster, text="Implicit\nWaitpoint", style=WAITPOINT_STYLE)
                graph_generator.connect(executable_node, api_node, cluster)
                graph_generator.connect(api_node, waitpoint_node, cluster)

    return executable_node


def create_graph(graph_generator):
    graph_generator.set_title("Tasks")
    root = graph_generator.get_model_root()

    tasks = root.findall("partitions/partition/tasks/task") + \
        root.findall("partitions/partition/Interrupts/Interrupt")

    if not tasks:
        return False

    for task in tasks:
        name = task.findtext("name")
        cluster = graph_generator.get_or_create_cluster(name, name)
        task_node = graph_generator.get_or_create_node(
            cluster, task, """{{name}}
priority: {{priority}}
Configured Priority: {{configuredPriority}}""", style=TASK_STYLE)
        for event in graph_generator.find_and_resolve_references(task, "eventInstances/eventInstanceRef"):
            # todo consider mode switch event groups
            if event.tag == "modeSwitchEventGroupInstance":
                task_event_mappings = event.findall(
                    "*/*/modeSwitchEventInstances/*/taskEventMappings/taskEventMapping")
            else:
                task_event_mappings = event.findall(
                    "taskEventMappings/taskEventMapping")

            for task_event_mapping in task_event_mappings:
                executable = graph_generator.find_and_resolve_reference(
                    task_event_mapping, "executableRef")
                executable_node = add_executable(
                    graph_generator, cluster, executable)
                event_name = task_event_mapping.findtext("eventName")
                graph_generator.connect(
                    task_node, executable_node, cluster, label=event_name)
