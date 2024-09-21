cmake_minimum_required(VERSION 3.10)

add_subdirectory( ./ImageRenderer )   # 源码

# 测试用例
if ( BUILD_TESTING )
	add_subdirectory( test )	# 测试用例
endif()