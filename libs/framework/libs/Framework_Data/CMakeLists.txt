

project( Framework_Data ) 

# 查找 include 文件夹中的 .hpp 和 .h 文件
file(GLOB_RECURSE header_list_out_hpp ./include/*.hpp)   # 查找所有 .hpp 文件
file(GLOB_RECURSE header_list_out_h   ./include/*.h)     # 查找所有 .h 文件

# 合并 .hpp 和 .h 文件列表
set(header_list_out ${header_list_out_hpp} ${header_list_out_h})

# 查找 src 文件夹中的 .hpp 和 .h 文件
file(GLOB_RECURSE header_list_hpp ./src/*.hpp)
file(GLOB_RECURSE header_list_h   ./src/*.h)

# 合并 .hpp 和 .h 文件列表
set(header_list ${header_list_hpp} ${header_list_h})

# 查找 src 文件夹中的 .cpp 文件
file(GLOB_RECURSE source_list ./src/*.cpp)

# 查找 ui_templates 文件夹中的 .ui 文件
file(GLOB_RECURSE ui_list ./ui_templates/*.ui)

# 查找 res 文件夹中的 .qrc 文件
file(GLOB_RECURSE qrc_list ./res/*.qrc)

find_package(Qt5 COMPONENTS 
	Core 
	Gui 
	Widgets 
	Quick 
	Qml 
	Network 
	OpenGL
	Xml 
	Sql 
	Test 
	Concurrent 
	PrintSupport 
	Multimedia 
	MultimediaWidgets 
	Bluetooth 
	REQUIRED
)

# 使用Qt5的uic工具处理.ui文件并生成头文件，
qt5_wrap_ui( generated_ui_list ${ui_list} )
# 使用Qt5的rcc工具处理.qrc文件并生成源文件，
qt5_add_resources( generated_qrc_list ${qrc_list} )
# MOC工具
set(CMAKE_AUTOMOC ON)

# RPATH 以便在构建和安装时使用
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib/")

# get project 
add_library ( 
	${PROJECT_NAME}   
	SHARED
	${header_list_out} 
	${header_list} 
	${source_list} 
	${generated_ui_list} 
	${generated_qrc_list}
)

# 引入自己的头文件目录路径  公有化使得当此库被包含时共享此环境
target_include_directories( ${PROJECT_NAME} PUBLIC  
	${CMAKE_CURRENT_SOURCE_DIR}/include/ )	

# 引入构建目录路径
target_include_directories( ${PROJECT_NAME} PRIVATE  
	 ${CMAKE_CURRENT_BINARY_DIR} )	

# 支持c++17标准
target_compile_features(
	${PROJECT_NAME} PRIVATE cxx_std_17
)

target_link_libraries( 
	${PROJECT_NAME} 
	PUBLIC
	Qt5::Core  
	Qt5::Gui  
	Qt5::Quick  
	Qt5::OpenGL  
	Qt5::PrintSupport  
	Qt5::Sql 
	Qt5::Widgets
)


# 第三方开源模块
## OpenCV
find_package(OpenCV REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBS})


# -安装
# 安装库文件到 lib 目录
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
# 安装头文件到 include 目录
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include)

