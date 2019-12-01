cmake_minimum_required(VERSION 3.1.0)
project(R-type VERSION 0.1.0)

if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")
    endif ()
else ()
    if(MSVC)
        set (CMAKE_CXX_STANDARD 17)
    else()
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")
    endif()
endif ()

#compilation flags
if(MSVC)
    # Force to always compile with W4
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")
endif()


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
        source/ecs/ClientEcs.cpp
        source/ecs/ServerEcs.cpp
        source/server/GameEngine.cpp
        source/ecs/Component/Acceleration.cpp
        source/ecs/Component/Vector.cpp
        source/ecs/Component/Position.cpp
        source/ecs/Component/Rendering.cpp
        source/ecs/Component/Timer.cpp
        source/ecs/Component/Velocity.cpp
        source/ecs/Entity/Server/Player.cpp
        source/ecs/System/UpdateEntitySystem.cpp
        source/ecs/Entity/Server/Fire.cpp
        source/ecs/Entity/SerializedEntity.cpp
        source/network/PacketManager.cpp
        source/network/RawData.cpp
        source/network/BoostUdpServer.cpp
        source/ecs/Component/Hitbox.cpp
        source/ecs/System/CollideSystem.cpp
        source/ecs/Entity/Server/Enemy.cpp source/ecs/Entity/Server/Enemy.hpp)

target_link_libraries(r-type_server ${CONAN_LIBS} ${CMAKE_DL_LIBS})
set_target_properties(r-type_server PROPERTIES LINKER_LANGUAGE CXX)

add_executable(r-type_client
        source/client/main.cpp
        source/client/Client.cpp
        source/ecs/AbstractEcs.cpp
        source/ecs/Component/Acceleration.cpp
        source/ecs/Component/Vector.cpp
        source/ecs/Component/Position.cpp
        source/ecs/Component/Rendering.cpp
        source/ecs/Component/Timer.cpp
        source/ecs/Component/Velocity.cpp
        source/ecs/System/Events.cpp
        source/ecs/ClientEcs.cpp
        source/ecs/System/IRenderSystem.hpp
        source/client/ClientEngine.cpp
        source/ecs/Entity/Client/RenderPlayer.cpp
        source/ecs/Entity/Client/RenderFire.cpp
        source/ecs/Entity/SerializedEntity.cpp
        source/network/PacketManager.cpp
        source/client/ClientNetwork.cpp
        source/network/BoostUdpClient.cpp
        source/network/RawData.cpp
        source/ecs/System/DrawEntitySystem.cpp
        source/ecs/Entity/Client/RenderEnemy.cpp
        )

target_link_libraries(r-type_client ${CONAN_LIBS})
set_target_properties(r-type_client PROPERTIES LINKER_LANGUAGE CXX)
