 
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"




#include <vector>

#include "jo_camera_man.h"


//-----------------------------------------------------------------------
TEST_CASE( "Basic test for Camera Api" )
{
    Jo::tJoCameraMan Man;
    Man.init();
    bool ret = Man.doIt();
    CHECK(ret);

}
 
