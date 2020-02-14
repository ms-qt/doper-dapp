import QtQuick 2.7
import QtQuick.Controls 2.0
import QtWebEngine 1.7

 Item  {
     visible: true
     WebEngineView {

        anchors.fill: parent
//        url: "https://lavas-project.github.io/lavas-demo/blog/index.html#/"
        url:"https://qiye.aliyun.com/"
        settings.pluginsEnabled: true
        settings.screenCaptureEnabled: true
        //AllowRunningInsecureContent
        settings.allowRunningInsecureContent: true
        settings.javascriptEnabled: true
        settings.localStorageEnabled: true
        onJavaScriptConsoleMessage: {
            console.log(message)
        }
        onFeaturePermissionRequested: {
            if(feature  == WebEngineView.MediaAudioCapture
                    || feature == WebEngineView.MediaAudioVideoCapture
                    || feature ==  WebEngineView.MediaVideoCapture){
                grantFeaturePermission(securityOrigin,feature,true)
            } else{
                grantFeaturePermission(securityOrigin,feature,false)
            }
        }
     }
 }
