cmake_minimum_required(VERSION 3.10)
project(test_ImageRenderer CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
# RPATH 以便在构建和安装时使用
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib/")

file( GLOB test_header_list ./*.hpp )	    # 所有.hpp文件
file( GLOB test_source_list ./*.cpp )		# 所有.cpp文件


add_executable(
	${PROJECT_NAME} 
    ${test_header_list}
    ${test_source_list}
)

# Debug 模式下的可执行文件后缀
set(CMAKE_DEBUG_POSTFIX "d")
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
target_link_libraries(${PROJECT_NAME} PUBLIC ImageRenderer)
target_link_libraries(${PROJECT_NAME} PUBLIC ImageROI)

# 安装
# 将可执行文件安装到bin目录中
install(TARGETS ${PROJECT_NAME} DESTINATION bin/tests/)                 
