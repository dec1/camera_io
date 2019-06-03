#pragma once

#include "jo_service.h"

namespace Jo
{
    class tClient;

    // Camera service encapsuates the hardware, and communictaes back to "client"
    // can have different derived classes depending on details such as connection type: usb/tcp etc
    // This class encapsulates those details from client and therefore rest of app
    class tJoServiceUsb : public tJoService
    {
    public:
        tJoServiceUsb(tJoClient * Cb);

        virtual ~tJoServiceUsb() override;
        // Init/Free a camera instance
        //----------------------------
        virtual void init() override {}
        virtual void free() override{}

        virtual const char * vendorInfo()   override{ return "my_vendor";}
        virtual const char * deviceId()     override { return "usb_dev_123";}
        virtual const char * deviceInfo()   override { return "details of device capabilities...";}

        // Image Capture
        //--------------
        virtual bool captureStart() override ;
        virtual bool captureStop()  override ;



        // --------   Configutarion ----------

        // Image Size
        //------------
        virtual tSize imageSizeDefault()    const   override { return tSize(800,600);}
        virtual tSize imageSize()           const   override { return _ImSize;}
        virtual bool setImageSize(tSize Size)       override {_ImSize = Size; return true;} // return value would be generally result of various checks first


        // Pixel Type
        //------------
        virtual etPixelType defaultPixelType()      const  override { return etPixelType::Rgb;}
        virtual etPixelType pixelType()             const  override  { return _PixType;}
        virtual bool setPixelType(etPixelType Type)        override { _PixType = Type; return true;}


        // Capture Rate (num of images sent to client per sec)
        //--------------
        virtual float captureRateDefault()         override  { return 5;}
        virtual float captureRate()                override  { return _captureRate;}
        virtual bool setCaptureRate(float rate)    override { _captureRate = rate; return true;}



    protected:

        tSize _ImSize = imageSizeDefault();
        etPixelType _PixType = defaultPixelType();
        float _captureRate;


    };
}


