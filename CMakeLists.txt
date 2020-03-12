cmake_minimum_required(VERSION 3.10.2)
project(portal)

# std c++11
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -Werror -pedantic")
# debugging flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -DDEBUG -fno-inline ")
# threads
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

#qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# CLIENT - SERVER - COMMON
file(GLOB_RECURSE COMMON_SRCS ./common/src/*.cpp)
file(GLOB_RECURSE CLIENT_SRCS ./client/src/*.cpp)
file(GLOB_RECURSE SERVER_SRCS ./server/src/*.cpp)
list(FILTER CLIENT_SRCS EXCLUDE REGEX "main.cpp")
list(FILTER SERVER_SRCS EXCLUDE REGEX "main.cpp")

# Including Box2D
include_directories(./libs/Box2D-master)
file(GLOB_RECURSE BOX2D_SRCS ./libs/Box2D-master/Box2D/*.cpp)

# Including SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(
    ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

#Including QT
find_package(Qt5 COMPONENTS REQUIRED Core Gui Widgets)
qt5_wrap_ui(ui_wrap ${EDITORUI})
qt5_wrap_cpp(moc_sources ${EDITOR_HEADERS})

#Including yaml
find_package(yaml-cpp REQUIRED)

# Libraries
add_library(libbox2d STATIC ${BOX2D_SRCS})
add_library(libcommon STATIC ${COMMON_SRCS})
add_library(libserver STATIC ${SERVER_SRCS})
add_library(libclient STATIC ${CLIENT_SRCS})
TARGET_LINK_LIBRARIES(libserver libcommon libbox2d yaml-cpp)
target_link_libraries(
    libclient libcommon avformat avcodec avutil swscale
    ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES}
    ${SDL2_TTF_LIBRARIES} Qt5::Core	Qt5::Gui Qt5::Widgets ${TIFF_LIBRARIES})

# Tiff
find_package(TIFF REQUIRED)
if (TIFF_FOUND)
    include_directories(${TIFF_INCLUDE_DIRS})
    target_link_libraries(libclient ${TIFF_LIBRARIES})
endif( TIFF_FOUND )

# Including CxxTest
file(GLOB_RECURSE TEST_CLIENT_HEADERS ./test/client/*.h)
file(GLOB_RECURSE TEST_SERVER_HEADERS ./test/server/*.h)
file(GLOB_RECURSE TEST_COMMON_HEADERS ./test/common/*.h)

find_package(CxxTest)
if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()
    CXXTEST_ADD_TEST(unittest-client runner-client.cpp ${TEST_CLIENT_HEADERS})
    TARGET_LINK_LIBRARIES(unittest-client libclient)

    CXXTEST_ADD_TEST(unittest-server runner-server.cpp ${TEST_SERVER_HEADERS} )
    TARGET_LINK_LIBRARIES(unittest-server libserver)

    CXXTEST_ADD_TEST(unittest-common runner-common.cpp ${TEST_COMMON_HEADERS})
    TARGET_LINK_LIBRARIES(unittest-common libcommon)
endif()

# Executables
add_executable(portal-client "client/src/main.cpp")
TARGET_LINK_LIBRARIES(portal-client libclient)

add_executable(portal-server "server/src/main.cpp")
TARGET_LINK_LIBRARIES(portal-server libserver)


# INSTALL
install(TARGETS portal-server portal-client libclient libserver libcommon libbox2d
        ARCHIVE DESTINATION "lib"
        RUNTIME DESTINATION "bin"
        INCLUDES DESTINATION "include")
install(DIRECTORY resources DESTINATION ".")
install(DIRECTORY maps DESTINATION ".")
install(DIRECTORY config DESTINATION ".")
install(DIRECTORY movies DESTINATION ".")
