#pragma once

#include "jo_camera.h"


#include <iostream>
#include <vector>
#include <memory>


namespace Jo
{

    // Camera Manager: administers connected cameras
    class tJoCameraMan
    {
    public:
        tJoCameraMan();
        virtual ~tJoCameraMan();

        bool init();
        bool free();

        bool doIt();

        bool isValid();

    protected:
        std::vector< std::shared_ptr< tJoCamera> > _Cameras;

    };

}
