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
include_directories(source/client source/network source/server)

add_executable(r-type_server
    source/server/main.cpp
    source/network/Packet.hpp
    source/network/Packet.cpp
    source/server/Server.cpp
    source/server/Server.hpp
    source/server/ClientManagement.hpp
    source/server/ClientManagement.cpp
    source/server/GameManagement.hpp
    source/server/GameManagement.cpp
    source/server/Session.cpp
    source/server/ISession.hpp
    source/server/Session.hpp
)
target_link_libraries(r-type_server ${CONAN_LIBS})

add_executable(r-type_client
    source/client/main.cpp
    source/network/Packet.hpp
    source/network/Packet.cpp
    source/client/Client.cpp
    source/client/Client.hpp
    source/client/ClientDataManagement.hpp
    source/client/IClientDataManagement.hpp
    source/client/ClientDataManagement.cpp
)
target_link_libraries(r-type_client ${CONAN_LIBS})