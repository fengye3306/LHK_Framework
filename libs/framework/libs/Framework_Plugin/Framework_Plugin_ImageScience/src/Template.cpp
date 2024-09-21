

#include "./Template.hpp"

#include "./Model_ImageLoader/Model_ImageLoader.hpp"
#include "./Model_ImageDisplay/Model_ImageDisplay.hpp"


#include "./Model_ImagePreprocessing/Model_ImagePreprocessing_output.hpp"


extern "C" Framework_Plugin_ImageScience_EXPORT 
    bool PLUGIN_OUTPUT(std::shared_ptr<QtNodes::NodeDelegateModelRegistry> ret){
    
    ret->registerModel<framework::Model_ImageLoader>               ("图像学");
    ret->registerModel<framework::Model_GlobalBinaryThresholding>     ("图像学");
    ret->registerModel<framework::Model_ImageDisplay>              ("图像学");

    return true;
};
