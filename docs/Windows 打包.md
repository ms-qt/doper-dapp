# Windows 打包

## 类型

### 1个exe

#### 工具下载地址

https://enigmaprotector.com/en/downloads.html

#### 使用命令

	windeployqt app.exe
	
#### 拷贝QML文件夹

> 将QML拷贝到生产程序的目录



### 安装包

#### 工具下载

http://www.jrsoftware.org/


#### 



    ; 脚本由 Inno Setup 脚本向导 生成！
    ; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
    
    #define MyAppName "北斗数睿运营管理平台"
    #define MyAppVersion "1.0.0"
    #define MyAppPublisher "北斗数睿"
    #define MyAppURL "http://www.bdlbsc.com/"
    #define MyAppExeName "app.exe"
    
    [Setup]
    ; 注: AppId的值为单独标识该应用程序。
    ; 不要为其他安装程序使用相同的AppId值。
    ; (若要生成新的 GUID，可在菜单中点击 "工具|生成 GUID"。)
    AppId={{007954CD-E1E1-4258-BD05-F6E41D7B5774}
    AppName={#MyAppName}
    AppVersion={#MyAppVersion}
    ;AppVerName={#MyAppName} {#MyAppVersion}
    AppPublisher={#MyAppPublisher}
    AppPublisherURL={#MyAppURL}
    AppSupportURL={#MyAppURL}
    AppUpdatesURL={#MyAppURL}
    DefaultDirName={autopf}\{#MyAppName}
    DisableProgramGroupPage=yes
    ; [Icons] 的“quicklaunchicon”条目使用 {userappdata}，而其 [Tasks] 条目具有适合 IsAdminInstallMode 的检查。
    UsedUserAreasWarning=no
    ; 以下行取消注释，以在非管理安装模式下运行（仅为当前用户安装）。
    ;PrivilegesRequired=lowest
    PrivilegesRequiredOverridesAllowed=dialog
    OutputDir=C:\Users\maohuawei\Downloads\安装包
    OutputBaseFilename=setup
    SetupIconFile=D:\project\app\qt\aliyuncode\doper-dapp\app\images\favicon.ico
    Compression=lzma
    SolidCompression=yes
    WizardStyle=modern
    
    [Languages]
    Name: "chinesesimp"; MessagesFile: "compiler:Default.isl"
    
    [Tasks]
    Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
    Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 6.1; Check: not IsAdminInstallMode
    
    [Files]
    Source: "C:\Users\maohuawei\CMakeBuilds\a7b8c1ce-bcca-4aff-adb3-f88d34b4a652\build\x64-Release\app\Release\app.exe"; DestDir: "{app}"; Flags: ignoreversion
    Source: "C:\Users\maohuawei\CMakeBuilds\310da04e-f5b7-4383-89ea-fe0661f94517\build\x64-Release\app\Release\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
    ; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”
    
    [Icons]
    Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
    Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
    Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon
    
    [Run]
    Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent
    


