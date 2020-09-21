cmake_minimum_required(VERSION 3.7.2)

project(Babel)

if(CMAKE_HOST_WIN32)
    macro(get_WIN32_WINNT version)
        if (WIN32 AND CMAKE_SYSTEM_VERSION)
            set(ver ${CMAKE_SYSTEM_VERSION})
            string(REPLACE "." "" ver ${ver})
            string(REGEX REPLACE "([0-9])" "0\\1" ver ${ver})

            set(${version} "0x${ver}")
        endif()
    endmacro()

    get_WIN32_WINNT(ver)
    add_definitions(-D_WIN32_WINNT=${ver})
endif()


set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()


add_subdirectory(client)
add_subdirectory(server)