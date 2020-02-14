; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���

#define MyAppName "BDLBSC Operation Management Platform"
#define MyAppVersion "1.0.0.0"
#define MyAppPublisher "maohuawei"
#define MyAppURL "http://www.bdlbsc.com/"
#define MyAppExeName "app.exe"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (��Ҫ�����µ� GUID�����ڲ˵��е�� "����|���� GUID"��)
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
LicenseFile=D:\project\app\qt\aliyuncode\doper-dapp\deploy\���֤.txt
InfoBeforeFile=D:\project\app\qt\aliyuncode\doper-dapp\deploy\�û�Э��.txt
InfoAfterFile=D:\project\app\qt\aliyuncode\doper-dapp\deploy\��ӭʹ��.txt
; ������ȡ��ע�ͣ����ڷǹ���װģʽ�����У���Ϊ��ǰ�û���װ����
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
; ע��: ��Ҫ���κι���ϵͳ�ļ���ʹ�á�Flags: ignoreversion��

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

