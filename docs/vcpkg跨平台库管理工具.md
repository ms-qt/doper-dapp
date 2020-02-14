# C++ 跨平台库管理工具vcpkg

> 跨平台，可以在windows macos linux 上使用

## github 地址

[https://github.com/microsoft/vcpkg](https://github.com/microsoft/vcpkg)


## 前提


### windows 

- 安装cmake
- 安装visual studio 2015(pw以上) （我安装2017）

### ubuntu

	sudo apt-get install curl


## 安装

 	git clone https://github.com/Microsoft/vcpkg.git
 	cd vcpkg

- windows

 		.\bootstrap-vcpkg.bat

- macos or linux 

		./bootstrap-vcpkg.sh

- 集成范围（windows 需要管理员权限，mac linux 需要root权限）

		vcpkg integrate install

## 安装库

eg : 

windows 安装64为的folly

	vcpkg install folly:x64-windows

macos 安装64为的folly

	vcpkg install folly:x64-osx



## 使用

Visual Studio 可以直接引入库头文件（版本需要注意 x86 x64）

MacOS 使用的时候 CMake 环境变量添加 
	
		-DCMAKE_TOOLCHAIN_FILE={自己安装目录}\scripts/buildsystems/vcpkg.cmake



