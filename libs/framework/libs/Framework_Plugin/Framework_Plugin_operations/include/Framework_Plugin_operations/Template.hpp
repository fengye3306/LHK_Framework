

#pragma once

#include <QtCore/qglobal.h>
#include <fstream>
#include <vector>

#include <QtNodes/NodeDelegateModelRegistry>


/**
 * 本文件用于模块的动态加载
 * * static 会将函数的作用域限制在当前编译单元内，因此所有的接口均不可使用static
 * * 函数实现不能放在头文件中，例如GCC编译器就无法处理出在头文件中定义的导出函数
 */

#if defined(FRAMEWORK_PLUGIN_OPERATIONS)
#  define FRAMEWORK_PLUGIN_OPERATIONS_EXPORT Q_DECL_EXPORT
#else
#  define FRAMEWORK_PLUGIN_OPERATIONS_EXPORT Q_DECL_IMPORT
#endif

extern "C" FRAMEWORK_PLUGIN_OPERATIONS_EXPORT 
    bool PLUGIN_OUTPUT(std::shared_ptr<QtNodes::NodeDelegateModelRegistry> ret);

