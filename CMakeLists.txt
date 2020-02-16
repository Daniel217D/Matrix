set(CMAKE_LEGACY_CYGWIN_WIN32 0) # Remove when CMake >= 2.8.4 is required

project(cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp main.cpp matrix.cpp matrix.h)