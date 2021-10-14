project(asio)

file(GLOB ASIO_HEADERS include/asio.hpp)

add_library(asio INTERFACE)

target_include_directories(asio
    INTERFACE
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)