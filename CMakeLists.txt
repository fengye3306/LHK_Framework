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

# RPATH
if( WIN32 )
    set( INSTALL_DESTINATIONS ${CLOUDCOMPARE_DEST_FOLDER} )

    if( ${OPTION_BUILD_CCVIEWER} )
        list( APPEND INSTALL_DESTINATIONS ${CCVIEWER_DEST_FOLDER} )
	endif()
elseif( UNIX AND NOT APPLE )
	# RPATH Linux/Unix: (dynamic) libs are put in $prefix/$lib/cloudcompare,
	# since they are only used by qCC/ccViewer
	include( GNUInstallDirs )
	set( LINUX_INSTALL_SHARED_DESTINATION "${CMAKE_INSTALL_FULL_LIBDIR}/cloudcompare" )
	set( CMAKE_INSTALL_RPATH ${LINUX_INSTALL_SHARED_DESTINATION} )
	set( INSTALL_DESTINATIONS ${CMAKE_INSTALL_PREFIX})
endif()


# 测试
option( BUILD_TESTING "Build tests" OFF )


add_subdirectory( ./libs )	   # 库
add_subdirectory( ./LIHONGKE )   # 主工程


