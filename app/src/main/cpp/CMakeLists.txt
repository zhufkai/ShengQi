cmake_minimum_required(VERSION 3.4.1)
#set(libs “${CMAKE_SOURCE_DIR}/../jniLibs/jniLibs”)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})

# 导入inc第三库相关头文件路径
include_directories(${CMAKE_SOURCE_DIR}/inc)

add_library( # Sets the name of the library.
        qq_voicer
        SHARED
        effect_fix.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}")

#add_library(libfmod SHARED IMPORTED )
#set_target_properties(libfmod PROPERTIES
#        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libfmod.so)
#
#add_library(libfmodL SHARED IMPORTED )
#set_target_properties(libfmodL PROPERTIES
#        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libfmodL.so)

find_library( # Sets the name of the path variable.
        log-lib
        log)

target_link_libraries( # Specifies the target library.
        qq_voicer
        fmod
        fmodL

        ${log-lib})
