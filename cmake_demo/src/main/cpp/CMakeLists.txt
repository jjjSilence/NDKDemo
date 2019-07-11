# 设置Cmake最小版本
cmake_minimum_required(VERSION 3.4.1)

add_library(
        # 设置library名称
        native-lib

        # 设置library模式
        # SHARED模式会编译so文件，STATIC模式不会编译
        SHARED

        # 设置原生代码路径
        native-lib.cpp)
target_include_directories(native-lib PRIVATE
        #配置include的路径(如果需要使用.h文件的话)
        ${CMAKE_SOURCE_DIR}/../myinclude
        )

add_library(
        # Sets the name of the library.
        #jni的loadLibrary的名称
        libaiengine

        # 设置library模式
        # SHARED模式会编译so文件，STATIC模式不会编译
        SHARED

        #jni的源文件
        aiengine.cpp)
target_include_directories(native-lib PRIVATE
        #配置include的路径(如果需要使用.h文件的话)
        ${CMAKE_SOURCE_DIR}/../libs/{ANDROID_ABI}/libaiengine.so
        )

# 定位library
find_library(
        # library名称
        log-lib

        # 将library路径存储为一个变量，可以在其他地方用这个变量引用NDK库
        # 在这里设置变量名称
        log)

# 关联library
target_link_libraries(
        # 关联的native-lib
        native-lib

        #关联so文件lib
        libaiengine

        # 关联log-lib
        ${log-lib})
