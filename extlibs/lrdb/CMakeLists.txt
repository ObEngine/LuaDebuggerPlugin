project(lrdb)

file(GLOB LRDB_HEADERS include/lrdb/*.hpp include/lrdb/command_stream/*.hpp)
file(GLOB LRDB_SOURCES src/*.cpp)

add_library(lrdb SHARED ${LRDB_HEADERS} ${LRDB_SOURCES})

target_include_directories(lrdb
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/lrdb
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(lrdb lua)
target_link_libraries(lrdb picojson)
target_link_libraries(lrdb asio)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)