from xmlModels import XmlDoc as Xmlplaylist
import os, sys

print("Python version: {version} \n".format(version=sys.version))

def main():
  # Get playlist path from argument list
  try:
    playlistPath = sys.argv[1]
  except:
    print("Playlist name was not delivered as argument to script {scriptName}".format(scriptName=str(sys.argv[0])))
    sys.exit(0)
  
  # Define path to recordings depending whether it is called as a jenkins job or locally
  try: 
    os.environ['SANDBOX']
    recordingsPath = os.environ['JENKINS_HOME'] + "\\workspace\\" + os.environ['JOB_NAME']
  except:
    recordingsPath = "\\\\uud4b04w\\CriticalScenes\\SILTest"
    
  # Summarize all rec files in a list
  recordingsList = [recording for recording in os.listdir(recordingsPath) if recording.endswith("rec")]
  
  # Create empty playlist file
  playlist = Xmlplaylist(playlistPath)
  
  # Fill playlist ...
  for rec in recordingsList:
    playlist.addBatchEntry(os.path.join(recordingsPath, rec))
  playlist.writeXML()

if __name__ == "__main__":
	main()