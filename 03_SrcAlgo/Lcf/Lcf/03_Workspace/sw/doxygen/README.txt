Content:

- create_documentation.bat				script used to create the documentation
- open_documentation.bat				script used to open the documentation
- process.doxy						process-specific doxygen configuration file
- SoC.doxy						SoC-specific doxygen configuration file
- FF.doxy, IA.doxy, IC.doxy, IPC.doxy, SPI.doxy		component-specific doxygen configuration file
- README.txt						this file


How to create the documentation:

- make sure the code follows the Doxygen and/or PlantUML template
- the tools are automatically installed during project build in C:\Tool\doxygen
- run create_documentation.bat p <project> <component>
- the <project> param can be mfc431, ars441 etc.
- the <component> param can be SoC to create the documentation for the entire project
  or a component name (e.g. FF, IA etc.) for a component-specific documentation
- the file <component>.doxy must exist. if it doesn't, you have to create one
- don't modify process.doxy
- the documentation is created under DPU\04_Engineering\04_Build\doc\<project>\<component>


How to open the documentation:

- run open_documentation.bat p <project> <component>
- <project> and <component> parameters have the same meaning as in documentation creation
- if the documentation has not been yet created (e.g. automatically during project build using the parameter doxygen)
  the documentation is now created
- the .chm file is open