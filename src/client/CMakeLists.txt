#查找当前文件夹中的所有源代码文件，也可以通过Set命令将所有文件设置为一个变量
#FILE(GLOB SRC_FILES "./*.cxx") 
#同理，查找当前文件夹中所有的头文件
FILE(GLOB HEAD_FILES "./*.h") 
#同理，查找当前文件夹中所有的ui文件
FILE(GLOB UI_FILES "./*.ui") 

FILE(GLOB SRC_FILES "./*.cpp" "./*.m"  "./*.mm")


set(RESOURCE_DIR resources/res.qrc)
#通过Ui文件生成对应的头文件，一定要添加
qt5_wrap_ui(WRAP_FILES ${UI_FILES})
qt5_add_resources(RCC resources/res.qrc)

 
#将ui文件和生成文件整理在一个文件夹中，非必须
source_group("Ui" FILES ${UI_FILES} ${WRAP_FILES} )

link_libraries(${APPKIT_LIBRARY})
#创建工程文件
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES} ${WRAP_FILES} ${RESOURCE_DIR})
 
#添加Qt5依赖项
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui)


