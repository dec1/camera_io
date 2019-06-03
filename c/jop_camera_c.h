#pragma once

extern "C"
{
// convenicence typedefs general
typedef unsigned char byte;
typedef unsigned int uint;

// opaque pointers to (eg c++) implmentations
typedef void * tImp;

const int camera_api_version =1;
//-----------------------------------------
struct tSize
{
    int width;
    int height;
};
//-----------------------------------------
enum etPixelType
{
    Rgb,
    Gray_8,
    Gray_16,
    //.......
};
// byte alignment etc explicit or implict (doc)


//----------------------------------------
struct tImage
{
    byte *data;
    tSize size;
    etPixelType pixel_type;
};



//------------------------------------------
// ------------- Manager  -------------------
//------------------------------------------
// iterates through "installed" plugins, and queries each for attached devs of supported type
int connectedDevs();

// x-platform/loading of plugins (each of which possibly implemented indifferent langauge and for different pyhsical connection usb/ethernet),
// symbol resolution etc
// mediates client-service:
// eg client doesnt call service functions (directly), but instead Manager proxies eg
// tImp Manager::service_init(tImp Client, int connectedDev)
// void Manager::service_free(tImp Service)
// ......

//------------------------------------------
// ------------- Client  -------------------
//------------------------------------------
// client should deep copy image data immediately, or need service to provide freeImage(tImp Client, tImage)
void onImage(tImp Client, tImage);

void onError(tImp Client, const char * str);
void onMesg (tImp Client, const char * str);



//------------------------------------------
// ------------- Service  ------------------
//------------------------------------------

// convenience typedefs for function pointers
typedef void (*tCbStr)(tImp Client, const char*);
typedef void (*tCbImg)(tImp Client, tImage);
//------------------------------------------


// Init/Free a camera instance
//----------------------------
tImp init_(tImp Client);
void free_(tImp Service);

const char * vendorInfo();
const char * deviceId();
const char * deviceInfo();


// Image Capture
//--------------
bool captureStart(tImp Service);
bool captureStop(tImp Service);


// Client Calbacks
// ------------------
bool setCbImage(tImp Service, tCbImg);
bool setCbError(tImp Service, tCbStr);
bool setCbMesg (tImp Service, tCbStr);


// --------   Configutarion ----------

// Image Size
//------------
tSize imageSizeDefault(tImp Service);
tSize imageSize(tImp Service);
bool setImageSize(tImp Service, tSize);


// Pixel Type
//------------
etPixelType pixelType(tImp Service);
bool setPixelType(tImp Service, etPixelType);


// Capture Rate (num of images sent to client per sec)
//--------------
float captureRateDefault(tImp Service);
float captureRate(tImp Service);
bool setCaptureRate(tImp Service, float);




}




