cmake_minimum_required(VERSION 3.21)

project(probed)

file(GLOB_RECURSE SAMPLE_PLUGIN_HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE SAMPLE_PLUGIN_SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(probed SHARED ${SAMPLE_PLUGIN_HEADERS} ${SAMPLE_PLUGIN_SOURCES})

target_include_directories(probed
    PRIVATE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

set(BUILD_PLAYER OFF CACHE BOOL "")
set(BUILD_DEV OFF CACHE BOOL "")
set(BUILD_TOOLKIT OFF CACHE BOOL "")
set(BUILD_TESTS OFF CACHE BOOL "")

add_subdirectory(ObEngine)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT probed)

target_link_libraries(probed ObEngineCore)

add_subdirectory(extlibs/picojson)
add_subdirectory(extlibs/asio)
add_subdirectory(extlibs/lrdb)

target_link_libraries(probed lua)
target_link_libraries(probed sol2)
target_link_libraries(probed lrdb)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)