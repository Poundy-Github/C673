#!/bin/sh

TRESOS_BIN=$(dirname "$0")

# following steps are needed to get the absolute path, independent if the script is called with absolute or relative path
cd $TRESOS_BIN/.. > /dev/null
TRESOS_BASE="$(pwd)" 
cd - > /dev/null

chmod +x $TRESOS_BASE/jre_x86_64/linux/bin/java

#JAVA setting
JAVACMD=java
JAVA_HOME=$TRESOS_BASE/jre_x86_64/linux
JAVA=$JAVA_HOME/bin/$JAVACMD

#PATH setting
SAVED_PATH=$PATH

#Command Line setting
CLASSPATH=$TRESOS_BASE/plugins/org.eclipse.equinox.launcher_1.3.201.v20161025-1711.jar

APPLICATION=dreisoft.tresos.application.launcher2.plugin.ApplicationTresosCmd
VMARGS="-Xmx4096m -Xms256M -server -XX:+UseG1GC -XX:+UseStringDeduplication -Dfile.encoding=UTF-8 -Dbase.path="$TRESOS_BASE" $STUDIO_VMARGS_USER" 
ARGS="-nl en -install "$TRESOS_BASE"/"
LAUNCHER=org.eclipse.equinox.launcher.Main
CMD=""$JAVA" $VMARGS -classpath $CLASSPATH $LAUNCHER -application $APPLICATION $ARGS $@ " 
$CMD


