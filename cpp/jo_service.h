#pragma once

#include "jo_client.h"

namespace Jo
{
    class tJoService
    {
    public:
        tJoService(tJoClient * Cb)
               : _Callback(Cb){}
        virtual ~tJoService(){}
        // Init/Free a camera instance
        //----------------------------
        virtual void init()=0;
        virtual void free()=0;

        virtual const char * vendorInfo() =0;
        virtual const char * deviceId()   =0;
        virtual const char * deviceInfo() =0;

        // Image Capture
        //--------------
        virtual bool captureStart() =0;
        virtual bool captureStop()  =0;


        // --------   Configutarion ----------

        // Image Size
        //------------
        virtual tSize imageSizeDefault()    const   =0;
        virtual tSize imageSize()           const   =0;
        virtual bool setImageSize(tSize Size)       =0;


        // Pixel Type
        //------------
        virtual etPixelType defaultPixelType()      const    =0;
        virtual etPixelType pixelType()             const    =0;
        virtual bool setPixelType(etPixelType Type)          =0;


        // Capture Rate (num of images sent to client per sec)
        //--------------
        virtual float captureRateDefault()           =0;
        virtual float captureRate()                  =0;
        virtual bool setCaptureRate(float rate)      =0;



    protected:

        tJoClient * _Callback;


        void sendMesg(const char * str)     { if(_Callback) _Callback->onMesg(str);}
        void sendError(const char * str)    { if(_Callback) _Callback->onError(str);}
        void sendImage(tImage Img)          { if(_Callback) _Callback->onImage(Img);}



    };
}


