project(picojson)

file(GLOB PICOJSON_HEADERS include/picojson.h)

add_library(picojson INTERFACE)

target_include_directories(picojson
    INTERFACE
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)