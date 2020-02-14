# RSocket cpp 编译

## 项目地址

[https://github.com/rsocket/rsocket-cpp.git](https://github.com/rsocket/rsocket-cpp.git)

## 前提

- 安装vcpkg

- 使用vcpkg 安装 folly

- 使用vcpkg 安装 fmt

## macos 

	git clone https://github.com/rsocket/rsocket-cpp.git	
	cd rsocket-cpp
	mkdir release
	cd release
	cmake -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_TOOLCHAIN_FILE=/home/dev/Desktop/vcpkg/scripts/buildsystems/vcpkg.cmake ../
	make 
	make install 

## ubuntu 

	git clone https://github.com/rsocket/rsocket-cpp.git	
	cd rsocket-cpp
	mkdir release
	cd release
	cmake -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_TOOLCHAIN_FILE=/home/dev/Desktop/vcpkg/scripts/buildsystems/vcpkg.cmake ../
	make 
	make install 


## windows 
