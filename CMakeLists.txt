##使用Cmake构建VS工程
##最低版本要求
Cmake_minimum_required(VERSION 2.8.11)

Message(STATUS  ${CMAKE_MODULE_PATh})
#设置工程名，此后使用${projectName}代替
Set(projectName ProCamera_system_vs)                                
Project(${projectName})

#添加JDK
Set(jniPath )
include_directories(${jniPath})
include_directories(./jni)

#添加JSON库
Set(JsonPath ./JSON)
include_directories(${JsonPath})
FILE(GLOB json ${JsonPath}/*.cpp ${JsonPath}/*.h)
SOURCE_GROUP("JSON_FILES" FILES ${json})

#添加stateModel库
Set(StateModelPath ./stateModel)
include_directories(${StateModelPath})
FILE(GLOB stateModel ${StateModelPath}/*.cpp ${StateModelPath}/*.h)
SOURCE_GROUP("State_Model" FILES ${stateModel})

#配置Astra库
SET(OpenNIPath C:/Program Files (x86)/OpenNI2)
INCLUDE_DIRECTORIES(${OpenNIPath}/Include 
${PROJECT_BINARY_PATh})

#配置OpenCV库                                                                          
Set(OpenCV_DIR C:/opencv/build)                                                                 
Find_package(OpenCV REQUIRED)

#添加头文件和源文件
FILE(GLOB hand_source ./jni/*.cpp)
FILE(GLOB hand_header ./jni/*.h)

#添加头文件和源文件组
SOURCE_GROUP("Source_Files" FILES ${hand_source} )
SOURCE_GROUP("header_Files" FILES ${hand_header} )
   
LINK_DIRECTORIES(${OpenNIPath}/Lib)
   
Add_executable(${projectName}  ${hand_source} ${hand_header} ${json} ${stateModel})

#链接OpenCV库lib文件                              
Target_link_libraries(${projectName} ${OpenCV_LIBS} OpenNI2.lib) 



              