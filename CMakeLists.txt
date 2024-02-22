cmake_minimum_required(VERSION 3.0.0)
project(SFMLProject VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(SFML_DIR "/usr/lib/x86_64-linux-gnu/cmake/SFML")

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(SFMLProject ${SOURCES})

# Link SFML to your target
target_link_libraries(SFMLProject sfml-graphics sfml-audio)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)