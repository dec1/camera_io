#pragma once

#include "jo_image.h"

namespace Jo
{

    struct tJoClient
    {
        virtual ~tJoClient(){}

        //    should make deep copy image data immediately, else need
        //   (i)  service to provide freeImage(tImage::data *), or
        //   (ii) tImage::data as shared_ptr<byte>
        virtual void onImage(tImage)=0;

        virtual void onError(const char * str)=0;
        virtual void onMesg (const char * str)=0;

        //
        // ImageCache (eg to comensate some services having different capture rates, or support algorithms that need temporal context

        // eg Support upscaling of service images that only provide low resolution or smaller sized images

        // captureOne() - synchronously

        // ..............

    };

}



