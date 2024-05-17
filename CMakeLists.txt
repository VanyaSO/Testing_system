# CMakeList.txt : CMake project for Testing_system, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Testing_system "main.cpp" "config.h" "Users/User.h" "Users/User.cpp" "Users/Tester/Tester.h" "Users/Tester/Tester.cpp" "Users/Admin/Admin.h" "Users/Admin/Admin.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Testing_system PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
