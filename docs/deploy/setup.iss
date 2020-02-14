; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！

#define MyAppName "BDLBSC Operation Management Platform"
#define MyAppVersion "1.0.0.0"
#define MyAppPublisher "maohuawei"
#define MyAppURL "http://www.bdlbsc.com/"
#define MyAppExeName "app.exe"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (若要生成新的 GUID，可在菜单中点击 "工具|生成 GUID"。)
AppId={{5BCCA994-B172-4FF3-A0F0-E5B8DF756028}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={autopf}\{#MyAppName}
DisableProgramGroupPage=yes
LicenseFile=D:\project\app\qt\aliyuncode\doper-dapp\deploy\许可证.txt
InfoBeforeFile=D:\project\app\qt\aliyuncode\doper-dapp\deploy\用户协议.txt
InfoAfterFile=D:\project\app\qt\aliyuncode\doper-dapp\deploy\欢迎使用.txt
; 以下行取消注释，以在非管理安装模式下运行（仅为当前用户安装）。
;PrivilegesRequired=lowest
PrivilegesRequiredOverridesAllowed=commandline
OutputDir=C:\Users\maohuawei\Desktop
OutputBaseFilename=setup
SetupIconFile=D:\project\app\qt\aliyuncode\doper-dapp\deploy\icon.ico
Compression=lzma
SolidCompression=yes
WizardStyle=modern

[Languages]
Name: "chinesesimp"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\Users\maohuawei\CMakeBuilds\a7b8c1ce-bcca-4aff-adb3-f88d34b4a652\build\x64-Release\app\Release\app.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\maohuawei\CMakeBuilds\a7b8c1ce-bcca-4aff-adb3-f88d34b4a652\build\x64-Release\app\Release\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

