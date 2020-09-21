project(babel_client)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#include boost
find_package(Boost)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()

set(INCLUDE_DIR ../GlobalClasses/include)
include_directories(bomberman ${INCLUDE_DIR})


add_definitions("-fPIC")

#find qt_package
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Network CONFIG REQUIRED)
find_package(Qt5Core CONFIG REQUIRED)


#check plateform
if(CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif(CMAKE_HOST_APPLE)
    set(MACOS 1)
elseif(CMAKE_HOST_UNIX)
    set(LINUX 1)
endif()



add_executable(babel_client main.cpp sources/GraphicalUserInterface/Window/Window.cpp
        sources/GraphicalUserInterface/Window/Window.hpp sources/GraphicalUserInterface/LineEdit/LineEdit.cpp
        sources/GraphicalUserInterface/LineEdit/LineEdit.hpp sources/GraphicalUserInterface/Label/Label.cpp
        sources/GraphicalUserInterface/Label/Label.hpp sources/GraphicalUserInterface/PushButton/PushButton.cpp
        sources/GraphicalUserInterface/PushButton/PushButton.hpp sources/GraphicalUserInterface/List/List.hpp
        sources/GraphicalUserInterface/List/List.cpp sources/GraphicalUserInterface/ComboBox/ComboBox.hpp
        sources/GraphicalUserInterface/ComboBox/ComboBox.cpp
        sources/Core/Core.hpp sources/Core/Core.cpp
        sources/ClientServerCommunication/TCPclient.cpp sources/ClientServerCommunication/TCPclient.hpp
        ../GlobalClasses/Serializer/Serializer.cpp ../GlobalClasses/Serializer/Serializer.hpp
        ../GlobalClasses/Request/Request.cpp ../GlobalClasses/Request/Request.hpp
        ../GlobalClasses/Exceptions/Exceptions.cpp ../GlobalClasses/Exceptions/Exceptions.hpp
        assets/QTres.qrc
        sources/ClientClientCommunication/DecodeSound.cpp
        sources/ClientClientCommunication/DecodeSound.cpp

        sources/ClientClientCommunication/EncodeSound.cpp
        sources/ClientClientCommunication/EncodeSound.hpp

        sources/ClientClientCommunication/Eventcall.cpp
        sources/ClientClientCommunication/Eventcall.hpp
        sources/ClientClientCommunication/UDPclient.cpp
        sources/ClientClientCommunication/UDPclient.hpp
        sources/ClientClientCommunication/Voice.cpp sources/ClientClientCommunication/Voice.hpp)

target_link_libraries(babel_client ${Boost_LIBRARIES} ${CONAN_LIBS} Qt5::Widgets Qt5::Network)