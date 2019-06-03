#include "jo_service_usb.h"

#include "jo_image.h"

namespace Jo
{

   tJoServiceUsb::tJoServiceUsb(tJoClient * Cb)
        : tJoService(Cb)
   {
   }
    //------------------------------------------------------
   tJoServiceUsb::~tJoServiceUsb()
   {
        free();
   }
   //------------------------------------------------------
   bool tJoServiceUsb::captureStart()
   {
       sendMesg("capture mode - begin...");
       tImage Img;
       sendImage(Img);
       sendImage(Img);
       //......

       return true;

   }
   //------------------------------------------------------
   bool tJoServiceUsb::captureStop()
   {
       sendMesg("capture mode - end...");
       return true;

   }


}
