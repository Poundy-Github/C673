indexOfJob = 0

pipeline{
    agent {
      label 'SHKL102W'
    }
    
    options {
        timeout(time: 3, unit: 'HOURS') 
    }
    stages {
        stage('Build') {
            options {
                timeout(time: 75, unit: 'MINUTES') 
            }
            steps{
                script{
                    indexOfJob = 1
                }
                bat '''
                    D:
                    cd D:/Git_Repository/ChangAn_C673/MFC5J3_C673_Mcu_App/01_AsrConfig/util
                    ./Run_boot
                '''
            }
        }

    }
    post {
        failure {
            script{
              if(indexOfJob == 1) {
              echo "compile failed"
              emailext attachLog: true, body: 'Hello, the job C673 MCU integration failed, please check the build log to see the details.', recipientProviders: [buildUser(), developers()], subject: '[ADAS_China_CI message] The job C673 MCU integration failed', to: 'jinlong.4.zhang@continental-corporation.com'
              }
            }
        }
    }
}
