cmake_minimum_required(VERSION 3.14)
project(GraphicsRenderer VERSION 1.0.0)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置 Debug 模式下的库后缀
set(CMAKE_DEBUG_POSTFIX "d")

# 设置安装和运行时的rpath
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# 文件列表 
file(GLOB_RECURSE header_list ./include/*.hpp)
file(GLOB_RECURSE source_list ./src/*.cpp)

# 创建动态库
add_library(${PROJECT_NAME} SHARED 
    ${header_list} 
    ${source_list}
)
# 导出宏
add_definitions(-DGraphicsRenderer_LIBRARY)

# 引入自己的头文件目录路径  公有化使得当此库被包含时共享此环境
target_include_directories( ${PROJECT_NAME} PUBLIC  
	${CMAKE_CURRENT_SOURCE_DIR}/include/ )	

# 引入构建目录路径
target_include_directories( ${PROJECT_NAME} PRIVATE  
	 ${CMAKE_CURRENT_BINARY_DIR} )	

# 第三方开源模块
## OpenCV
find_package(OpenCV REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBS})
# TBB
find_package(TBB REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC TBB::tbb)

# -安装
# 安装库文件到 lib 目录
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
# 安装头文件到 include 目录
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include)
