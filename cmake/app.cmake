find_package(JsonCPP REQUIRED)
#set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system filesystem thread program_options random regex date_time chrono REQUIRED)
find_package(LevelDB REQUIRED)
find_package(GMP)


set(CMAKE_THREAD_PREFER_PTHREAD ON)
find_package(Threads REQUIRED)


set(APP_SOURCES src/main.cpp)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}")


add_executable(xethd ${APP_SOURCES})
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a;.la;.lib;.so;.dll")


target_include_directories(
    xethd
    PUBLIC
    ${Boost_INCLUDE_DIRS}
    ${JSONCPP_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_BINARY_DIR}/libethrpc/include
    ${PROJECT_BINARY_DIR}/libethcrypto/include
    ${PROJECT_BINARY_DIR}/libethstealth/include
)

target_link_libraries(xethd
    xethdlib
    ethstealth
    bitprofile
    ethrpc
    ethcrypto
    ${JSONCPP_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_THREAD_LIBRARY}
    ${Boost_PROGRAM_OPTIONS_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_RANDOM_LIBRARY}
    ${Boost_REGEX_LIBRARY}
    ${Boost_DATE_TIME_LIBRARY}
    ${Boost_CHRONO_LIBRARY}
    ${CRYPTOPP_LIBRARY}
    ${LEVELDB_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT} 
)


if(GMP_LIBRARIES)
    target_link_libraries(xethd ${GMP_LIBRARIES})
endif()


