"""
 Copyright (C) Elektrobit Automotive GmbH
 All rights exclusively reserved for Elektrobit Automotive GmbH,
 unless expressly agreed to otherwise.
"""

"""
    What does the diagram show?
    The diagram shows the context for every runnable which is either one or multiple tasks or other runnables in between (direct calling chains).
    If a runnable is mapped to a BSW entity, this mapping is shown too.

    What is the purpose of the diagram?
    With the help of the diagram, it is possible to better understand the context in which each runnable can run.

    Disclaimer: This script for generating the diagram is only an example and does not claim to be complete or correct. It is only
    a support to better understand the internal data model of the generator and the decisions made during the code generation. 
"""


from rtegraph import graph_generator
from rtegraph.constants import *
from collections import OrderedDict
TASK_PROPERTIES = """{{name}}
priority: {{priority}}
Configured Priority: {{configuredPriority}}"""
SCHM_TASK_PROPERTIES = """{{name}}
Configured Priority: {{configuredPriority}}"""


def get_or_create_runnable_and_callers(graph_generator, cluster, runnable, executable_to_task_mappings, task_map, already_mapped=False):
    runnable_node = graph_generator.get_node(cluster, runnable)
    if runnable_node is not None:
        return runnable_node  # runnable and it's callers/tasks already exists
    else:
        runnable_node = graph_generator.get_or_create_node(
            cluster, runnable, "{{name}}\nsymbol: {{entryPoint}}", style=RUNNABLE_STYLE)
    found_context = False
    if not already_mapped:
        mapped_executable = graph_generator.find_and_resolve_reference(
            runnable, "mappedExecutableInstanceRef")
        if mapped_executable is not None:
            found_context = True
            mapped_executable_node = get_or_create_runnable_and_callers(
                graph_generator, cluster, mapped_executable, executable_to_task_mappings, task_map, True)
            graph_generator.connect(
                mapped_executable_node, runnable_node, cluster, label="SwcBswMapping")
    task_event_mappings = executable_to_task_mappings.get(runnable, [])

    for mapping in task_event_mappings:
        taskname = mapping.findtext("taskName")
        task = task_map.get(taskname)
        if task is not None:
            found_context = True
            task_node = graph_generator.get_or_create_node(cluster, task, SCHM_TASK_PROPERTIES if task.findtext(
                'schMTask') == 'true' else TASK_PROPERTIES, style=TASK_STYLE)
            graph_generator.connect(
                task_node, runnable_node, cluster, label=mapping.findtext("eventName"))
    called_runnables = graph_generator.find_and_resolve_references(
        runnable, "directCallers/directCallerRef")
    for called_runnable in called_runnables:
        found_context = True
        called_runnable_node = get_or_create_runnable_and_callers(
            graph_generator, cluster, called_runnable, executable_to_task_mappings, task_map)
        graph_generator.connect(
            called_runnable_node, runnable_node, cluster, label="(direct call)")
    if not found_context:
        task_node = graph_generator.get_or_create_node_with_customized_id(
            'unknownTask' + cluster.id, cluster, text="Unkown Task", style=UNKNOWN_TASK_STYLE)
        graph_generator.connect(task_node, runnable_node, cluster)
    return runnable_node


def create_executable_to_task_mappings(graph_generator):
    root = graph_generator.get_model_root()
    executable_to_task_mappings = OrderedDict()
    for event_mapping in root.findall("events/*/taskEventMappings/*"):
        executable_to_task_mappings.setdefault(graph_generator.find_and_resolve_reference(
            event_mapping, "executableRef"), []).append(event_mapping)
    for event_mapping in root.findall("events/modeSwitchEventGroupInstance/*/*/modeSwitchEventInstances/*/taskEventMappings/*"):
        executable_to_task_mappings.setdefault(graph_generator.find_and_resolve_reference(
            event_mapping, "executableRef"), []).append(event_mapping)
    return executable_to_task_mappings


def create_task_map(root):
    task_map = OrderedDict()
    for task in root.findall("partitions/partition/tasks/task") + root.findall("partitions/partition/Interrupts/Interrupt"):
        task_map[task.findtext("name")] = task
    return task_map


def create_graph(graph_generator):
    graph_generator.set_title("Runnable Context")
    root = graph_generator.get_model_root()

    runnables = root.findall("partitions/*/softwareComponents/*/runnables/*")
    if not runnables:
        return False

    executable_to_task_mappings = create_executable_to_task_mappings(graph_generator)
    task_map = create_task_map(root)

    for runnable in runnables:
        entry_point = runnable.findtext("entryPoint")
        name = runnable.findtext("name")
        cluster = graph_generator.get_or_create_cluster(entry_point, entry_point)
        get_or_create_runnable_and_callers(
            graph_generator, cluster, runnable, executable_to_task_mappings, task_map)
