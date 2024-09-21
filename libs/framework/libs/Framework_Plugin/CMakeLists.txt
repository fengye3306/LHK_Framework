

project( Framework_Plugin ) 

# RPATH 以便在构建和安装时使用
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib/")


add_subdirectory( ./Framework_Plugin_operations )
add_subdirectory( ./Framework_Plugin_ImageScience )

