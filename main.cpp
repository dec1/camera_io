
#include "jop_camera_c.h"

#include "jo_service_usb.h"
#include "jo_client_usb.h"
#include "jo_camera_man.h"


int main(int argc, char *argv[])
{

    Jo::tJoCameraMan Man;
    Man.init();
    bool ret = Man.doIt();

    return 0;
}
