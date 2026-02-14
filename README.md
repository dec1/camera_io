# camera_io

Api for managing one or more connected cameras, with mock implementation and automated test.

[![CI](https://github.com/dec1/camera_io/actions/workflows/ci.yaml/badge.svg)](https://github.com/dec1/camera_io/actions/workflows/ci.yaml)

Each attached hardware camera is encapsulated by a [Camera](cpp/jo_camera.h) object. 
A [CameraMan](cpp/jo_camera_man.h) object manages the set of all connected cameras.


A camera itself encapsulates a [Service](cpp/jo_service.h) and [Client](cpp/jo_cliente.h) endpoint. The service (*command executer*) interacts (most) directly with the hardware device, and communicates with the app only through its corresponding client (*command result interpreter*), which interprets and optionally filters these replies (eg rescaling, pixel format conversion, caching etc). The client enables the rest of the application can treat each camera identically (smothing over hardware differences such as different native camera resolutions and/or capture rates). Object-orientated patterns such as dependency injecton, abstract base classes and use of the pImpl idiom make it easy to extend both client and/or service orthogonally with minimum impact on the rest of the application (which only sees the minimum but sufficient virtual base class interfaces). eg a new class  derived from tJoService analogous to [jo_service_usb.h](cpp/jo_service_usb.h) could be added later to support some new means of communication eg bluetooth (it simply has to support the base class interface and implement pure virtual methods in [jo_service.h](cpp/jo_service.h).). Each of Camera, Service and Client are all oblivious to the existence of any derived classes of the other 2 - dependency injection in the manager gives them the base class pointers they need to act polymorphically.

*Note: In general one could specify separate (embedded) formats for (wire) transfer and memory representation, if one needed to make maximum use of bandwidth*

| RAM           | Wire          | Wire          |    RAM
| ------------- | ------------- | ------------- | ------------- 
| etPixelType   |etPixelType    | etPixelType   | etPixelType
|               |compressed     | compressed    | 





An example automated [test](test/main_test.cpp) is included for comleteness.

Structure: 

- [cpp](cpp) - The c++ code
- [c](c) - An optional c interface as a possible (but less elegant and effective) alternative to the c++ version, that uses opaque pointers to facilitate object orientation on either side of the c-interface
- [test](test) - Automated test
 
 
## Prerequisites
- c++ (*version C++11 or later*)
- cmake (*version 3.0 or later*)

## Usage


- Clone this repo

`> git clone https://github.com/dec1/camera_io.git`

`> cd camera_io`

- Create native build files (in dir "out") 

`> cmake . -B./out`

- Build executable from native build files


`> cmake --build out`

- Run the executable

*(Note: On Ms Windows with Visual Studio compiler, the paths below may differ slightly)*

`> out/camera_io`

```
Mesg:  Camera Service: usb_dev_123 capture mode - begin...
Image: Camera Service: usb_dev_123 image received
Image: Camera Service: usb_dev_123 image received
Mesg:  Camera Service: usb_dev_123 capture mode - end...
```

- Run the tests

`> out/test/camera_io_test`

```
Mesg:  Camera Service: usb_dev_123 capture mode - begin...
Image: Camera Service: usb_dev_123 image received
Image: Camera Service: usb_dev_123 image received
Mesg:  Camera Service: usb_dev_123 capture mode - end...
===============================================================================
All tests passed (1 assertion in 1 test case)                           
```


