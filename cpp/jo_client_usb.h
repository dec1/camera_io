#pragma once

class tJoCamera;

#include "jo_client.h"
#include "jo_camera.h"

#include <iostream>

namespace Jo
{

    // client what the camera service "sees" and communicates with.
    class tJoClientUsb : public tJoClient
    {
    public:
        tJoClientUsb(tJoCamera * Cam = nullptr);
        virtual ~tJoClientUsb();

        void setCamera(tJoCamera *Cam){_Camera = Cam;}

        bool doIt(){onMesg(" Client doing it..."); return true;}

        virtual void onImage(tImage Img)       override;
        virtual void onError(const char * str) override;
        virtual void onMesg (const char * str) override;

    protected:
        tJoCamera * _Camera;
    };

}
