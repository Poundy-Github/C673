import threading
import os
import shutil
import os.path
import sys
# import py7zr

done1 = 0
done2 = 0
done3 = 0
done4 = 0
done5 = 0
done6 = 0


res6 = 0

source_path = os.getcwd()


def bat1():
    global done1, res1
    res1 = os.system(res1)
    done1 = 1


def bat2():
    global done2, res2
    res1 = os.system(res2)
    done2 = 1


def bat3():
    global done3, res3
    res1 = os.system(res3)
    done3 = 1


def bat4():
    global done4, res4
    res1 = os.system(res4)
    done4 = 1


def bat5():
    global done5, res5
    res1 = os.system(res5)
    done5 = 1


def copy_file_fun(sou_path, des_path):
    for root, dirs, files in os.walk(sou_path):
        for f in files:
            fullname = os.path.join(root, f)
            shutil.copy2(fullname, des_path)


def copy_s19file_fun(sou_path, des_path):
    for root, dirs, files in os.walk(sou_path):
        for f in files:
            if f == 'A_Application.s19' or f == 'B_Application.s19' or f == 'FlashDriver.s19':
                # print(1)
                fullname = os.path.join(root, f)
                shutil.copy2(fullname, des_path)


def copy_dirs_fun(sou_path, des_path):
    if os.path.exists(des_path):
        shutil.rmtree(des_path)
    shutil.copytree(sou_path, des_path)


def copy_ab_blank_sourcefile(path):
    # copy output
    output_path = source_path
    os.chdir(output_path)
    output_path = os.path.abspath(os.path.join(os.getcwd(), "../.."))
    output_path = os.path.join(output_path, '05_Output\\bin')
    for root, dirs, files in os.walk(output_path):
        for f in files:
            fullname = os.path.join(root, f)
            shutil.copy2(fullname, path)
    os.chdir(path)
    path = os.path.split(path)
    try:
        if path[1] == 'SourceA':
            os.rename('TRICORE_TC38XQ_01_AsrConfig.mot', 'ApplicationA.mot')
            print('Rename to ApplicationA.mot successful!')
        if path[1] == 'SourceB':
            os.rename('TRICORE_TC38XQ_01_AsrConfig.mot', 'ApplicationB.mot')
            print('Rename to ApplicationB.mot successful!')
    except WindowsError:
        if path[1] == 'SourceA':
            os.remove('ApplicationA.mot')
            os.rename('TRICORE_TC38XQ_01_AsrConfig.mot', 'ApplicationA.mot')
            print('Cover ApplicationA.mot successful!')
        if path[1] == 'SourceB':
            os.remove('ApplicationB.mot')
            os.rename('TRICORE_TC38XQ_01_AsrConfig.mot', 'ApplicationB.mot')
            print('Cover ApplicationB.mot successful !')


def create_dir_in_output():
        current_path = os.getcwd()
        current_path = os.path.abspath(os.path.join(os.getcwd(), "../../"))
        os.chdir(current_path)
        if not os.path.exists('07_Delivery'):
            os.mkdir('07_Delivery')
        current_path = os.path.join(current_path, '07_Delivery')
        os.chdir(current_path)
        #if not os.path.exists('J3'):
            #os.mkdir('J3')
        if not os.path.exists('Mcu'):
            os.mkdir('Mcu')
        current_path = os.path.join(current_path, 'Mcu')
        os.chdir(current_path)
        if not os.path.exists('01_Bootloader/UCB'):
            os.makedirs('01_Bootloader/UCB')
        if not os.path.exists('01_Bootloader/ProgrammingBYTools'):
            os.makedirs('01_Bootloader/ProgrammingBYTools')
        if not os.path.exists('01_Bootloader//OTA'):
            os.makedirs('01_Bootloader//OTA')
        if not os.path.exists('02_ApplicationA&B/SourceA'):
            os.makedirs('02_ApplicationA&B/SourceA')
        if not os.path.exists('02_ApplicationA&B/SourceB'):
            os.makedirs('02_ApplicationA&B/SourceB')
        if not os.path.exists('03_CANoe_Project'):
            os.makedirs('03_CANoe_Project')
        if not os.path.exists('03_CANoe_Project/FBL_UDS_CANoe12_V6.0'):
            os.makedirs('03_CANoe_Project/FBL_UDS_CANoe12_V6.0')
        if not os.path.exists('04_DBC'):
            os.makedirs('04_DBC')
        if not os.path.exists('05_Mtsswc'):
            os.makedirs('05_Mtsswc')
        print('Create dirs successful！')


# execute launch bat file_first
def execute_launch_bat():
    global done5, res5
    path = source_path
    print(path)
    os.chdir(path)
    source_dir = os.path.join(path, 'RemakeAll.bat')
    res5 = os.system('RemakeAll.bat')
    done5 = 1


# execute launch bat file_first
def execute_launch_bat_second():
    global done5, res5
    path = source_path
    print(path)
    os.chdir(path)
    source_dir = os.path.join(path, 'RemakeAll_noclean.bat')
    res5 = os.system('RemakeAll_noclean.bat')
    

def source_a_operation():
    path = source_path
    path = os.path.abspath(os.path.join(os.getcwd(), "../.."))
    path1 = path
    path = os.path.join(path, '07_Delivery\\Mcu\\02_ApplicationA&B\\SourceA')
    copy_ab_blank_sourcefile(path)
    print('Copy A Blank successful!')
    #path1 = os.path.join(path1, '07_Delivery\\GenerateData3.3\\input')
    path1 = os.path.join(path1, '06_Tools\\01_SignatureTool\\S19_Format_Tool\\BootloaderV6.0\\GenerateData3.3\\input')
    shutil.copy2('ApplicationA.mot', path1)
    print('Copy ApplicationA.mot to GenerateData3.3/input successful!')


def a_blank_operation_one():
    # 更改board-tasking.ldscript 为A面 开始
    count = 0
    path = source_path
    os.chdir(path)
    path = os.path.abspath(os.path.join(os.getcwd(), "../.."))
    path = os.path.join(path, '04_Script\\03_Link')
    os.chdir(path)
    with open('board-tasking.ldscript', 'r', encoding="utf-8") as f1, open('board-tasking.ldscript.bak', 'w', encoding="utf-8") as f2:
        for (num, value) in enumerate(f1):
            if num == 20:
                value = value.replace('#define TSK_COMPILE_CODE_IN_BLOCK			TSK_COMPILE_CODE_IN_BLOCK_B', '#define TSK_COMPILE_CODE_IN_BLOCK			TSK_COMPILE_CODE_IN_BLOCK_A')
            f2.write(value)
    os.remove('board-tasking.ldscript')
    os.rename('board-tasking.ldscript.bak', 'board-tasking.ldscript')
    print('Modify board-tasking.ldscript to A blank successful!')
    # 更改board-tasking.ldscript 为A面 结束


def b_blank_operation_one():
    # 更改board-tasking.ldscript 为B面 开始
    count = 0
    path = source_path
    os.chdir(path)
    path = os.path.abspath(os.path.join(os.getcwd(), "../.."))
    path = os.path.join(path, '04_Script\\03_Link')
    os.chdir(path)
    with open('board-tasking.ldscript', 'r', encoding="utf-8") as f1, open('board-tasking.ldscript.bak', 'w', encoding="utf-8") as f2:
        for (num, value) in enumerate(f1):
            if num == 20:
                value = value.replace('#define TSK_COMPILE_CODE_IN_BLOCK			TSK_COMPILE_CODE_IN_BLOCK_A', '#define TSK_COMPILE_CODE_IN_BLOCK			TSK_COMPILE_CODE_IN_BLOCK_B')
            f2.write(value)
    os.remove('board-tasking.ldscript')
    os.rename('board-tasking.ldscript.bak', 'board-tasking.ldscript')
    print('Modify board-tasking.ldscript to B blank successful!')
    # 更改board-tasking.ldscript 为B面 结束


def b_blank_operation_two():
    # 删除generate下TRICORE-tasking.ldscript  开始
    path = os.getcwd()
    path = os.path.abspath(os.path.join(os.getcwd(), "../.."))
    path = os.path.join(path, '01_AsrConfig\\output\\generated')
    os.chdir(path)
    for root, dirs, files in os.walk(path):
        for f in files:
            if f == 'TRICORE-tasking.ldscript':
                fullname = os.path.join(root, f)
                os.remove(fullname)
    print('Deleted TRICORE-tasking.ldscript successful! ')
    # 删除bin下文件及generate下TRICORE-tasking.ldscript  结束


def b_blank_operation_three():
    # 删除bin下所有文件 开始
    path = os.getcwd()
    path = os.path.abspath(os.path.join(os.getcwd(), "../../.."))
    path = os.path.join(path, '05_Output')
    os.chdir(path)
    for root, dirs, files in os.walk(path):
        for f in files:
            fullname = os.path.join(root, f)
            os.remove(fullname)
    print('Deleted output files successful！')
    # 删除bin下所有文件 结束


def source_b_operation():
    bpath = source_path
    os.chdir(bpath)
    bpath = os.path.abspath(os.path.join(os.getcwd(), "../.."))
    path1 = bpath
    bpath = os.path.join(path1, '07_Delivery\\Mcu\\02_ApplicationA&B\\SourceB')
    copy_ab_blank_sourcefile(bpath)
    print('Copy B Blank successful!')
    path1 = os.path.join(path1, '06_Tools\\01_SignatureTool\\S19_Format_Tool\\BootloaderV6.0\\GenerateData3.3\\input')
    shutil.copy2('ApplicationB.mot', path1)
    print('Copy ApplicationB.mot to GenerateData3.3/input successful!')


def run_five_bat():
    print("Start Run GenerateData3.3 bat script!!!")
    path = source_path
    os.chdir(path)
    path = os.path.abspath(os.path.join(os.getcwd(), "../.."))
    path = os.path.join(path, '06_Tools\\01_SignatureTool\\S19_Format_Tool\\BootloaderV6.0\\GenerateData3.3')
    os.chdir(path)
    print(path)
    path_cur = path
    path = path_cur + '\\GenerateApplication.bat'
    path1 = path_cur + '\\GenerateBoot.bat'
    path2 = path_cur + '\\GenerateBootLoaderUpdater.bat'
    path3 = path_cur + '\\GenerateFlashBootLoader.bat'
    path4 = path_cur + '\\Merge.bat'
    res = os.system(path)
    res1 = os.system(path1)
    res2 = os.system(path2)
    res3 = os.system(path3)
    res4 = os.system(path4)
    print(res)
    print(res1)
    print(res2)
    print(res3)
    print(res4)
    print('Run five bats successful!')


def copy_tools19_to_programmingbbytools():
    print("Start Copy files from GenerateData3.3\output\TOOL to Mcu\\01_Bootloader\ProgrammingBYTools !!!")
    path = source_path
    os.chdir(path)
    path = os.path.abspath(os.path.join(os.getcwd(), "../.."))
    path1 = path
    path = os.path.join(path, '06_Tools\\01_SignatureTool\\S19_Format_Tool\\BootloaderV6.0\\GenerateData3.3\\output\\TOOL')
    path1 = os.path.join(path1, '07_Delivery\\Mcu\\01_Bootloader\\ProgrammingBYTools')
    copy_file_fun(path, path1)
    print('Copy files from GenerateData3.3\output\TOOL to Mcu\\01_Bootloader\ProgrammingBYTools successful!')


def copy_otas19_to_outota():
    print("Start Copy files from GenerateData3.3\output\OTA to \Mcu\01_Bootloader\OTA !!!")
    path = source_path
    os.chdir(path)
    path = os.path.abspath(os.path.join(os.getcwd(), "../.."))
    path1 = path
    path = os.path.join(path, '06_Tools\\01_SignatureTool\\S19_Format_Tool\\BootloaderV6.0\\GenerateData3.3\\output\\OTA')
    path1 = os.path.join(path1, '07_Delivery\\Mcu\\01_Bootloader\\OTA')
    copy_s19file_fun(path, path1)

    print('Copy files from GenerateData3.3\output\ota to Mcu\\01_Bootloader\ota successful!')


def copy_otas19_to_canoe_data():
    print('Start copy files from GenerateData3.3\output\OTA to FBL_UDS_CANoe12_V6.0\data')
    path = source_path
    os.chdir(path)
    path = os.path.abspath(os.path.join(os.getcwd(), "../.."))
    path1 = path
    path = os.path.join(path, '06_Tools\\01_SignatureTool\\S19_Format_Tool\\BootloaderV6.0\\GenerateData3.3\\output\OTA')
    path1 = os.path.join(path1, '06_Tools\\02_CANoe_FlashingTools\\S19_Format_Tool\\BootloaderV6_0\\FBL_UDS_CANoe12_V6.0\\data')
    copy_file_fun(path, path1)
    os.chdir(path1)
    os.remove('A_Application.s19')
    os.remove('B_Application.s19')
    os.remove('FlashBootLoader.s19')
    print('Copy files from GenerateData3.3\output\OTA to FBL_UDS_CANoe12_V6.0\data successful!')



def copy_canoedate_to_outcanoe():
    path = source_path
    os.chdir(path)
    path = os.path.abspath(os.path.join(os.getcwd(), "../.."))
    path1 = path
    path = os.path.join(path, '06_Tools\\02_CANoe_FlashingTools\\S19_Format_Tool\\BootloaderV6_0\\FBL_UDS_CANoe12_V6.0')
    path1 = os.path.join(path1, '07_Delivery\\Mcu\\03_CANoe_Project\\FBL_UDS_CANoe12_V6.0')
    copy_dirs_fun(path, path1)
    print('Copy files from 07_Output\FBL_UDS_CANoe12_V6.0 to \Mcu\03_CANoe_Project\FBL_UDS_CANoe12_V6.0 successful!')
    


def zip_sourcea_sourceb():
    path = source_path
    os.chdir(path)
    path = os.path.abspath(os.path.join(os.getcwd(), "../.."))
    path = os.path.join(path, '07_Delivery\\Mcu\\02_ApplicationA&B')
    print(path)
    os.chdir(path)
    shutil.make_archive('ApplicationA&B_C673', format='zip', root_dir=path)
    # with py7zr.SevenZipFile('202.7z', 'w') as z:
    #     z.writeall('./basedir')

def zip_FBL_UDS_FLashPackage():
    path = source_path
    os.chdir(path)
    path = os.path.abspath(os.path.join(os.getcwd(), "../.."))
    path = os.path.join(path, '07_Delivery\\Mcu\\03_CANoe_Project\\FBL_UDS_CANoe12_V6.0')
    print(path)
    #os.chdir(path)
    shutil.make_archive('FBL_UDS_CANoe12_V6.0', format='zip', root_dir=path)



def copy_sdlswc_to_mtsswc():
    print('Start Copy files from 05_Output\\output\\pdo to 07_Delivery\\Mcu\\05_Mtsswc !!!')
    path = source_path
    os.chdir(path)
    path = os.path.abspath(os.path.join(os.getcwd(), "../.."))
    path1 = path
    path = os.path.join(path, '05_Output\\pdo')
    path1 = os.path.join(path1, '07_Delivery\\Mcu\\05_Mtsswc')
    copy_file_fun(path, path1)
    os.chdir(path1)
    if os.path.exists('FCTVDY.pdo'):
       os.remove('FCTVDY.pdo')
    if os.path.exists('pdoscan.log'):
       os.remove('pdoscan.log')
    if os.path.exists('pdotool.log'):
       os.remove('pdotool.log')
    print('Copy files from 05_Output\\output\\pdo to 07_Delivery\\Mcu\\05_Mtsswc successful!')


def generate_input():
    path = os.getcwd()
    print(path)


# main function entrance
def main():

    # if done1 == 1 and done2 == 1 and done3 == 1 and done4 == 1 and done5 == 1:
    #     print("Process successful")
    # else:
    #     print("Process failed")

    #
    # #   执行编译B面操作_1 操作 开始
    b_blank_operation_one()
    # #   执行编译B面操作_1 操作 结束
    #
    # #   执行编译B面操作_2 操作 开始
    b_blank_operation_two()
    # #   执行编译B面操作_2 操作 结束
    #
    # #   执行编译B面操作_3 操作 开始
    b_blank_operation_three()
    # #   执行编译B面操作_3 操作 结束


    # 执行launch.bat 操作 开始
    try:
        execute_launch_bat()
    except:
        print('compile success!')
    #   执行launch.bat 操作 结束


    #
    # 在07_Output目录下创建J3 Mcu及Mcu内部文件目录 操作 开始
    create_dir_in_output()
    # 在07_Output目录下创建J3 Mcu及Mcu内部文件目录 操作 结束

    #
    # 拷贝B面的bin文件到sourceB并将对应的mot文件拷贝到GenerateData3.3/input 操作 开始
    source_b_operation()
    # 拷贝B面的bin文件到sourceB 操作 结束


    #
    # #   执行编译A面操作_1 操作 开始
    a_blank_operation_one()
    # #   执行编译A面操作_1 操作 结束
    #
    # #   执行编译A面操作_2 操作 开始
    b_blank_operation_two()
    # #   执行编译A面操作_2 操作 结束
    #
    # #   执行编译A面操作_3 操作 开始
    b_blank_operation_three()
    # #   执行编译A面操作_3 操作 结束

    #
    #   执行launch.bat 操作 开始
    try:
        execute_launch_bat_second()
    except:
        print('compile success!')
    #   执行launch.bat 操作 结束

    #
    # 拷贝A面的bin文件到sourceA并将对应的mot文件拷贝到GenerateData3.3/input 操作 开始
    source_a_operation()
    # 拷贝A面的bin文件到sourceA 操作 结束

    #
    # 执行五个脚本 操作 开始
    run_five_bat()
    # 执行五个脚本 操作 开始

    #
    # 拷贝GenerateData3.3\output 目录下TOOL文件至01_Bootloader\ProgrammingBYTools 操作 开始
    copy_tools19_to_programmingbbytools()
    # 拷贝GenerateData3.3\output 目录下TOOL文件至01_Bootloader\ProgrammingBYTools 操作 结束

    #
    # 拷贝GenerateData3.3\output 目录下OTA文件至01_Bootloader\OTA 操作 开始
    copy_otas19_to_outota()
    # 拷贝GenerateData3.3\output 目录下OTA文件至01_Bootloader\OTA 操作 操作 结束

    #
    # 拷贝GenerateData3.3\output 目录下OTA文件至 07_Output\FBL_UDS_CANoe12_V6.0\data操作 开始
    copy_otas19_to_canoe_data()
    #  拷贝GenerateData3.3\output 目录下OTA文件至 07_Output\FBL_UDS_CANoe12_V6.0\data操作 结束

    #
    # 拷贝FBL_UDS_CANoe12_V6.0 目录下文件至Mcu\03_CANoe_Project\FBL_UDS_CANoe12_V6.0 操作 开始
    copy_canoedate_to_outcanoe()
    # 拷贝FBL_UDS_CANoe12_V6.0 目录下文件至Mcu\03_CANoe_Project\FBL_UDS_CANoe12_V6.0 操作 结束

    #
    # 压缩 02_ApplicationA&B下文件 操作 开始
    zip_sourcea_sourceb()
    # 压缩 02_ApplicationA&B下文件 操作 结束

    #
    # 拷贝01_AsrConfig\output\pdo 目录下sdl swc文件至07_Output\Mcu\05_Mtsswc操作 开始
    copy_sdlswc_to_mtsswc()
    # 拷贝01_AsrConfig\output\pdo 目录下sdl swc文件至07_Output\Mcu\05_Mtsswc操作 结束

if __name__ == '__main__':
    main()
