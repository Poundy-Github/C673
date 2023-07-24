from mks_config_tools import mks_obj

def main():

    Host = 'ims-adas'
    Port = '7001'
    CpId = '577073:1'

    devpath_list = [""] #If shares to be added to the normal of the target project use devpath_list = [""]
    #devpath_list = ['ARS441DP10','ARS441DP10_v5']


    base_target_dict = {
                        '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FRS_FreeSpace/05_Testing/06_Test_Tools/mts_measurement/cfg/algo/frs/project.pj' \
                        :'/nfs/projekte1/PROJECTS/SRR510/06_Algorithm/05_Testing/06_Test_Tools/mts_measurement/cfg/algo/frs/project.pj', \
        }

    '''
    base_target_dict = {
                        '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FRS_FreeSpace/04_Engineering/01_Source_Code/algo/gfrs/project.pj'\
                        :'/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/01_Source_Code/algo/gfrs/project.pj', \
                        '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FRS_FreeSpace/04_Engineering/03_Workspace/algo/gfrs_sim/project.pj' \
                        :'/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/gfrs_sim/project.pj', \
                        '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FRS_FreeSpace/04_Engineering/05_Deliverables/cfg/algo/gfrs/project.pj' \
                        :'/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/05_Testing/06_Test_Tools/mts_measurement/cfg/algo/gfrs/project.pj', \
                        '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FRS_FreeSpace/04_Engineering/05_Deliverables/dll/algo/gfrs_sim/project.pj' \
                        : '/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/04_Build/algo/gfrs_sim/project.pj', \
                        \
                        '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/RD_RoadDetection/04_Engineering/01_Source_Code/algo/rd/project.pj' \
                        :'/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/01_Source_Code/algo/rd/project.pj', \
                        '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/RD_RoadDetection/04_Engineering/03_Workspace/algo/rd_sim/project.pj' \
                        :'/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/rd_sim/project.pj', \
                        '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/RD_RoadDetection/04_Engineering/05_Deliverables/cfg/algo/rd/project.pj' \
                        :'/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/05_Testing/06_Test_Tools/mts_measurement/cfg/algo/rd/project.pj', \
                        '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/RD_RoadDetection/04_Engineering/05_Deliverables/dll/algo/rd_sim/project.pj' \
                        :'/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/04_Build/algo/rd_sim/project.pj', \
                        \
                        '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/GP_GridProcessing/04_Engineering/01_Source_Code/algo/gp/project.pj' \
                        :'/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/01_Source_Code/algo/gp/project.pj', \
                        '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/GP_GridProcessing/04_Engineering/03_Workspace/algo/gp_sim/project.pj' \
                        :'/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/gp_sim/project.pj', \
                        '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/GP_GridProcessing/04_Engineering/05_Deliverables/cfg/algo/gp/project.pj' \
                        :'/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/05_Testing/06_Test_Tools/mts_measurement/cfg/algo/gp/project.pj', \
                        '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/GP_GridProcessing/04_Engineering/05_Deliverables/dll/algo/gp_sim/project.pj' \
                        :'/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/04_Build/algo/gp_sim/project.pj', \
        }
    '''

    mks_object = mks_obj()

    mks_object.SetHost(Host)
    mks_object.SetPort(Port)
    mks_object.SetCpId(CpId)

    ###################### Validate the changepackage #####################
    error = mks_object.IsChangePackageValid(CpId, Host, Port)
    if error == 1:
        return error

    for dp in devpath_list:
        print '\n','current dp: ',dp
        for basepath in base_target_dict:
            print 'basepath: ', basepath, '\n'
            targetpath = base_target_dict[basepath]
            print 'targetpath: ', targetpath, '\n'

            temp = targetpath[:targetpath.rfind('/',0,targetpath.rfind('/'))]
            temp = temp + '/project.pj'
            if dp == "":
                devp = None
                if mks_object.GetProjectView(temp, None, devp) == None:
                    print 'Target path ' + temp+ ' does not exist'
            else:
                devp = dp
                if mks_object.GetProjectView(temp, None, devp) == None:
                    print 'Target path '+temp+' does not exist on the development path: '+devp

            print mks_object.AddSharedSubProject(basepath, targetpath, DevPath=dp, SubprojectDevelopmentPath=None, SubprojectRevision='1.1', TypeOfShare="build")

    return error
if __name__ == '__main__':
    main()
