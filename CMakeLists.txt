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
        source/ecs/Entity/Fire.cpp source/ecs/Entity/Fire.hpp)

target_link_libraries(rtype_server ${CONAN_LIBS})
set_target_properties(rtype_server PROPERTIES LINKER_LANGUAGE CXX)

include_directories(source/server
        source/client
        source/ecs
        source/ecs/System
        source/network
        source/ecs/Component
        source/ecs/Entity
        )

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
        source/ecs/System/IRenderSystem.hpp)
        source/ecs/System/UpdateEntitySystem.cpp
        source/ecs/Entity/Fire.cpp source/ecs/Entity/Fire.hpp source/ecs/Entity/RenderPlayer.cpp source/ecs/Entity/RenderPlayer.hpp)

target_link_libraries(rtype_client ${CONAN_LIBS})
set_target_properties(rtype_client PROPERTIES LINKER_LANGUAGE CXX)


