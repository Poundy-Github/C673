"""
.../stk/cmd/hpc_task_info.py
stk.cmd.hpc_task_info
---------------------

    this is a standalone script for a search of failed tasks of a job on HPC cluster.

    - by default, it uses HPC cluster head node LISS006, but can be adjusted via -n option,
    - please specify option -j followed by an ID of a job or the name of job to be queried for,
    - option -f is used as a regex search pattern trying to find 'Failed' tasks (default),

    just pipe the stdout to any file of wish to be able to process results further, e.g.
    python hpc_task_info.py -j 2222 > hpc_2222.txt


:org:           Continental AG
:author:        Sven Mertens

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:32CET $
"""

# Python Modules ======================================================================================================
from win32com.client.gencache import EnsureModule
from win32com.client import Dispatch
from pythoncom import com_error  # pylint: disable=E0611
from argparse import ArgumentParser
# from optparse import OptionParser
from re import search as research
from os import environ

#= DEFINES ============================================================================================================
JOBSTATE = {1: 'Configuring', 2: 'Submitted', 4: 'Validating', 8: 'ExternalValidation', 16: 'Queued', 32: 'Running',
            64: 'Finishing', 128: 'Finished', 256: 'Failed', 512: 'Canceled', 1024: 'Canceling', 2047: 'All'}

TASKSTATE = {1: 'Configuring', 2: 'Submitted', 4: 'Validating', 8: 'Queued', 16: 'Dispatching', 32: 'Running',
             64: 'Finishing', 128: 'Finished', 256: 'Failed', 512: 'Canceled', 1024: 'Canceling', 2047: 'All'}

#= MAIN ===============================================================================================================


if __name__ == '__main__':
    opts = ArgumentParser(description="proggy retrieves information about HPC job details")
    opts.add_argument("-n", "--headnode", dest="hpc", default='LISS006.CW01.CONTIWAN.COM',
                      help="head node of HPC environment, [default='LISS006.CW01.CONTIWAN.COM']")
    opts.add_argument("-j", "--job", dest="job", default=None,
                      help="job to query for [default=None]")
    opts.add_argument("-f", "--filter", dest="filter", default='Failed',
                      help="RegEx filter for state search of tasks. [default='Failed']")
    opts.add_argument("-m", "--mine", action="store_true", default=False,
                      help="restrict display or search for only my own created jobs.")
    opts.add_argument("-v", action="count", dest="verbosity", default=0,
                      help="increase output verbosity")
    args = opts.parse_args()

    # force makepy for the needed com modules to have early binding available
    EnsureModule('{C45D10A1-54E8-420B-A052-719D47EC7C16}', 0, 2, 0)
    EnsureModule('{7212BCD2-6B84-415C-A12F-B49A77DEE393}', 0, 2, 0)

    # conncet to our server
    sched = Dispatch("Microsoft.Hpc.Scheduler.Scheduler")
    sched.Connect(args.hpc)

    if args.job is None:  # print it out for the user
        i = environ["username"]
        print("please specify a job name or it's ID to get more info! [-j <job>]\n")
        jobs = [(j.Name, j.Id) for j in sched.GetJobList(None, None)
                if not args.mine or args.mine and i in j.Owner]  # retrieve job details
        lens = (max(12, len(max(jobs, key=lambda x: len(x[0]))[0])),  # calc length of strings
                max(8, len(str(max(jobs, key=lambda x: x[1])[1]))))
        tmpl = (" %%%ds | %%%ds" % (lens[0], lens[1]))  # create a print template
        print(tmpl % ("job name", "job id"))
        print("=" * (lens[0] + 2) + "|" + "=" * (lens[1] + 2))  # print head underline
        for j in jobs:  # print the job names and id's
            print(tmpl % j)

        sched.Close()
        exit(0)

    jobIdent = int(args.job) if type(args.job) == str and args.job.isdigit() else args.job  # int?
    for job in sched.GetJobList(None, None):  # iterate through jobs
        if jobIdent in (str(job.Name), job.Id):  # try to find it by name or id
            if args.verbosity > 0:
                print("(%d) %s: %s" % (job.Id, job.Name, JOBSTATE[job.State]))
            try:
                for task in job.GetTaskList(None, None, False):  # iterate through tasks
                    tstate = TASKSTATE[task.State]
                    if research(args.filter, tstate) is not None:  # found and print
                        if args.verbosity > 0:  # print in readable format
                            print("(%d) %s: %s" % (task.Name, task.TaskId.JobTaskId, tstate))
                        else:  # well, just the name of task
                            print(task.Name)
            except com_error as ce:
                print("Exception: %s" % ce.args[2][2])
            except Exception as ex:
                print("Exception: %s" % str(ex))
            break
    sched.Close()

"""
CHANGE LOG:
-----------
$Log: hpc_task_info.py  $
Revision 1.1 2021/12/13 17:55:32CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/cmd/project.pj
Revision 1.1 2013/11/13 16:10:32CET Mertens, Sven (uidv7805) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/cmd/project.pj
"""
