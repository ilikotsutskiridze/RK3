cmake_minimum_required(VERSION 3.4)

include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.251.tar.gz"
        SHA1 "5659b15dc0884d4b03dbd95710e6a1fa0fc3258d"
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)

project(revert_string)
set(REVERT_STRING_VERSION_MAJOR 0)
set(REVERT_STRING_string_VERSION_MINOR 1)
set(REVERT_STRING_VERSION_PATCH 0)
set(REVERT_STRING_VERSION_TWEAK 0)
set(REVERT_STRING_VERSION
        ${REVERT_STRING_VERSION_MAJOR}.${REVERT_STRING_VERSION_MINOR}.${REVERT_STRING_VERSION_PATCH}.${REVERT_STRING_VERSION_TWEAK})
set(REVERT_STRING_VERSION_STRING "v${REVERT_STRING_VERSION}")

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_library(revert_string STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/revert_string.cpp)

target_include_directories(revert_string PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

if(BUILD_EXAMPLES)
    file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
    foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
        get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
        add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
        target_link_libraries(${EXAMPLE_NAME} revert_string)
        install(TARGETS ${EXAMPLE_NAME}
                RUNTIME DESTINATION bin
                )
    endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
endif()

add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/examples/demo.cpp)
target_link_libraries(demo revert_string)
install(TARGETS demo RUNTIME DESTINATION bin)

install(TARGETS revert_string
        EXPORT revert_string-config
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT revert_string-config DESTINATION cmake)

if(BUILD_TESTS)
    enable_testing()
    file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
    add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
    target_link_libraries(check ${PROJECT_NAME} GTest::gtest_main)
    add_test(NAME check COMMAND check)
endif()

include(CPackConfig.cmake)