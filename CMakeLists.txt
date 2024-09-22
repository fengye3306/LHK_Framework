cmake_minimum_required( VERSION 3.10 )

# One shouldn't generate the BUILD project directly in the SOURCES folder!
# 不应该直接在 SOURCES 文件夹中生成 BUILD 项目！
if ( ${CMAKE_CURRENT_BINARY_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR} )
	if ( NOT SAME_BUILD_AND_SOURCE_FOLDER_WARNING_ALREADY_ISSUED )
		message(FATAL_ERROR "It is not advised to BUILD the binaries directly in the SOURCE folder!\n If you want to proceed with this option, just CONFIGURE the project once again" )
		set( SAME_BUILD_AND_SOURCE_FOLDER_WARNING_ALREADY_ISSUED TRUE )
	endif()
endif()


# Default debug suffix for libraries.
# 默认的调试库后缀。
set( CMAKE_DEBUG_POSTFIX "d" )

# 测试
option( BUILD_TESTING "Build tests" OFF )

add_subdirectory( ./libs )	   	 # 库
add_subdirectory( ./LIHONGKE )   # 主工程

