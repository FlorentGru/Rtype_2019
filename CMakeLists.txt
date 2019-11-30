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
        source/ecs/System
        source/network
        source/ecs/Component
        source/ecs/Entity
        source/ecs/Entity/Client
        source/ecs/Entity/Server
        )

add_executable(r-type_server
        source/server/main.cpp
        source/server/Server.cpp
        source/server/ServerNetwork.cpp
        source/server/Session.cpp
        source/ecs/System/Events.cpp
        source/ecs/AbstractEcs.cpp
        source/ecs/Component/Acceleration.cpp
        source/ecs/Component/Vector.cpp
        source/ecs/Component/Position.cpp
        source/ecs/Component/Rendering.cpp
        source/ecs/Component/Timer.cpp
        source/ecs/Component/Velocity.cpp
        source/ecs/Entity/Server/Player.cpp
        source/ecs/System/Events.cpp
        source/ecs/ServerEcs.cpp
        source/ecs/ClientEcs.cpp
        source/ecs/System/UpdateEntitySystem.cpp
        source/ecs/Entity/Server/Fire.cpp
        source/ecs/Entity/SerializedEntity.cpp
        source/network/PacketManager.cpp
        source/network/RawData.cpp
        source/network/BoostUdpServer.cpp
        )

target_link_libraries(r-type_server ${CONAN_LIBS})
set_target_properties(r-type_server PROPERTIES LINKER_LANGUAGE CXX)

add_executable(r-type_client
        source/client/main.cpp
        source/ecs/System/Events.cpp
        source/ecs/AbstractEcs.cpp
        source/ecs/Component/Acceleration.cpp
        source/ecs/Component/Vector.cpp
        source/ecs/Component/Position.cpp
        source/ecs/Component/Rendering.cpp
        source/ecs/Component/Timer.cpp
        source/ecs/Component/Velocity.cpp
        source/ecs/System/Events.cpp
        source/ecs/ServerEcs.cpp
        source/ecs/ClientEcs.cpp
        source/ecs/Entity/Client/RenderPlayer.cpp
        source/ecs/Entity/Client/RenderFire.cpp
        source/ecs/Entity/SerializedEntity.cpp
        source/network/PacketManager.cpp
        source/client/ClientNetwork.cpp
        source/network/BoostUdpClient.cpp
        source/client/Client.cpp
        source/network/RawData.cpp
        )

target_link_libraries(r-type_client ${CONAN_LIBS})
set_target_properties(r-type_client PROPERTIES LINKER_LANGUAGE CXX)


