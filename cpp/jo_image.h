#pragma once

namespace Jo
{


    typedef unsigned char byte;
    typedef unsigned int uint;


    const int camera_api_version =1;
    //-----------------------------------------
    struct tSize
    {
        int width;
        int height;

        tSize(int w, int h)
            : width(w), height(h){}
    };
    //-----------------------------------------
    enum etPixelType
    {
        Rgb,
        Gray_8,
        Gray_16,
        //.......
    };
    //-----------------------------------------
    // byte alignment etc explicit or implict (doc)
    //-----------------------------------------


    struct tImage
    {
        byte *data = nullptr;          // alternative: shared_ptr<byte> .. no need for explcitit "free"
        tSize size = tSize(0,0);
        etPixelType pixel_type = Rgb;
    };

}




