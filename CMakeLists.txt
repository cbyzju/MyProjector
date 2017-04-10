##ʹ��Cmake����VS����
##��Ͱ汾Ҫ��
Cmake_minimum_required(VERSION 2.8.11)

Message(STATUS  ${CMAKE_MODULE_PATh})
#���ù��������˺�ʹ��${projectName}����
Set(projectName ProCamera_system_vs)                                
Project(${projectName})

#����JDK
Set(jniPath )
include_directories(${jniPath})
include_directories(./jni)

#����JSON��
Set(JsonPath ./JSON)
include_directories(${JsonPath})
FILE(GLOB json ${JsonPath}/*.cpp ${JsonPath}/*.h)
SOURCE_GROUP("JSON_FILES" FILES ${json})

#����stateModel��
Set(StateModelPath ./stateModel)
include_directories(${StateModelPath})
FILE(GLOB stateModel ${StateModelPath}/*.cpp ${StateModelPath}/*.h)
SOURCE_GROUP("State_Model" FILES ${stateModel})

#����Astra��
SET(OpenNIPath C:/Program Files (x86)/OpenNI2)
INCLUDE_DIRECTORIES(${OpenNIPath}/Include 
${PROJECT_BINARY_PATh})

#����OpenCV��                                                                          
Set(OpenCV_DIR C:/opencv/build)                                                                 
Find_package(OpenCV REQUIRED)

#����ͷ�ļ���Դ�ļ�
FILE(GLOB hand_source ./jni/*.cpp)
FILE(GLOB hand_header ./jni/*.h)

#����ͷ�ļ���Դ�ļ���
SOURCE_GROUP("Source_Files" FILES ${hand_source} )
SOURCE_GROUP("header_Files" FILES ${hand_header} )
   
LINK_DIRECTORIES(${OpenNIPath}/Lib)
   
Add_executable(${projectName}  ${hand_source} ${hand_header} ${json} ${stateModel})

#����OpenCV��lib�ļ�                              
Target_link_libraries(${projectName} ${OpenCV_LIBS} OpenNI2.lib) 



              