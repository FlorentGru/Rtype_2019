cmake_minimum_required(VERSION 3.5)
project(rtype LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
if (UNIX)
    add_definitions("-fPIC -Wall -Wextra -Wshadow -Wuninitialized -Wunreachable-code")
endif (UNIX)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(build/conanbuildinfo.cmake)
conan_basic_setup()

include(CPack)
include_directories(server/includes source/client source/client/window source/client/background)

add_executable(r-type_server
        source/server/main.cpp
        source/server/server.cpp
        source/server/server.hpp
        source/network/AUdpSocket.hpp source/network/RawData.hpp)
target_link_libraries(r-type_server ${CONAN_LIBS})

add_executable(r-type_client
  source/client/main.cpp
  source/client/window/window.cpp
  source/client/window/window.hpp
  source/client/window/initWindow.hpp
  source/client/window/initWindow.cpp
  source/client/window/AWindow.hpp
  source/client/background/background.hpp
  source/client/background/background.cpp
  source/client/client.cpp
  source/client/client.hpp
        source/network/Packet.hpp source/network/AUdpSocket.hpp source/network/RawData.hpp)
target_link_libraries(r-type_client ${CONAN_LIBS})
