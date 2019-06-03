#include "jo_client_usb.h"
#include "jo_camera.h"

namespace Jo
{

    tJoClientUsb::tJoClientUsb(tJoCamera * Cam)
     :_Camera(Cam){}
    //------------------------------------
    tJoClientUsb::~tJoClientUsb()
    {

    }
    //-----------------------------------
    void tJoClientUsb::onImage(tImage Img)
    {
        if(_Camera)
            _Camera->onImage(Img);
    }
    //------------------------------------
    void tJoClientUsb::onError(const char * str)
    {
        if(_Camera)
            _Camera->onError(str);
    }
    //------------------------------------
    void tJoClientUsb::onMesg (const char * str)
    {
        if(_Camera)
            _Camera->onMesg(str);
    }
}
