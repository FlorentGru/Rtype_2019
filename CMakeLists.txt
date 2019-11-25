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
include_directories(source/server/ source/client/ source/ecs source/network)

add_executable(rtype_server
        source/network/AUdpSocket.hpp source/network/RawData.hpp source/ecs/System/Events.hpp source/ecs/System/Events.cpp source/ecs/Ecs.cpp source/ecs/AbstractEcs.cpp source/ecs/Ecs.hpp source/server/gameEngine/GameEngine.cpp source/server/gameEngine/GameEngine.hpp)
target_link_libraries(rtype_server ${CONAN_LIBS})
set_target_properties(rtype_server PROPERTIES LINKER_LANGUAGE CXX)

add_executable(rtype_client
        source/network/Packet.hpp source/network/AUdpSocket.hpp source/network/RawData.hpp source/ecs/System/Events.hpp source/ecs/System/Events.cpp source/ecs/Ecs.cpp source/ecs/Ecs.hpp source/ecs/AbstractEcs.cpp source/ecs/AbstractEcs.hpp)
target_link_libraries(rtype_client ${CONAN_LIBS})
set_target_properties(rtype_client PROPERTIES LINKER_LANGUAGE CXX)