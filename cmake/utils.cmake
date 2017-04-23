find_package(JsonCPP REQUIRED)
find_package(Boost COMPONENTS system filesystem thread program_options random regex date_time chrono REQUIRED)
find_package(LevelDB REQUIRED)
find_package(GMP)
set(CMAKE_THREAD_PREFER_PTHREAD ON)
find_package(Threads REQUIRED)


add_executable(dumpdb ${PROJECT_SOURCE_DIR}/utils/dumpdb.cpp)
target_include_directories(dumpdb PUBLIC ${UTILS_INCLUDES})
target_link_libraries(dumpdb 
    xethlib
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
    target_link_libraries(dumpdb ${GMP_LIBRARIES})
endif()





