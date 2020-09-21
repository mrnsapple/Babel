project(babel_server)

#include boost
find_package(Boost)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()

add_definitions("-fPIC")

#find qt_package
find_package(Qt5Network CONFIG REQUIRED)


# set the include directory for header file
set(INCLUDE_DIR_CLIENT ../GlobalClasses/include)
include_directories(babel_server ${INCLUDE_DIR_CLIENT})

#check plateform
if(CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif(CMAKE_HOST_APPLE)
    set(MACOS 1)
elseif(CMAKE_HOST_UNIX)
    set(LINUX 1)
endif()

add_executable(babel_server main.cpp
        ${INCLUDE_DIR_CLIENT}/header.hpp
        classes/Database/Database.cpp classes/Database/Database.hpp
        ../GlobalClasses/Exceptions/Exceptions.cpp ../GlobalClasses/Exceptions/Exceptions.hpp
        classes/Server/Server.cpp classes/Server/Server.hpp
        classes/Session/Session.cpp classes/Session/Session.hpp
        ../GlobalClasses/Serializer/Serializer.cpp ../GlobalClasses/Serializer/Serializer.hpp
        ../GlobalClasses/Request/Request.cpp ../GlobalClasses/Request/Request.hpp
)

target_link_libraries(babel_server ${Boost_LIBRARIES} ${CONAN_LIBS}  Qt5::Network)