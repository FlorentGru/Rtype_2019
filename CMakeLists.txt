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
include_directories(server/includes client/includes)

add_executable(r-type_server
    server/sources/main.cpp
    server/includes/server.hpp
)
target_link_libraries(r-type_server ${CONAN_LIBS})

add_executable(r-type_client
    client/sources/main.cpp
    client/includes/client.hpp
)
target_link_libraries(r-type_client ${CONAN_LIBS})