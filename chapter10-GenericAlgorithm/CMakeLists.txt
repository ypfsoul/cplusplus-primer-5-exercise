#项目信息
PROJECT(main)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
#源文件列表
SET(SRC_LIST ${DIR_SRCS})

#编译器
SET(CMAKE_CXX_COMPILER "clang++")
#编译参数(最好不要加 -Werror)
SET(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ -Weverything -Wno-deprecated-declarations -Wno-disabled-macro-expansion -Wno-float-equal -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-global-constructors -Wno-exit-time-destructors -Wno-missing-prototypes -Wno-padded -Wno-old-style-cast")
#链接参数
SET(CMAKE_EXE_LINKER_FLAGS "-lc++ -lc++abi")
#生成类型debug/release
SET(CMAKE_BUILD_TYPE Debug)
#指定生成目标
ADD_EXECUTABLE(main ${SRC_LIST})
