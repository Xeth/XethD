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





