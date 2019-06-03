
set(SOURCES
    main_test.cpp

    ../cpp/jo_image.h
    ../cpp/jo_client.h
    ../cpp/jo_service.h
    ../cpp/jo_camera.h
    ../cpp/jo_camera.cpp

    ../cpp/jo_camera_man.cpp
    ../cpp/jo_camera_man.h

    ../cpp/jo_client_usb.cpp
    ../cpp/jo_client_usb.h
    ../cpp/jo_service_usb.cpp
    ../cpp/jo_service_usb.h
 )



set(MY_TARG ${PROJECT_NAME}_test)


add_executable(${MY_TARG} ${SOURCES} )


target_include_directories(${MY_TARG} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../cpp)
message(STATUS  " ......." ${CMAKE_CURRENT_LIST_DIR}/cpp/..)
