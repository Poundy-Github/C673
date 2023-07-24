========================
= Wrongly_Configured_Subprojects README =
========================

Author:     Alexandru Corbu, uidg5120, alexandru.corbu@continental-corporation.com
Maintainer: Engineering Tools, to contact us please follow the link: https://cws1.conti.de/content/00005672/ADAS%20Processes%20%20Tools/How%20To%20Contact%20Tool%20Support.aspx

Installation:
=============
    Copy the content somewhere on your local PC
   
    In IMS Integrity client, go to: ViewSet->Customize..., on the left
    side of the popping up window, choose "Custom", on the right
    side, find an empty entry and fill in the form like this:

       Name:        Wrongly Configured Subprojects
       Program:     Browse where you saved the application and select the .exe
       Parameters:  
       Description: Export in a .CSV file the wrongly configured subprojects
       Icon File:   Browse where you stored the application and select icon.png

    Don't forget to set that button as "Visible, On Toolbar" in the 3rd
    column, in order to actually see it.

    
Description:
    - Return in a CSV file the wrongly configured subprojects, so you can use it
	 before a checkpoint is created or a development path, or a restore is done
	 to see which subprojects need reconfiguration;
	- It runs recursively from the selected subproject.

Dependencies:
    - Integrity 10, Build 10.6.0.7337 with 15 hotfixes installed (at least this is
	the version this was tested with)


Tipps and Tricks:
    - A common problem is this one: it takes a while to run depending on the number
	 of subprojects which needs to be read.
	 


Trouble shooting:
=================
    - After you start it, a cmd will appear. Just like it says there you need to wait
	until it's closed. If you run it from the project level, it will take about 1 hour,
	1 hour and a half. If it will take more than 1 hour and a half, close the cmd and
	run again this custom action.

Version history:
================
02.04.2016 -  0.1 : The first version in Python.
17.04.2016 -  0.2 : Some reliability and stability improvement
20.04.2016 -  0.3 : You can run it now from a subproject level or project level

