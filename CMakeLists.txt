cmake_minimum_required(VERSION 3.21.1)

project(impl LANGUAGES C CXX VERSION 4.5.6)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_library(${PROJECT_NAME} SHARED ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CMAKE_CXX_STANDARD 11)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
)

configure_file(include/${PROJECT_NAME}_config.h.in ${PROJECT_NAME}_config.h)

FetchContent_Declare(
    interfaces
    GIT_REPOSITORY "https://github.com/Radunasor/interfaces.git"
    GIT_TAG main
)
FetchContent_MakeAvailable(interfaces)
target_link_libraries(${PROJECT_NAME} PRIVATE interfaces)