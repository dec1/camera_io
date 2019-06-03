cmake_minimum_required(VERSION 3.0.0)

project(camera_io VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)

# find_package(Qt5Core)

set(My_Sources_Cpp

    cpp/jo_image.h
    cpp/jo_client.h
    cpp/jo_service.h
    cpp/jo_camera.h
    cpp/jo_camera.cpp

    cpp/jo_camera_man.cpp
    cpp/jo_camera_man.h

    cpp/jo_client_usb.cpp
    cpp/jo_client_usb.h
    cpp/jo_service_usb.cpp
    cpp/jo_service_usb.h

    )

add_executable(${PROJECT_NAME}
    main.cpp
    c/jop_camera_c.h
    ${My_Sources_Cpp}
    )

target_include_directories(${PROJECT_NAME} PUBLIC cpp)
target_include_directories(${PROJECT_NAME} PUBLIC c)

add_subdirectory(test)

