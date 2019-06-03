#include "jo_camera.h"
#include "jo_service.h"
#include "jo_client.h"

#include <string>
using std::string;

namespace Jo
{

    tJoCamera::tJoCamera(tJoClient * Client,  tJoService * Service)
        : _Client(Client), _Service(Service)
    {}
    //------------------------------------
    tJoCamera::~tJoCamera()
    {

        delete _Service;
        delete _Client;

    }
    //_---------------------------------------------
    bool tJoCamera::doIt()
    {
        if(!isValid())
            return false;



        tJoService * Service = service();
        string id =  Service->deviceId();
        if(service())
            service()->captureStart();
            service()->captureStop();

        return true;
    }
    //---------------------------------------------
   string tJoCamera::desc()
   {
       return _Service? string("Camera Service: ").append(_Service->deviceId()) : "No Camera Service";
   }



}
