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
include_directories(source/server
        source/client
        source/client/background
        source/client/window
        source/ecs
        source/ecs/System
        source/network
        source/ecs/Component
        source/ecs/Entity
        )

add_executable(rtype_server
        source/ecs/System/Events.cpp
        source/ecs/AbstractEcs.cpp
        source/ecs/ClientEcs.cpp
        source/ecs/ServerEcs.cpp
        source/server/gameEngine/GameEngine.cpp
        source/ecs/Component/Acceleration.cpp
        source/ecs/Component/Vector.cpp
        source/ecs/Component/Position.cpp
        source/ecs/Component/Rendering.cpp
        source/ecs/Component/Timer.cpp
        source/ecs/Component/Velocity.cpp
        source/ecs/Entity/Player.cpp
        source/ecs/System/Events.cpp
        source/ecs/ServerEcs.cpp
        source/ecs/ClientEcs.cpp
        source/ecs/System/UpdateEntitySystem.cpp
        source/ecs/Entity/Fire.cpp source/ecs/Entity/Fire.hpp
        source/server/server.cpp
        source/server/gameEngine/GameEngine.cpp
        source/server/main.cpp)

target_link_libraries(rtype_server ${CONAN_LIBS})
set_target_properties(rtype_server PROPERTIES LINKER_LANGUAGE CXX)

add_executable(rtype_client
        source/ecs/System/Events.cpp
        source/ecs/AbstractEcs.cpp
        source/ecs/Component/Acceleration.cpp
        source/ecs/Component/Vector.cpp
        source/ecs/Component/Position.cpp
        source/ecs/Component/Rendering.cpp
        source/ecs/Component/Timer.cpp
        source/ecs/Component/Velocity.cpp
        source/ecs/Entity/Player.cpp
        source/ecs/System/Events.cpp
        source/ecs/ServerEcs.cpp
        source/ecs/ClientEcs.cpp
        source/ecs/System/IRenderSystem.hpp
        source/ecs/System/UpdateEntitySystem.cpp
        source/ecs/Entity/Fire.cpp source/ecs/Entity/Fire.hpp source/ecs/Entity/RenderPlayer.cpp source/ecs/Entity/RenderPlayer.hpp
        source/client/client.cpp
        source/client/ClientEngine.cpp
        source/client/ClientMain.cpp
        source/client/background/background.cpp
        source/client/window/initWindow.cpp
        source/client/window/window.cpp
        source/client/main.cpp
        source/client/player.cpp)
        source/network/Packet.hpp source/network/AUdpSocket.hpp source/network/RawData.hpp source/client/ClientMain.cpp source/client/ClientMain.hpp source/client/ClientEngine.cpp source/client/ClientEngine.hpp
        source/ecs/System/IRenderSystem.hpp source/ecs/System/IEventsSystem.hpp)

target_link_libraries(rtype_client ${CONAN_LIBS})
set_target_properties(rtype_client PROPERTIES LINKER_LANGUAGE CXX)