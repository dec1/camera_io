#include "jo_camera_man.h"
#include "jo_service_usb.h"
#include "jo_client_usb.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::string;

namespace Jo
{
    tJoCameraMan::tJoCameraMan()
    {

    }
    //-------------------------------
    tJoCameraMan::~tJoCameraMan()
    {
        free();
    }
    //-------------------------------
    bool tJoCameraMan::free()
    {
       _Cameras.clear();
       return true;
    }
      //-------------------------------
    bool tJoCameraMan::isValid()
    {
        if(_Cameras.empty())
              return false;

        for(auto Camera: _Cameras)
            if(!Camera->isValid())
                return false;

        return true;
    }
    //-------------------------------
    bool tJoCameraMan::init()
    {
       free();

       // for each physically connected camera device
       // create a software Camera object:

       auto Client = new tJoClientUsb();
       auto Service = new tJoServiceUsb(Client);    // dependency injection

       auto Camera = make_shared<tJoCamera>(Client, Service);
       Client->setCamera(Camera.get());             // dependency injection
       _Cameras.push_back(Camera);                  // everywhere else Cameras can be treated polymorphically (base class pointers -> derived class implementation)

                                                    // tJoServiceUsb "knows" nothing about tJoClientUsb and vice versa

       return isValid();

    }
    //-------------------------------
    bool tJoCameraMan::doIt()
    {
        if(!isValid())
            return false;


         for(auto Camera: _Cameras)
         {
             if(Camera)
                Camera->doIt();                 //  polymorphism
         }

         return true;

    }

}
