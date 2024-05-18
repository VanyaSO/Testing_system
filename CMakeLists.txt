cmake_minimum_required(VERSION 3.12)

project(Testing_system)

add_executable(Testing_system
        main.cpp
        common/config.h
        common/Common/Common.h
        common/Common/Common.cpp
        Menu/Menu.h
        Menu/Menu.cpp
        Users/User.h
        Users/User.cpp
        Users/Tester/Tester.h
        Users/Tester/Tester.cpp
        Users/Admin/Admin.h
        Users/Admin/Admin.cpp
        Menu/AdminMenu/AdminMenu.cpp
        Test/Question/Question.h
        Test/Question/Question.cpp
        Test/Test.h
        Test/Test.cpp
        FileWriteReadTest/FileWriteReadTest.h
        FileWriteReadTest/FileWriteReadTest.cpp

)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Testing_system PROPERTY CXX_STANDARD 20)
endif()