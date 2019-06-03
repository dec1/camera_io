#pragma once

#include  "jo_image.h"

#include <iostream>
#include <string>

namespace Jo
{

    class tJoClient;
    class tJoService;



    // A camera is composed of the 2 "endpoints":
    // (i)  client  (image consumer/callback)
    // (ii) service (image provider)
    class tJoCamera
    {
    public:
        tJoCamera(tJoClient * Client,  tJoService * Service);

        virtual ~tJoCamera();

        tJoService * service() { return _Service;}
        tJoClient * client()  { return _Client;}

        bool isValid(){ return _Client && _Service;}
        bool doIt();

        // can present whatever interface the rest of the app needs to the encapsulated service/client

        void onImage(tImage){std::cout<<"Image: "<<desc()<<" image received" <<std::endl;}
        void onError(const char * str){std::cout<<"Error: "<<desc()<<" " << str <<std::endl;}
        void onMesg (const char * str){std::cout<<"Mesg:  "<<desc()<<" " << str <<std::endl;}

        std::string desc();


    protected:
        tJoClient *    _Client;
        tJoService *  _Service;


    };

}
