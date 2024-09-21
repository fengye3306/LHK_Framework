#include <Framework_Plugin_operations/Template.hpp>

#include "./Model_NumberDisplay.hpp"
#include "./Model_NumberSet.hpp"

#include "./Model_MathOperation_Multiplication.hpp"

extern "C" FRAMEWORK_PLUGIN_OPERATIONS_EXPORT 
    bool PLUGIN_OUTPUT(std::shared_ptr<QtNodes::NodeDelegateModelRegistry> ret){
    
    ret->registerModel<Model_NumberDisplay>                              ("代数运算");
    ret->registerModel<Model_NumberSet>                                  ("代数运算");
    ret->registerModel<Model_MathOperation_Multiplication>               ("代数运算");
    return true;
};
