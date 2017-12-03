file(GLOB_RECURSE TEST_SOURCES
    "test/*.cpp"
)

GENERATE_QT_TEST_MAIN(${PROJECT_BINARY_DIR}/test/main.cpp ${PROJECT_SOURCE_DIR}/test/case)

add_definitions(-DBOOST_PP_VARIADICS)
file(COPY ${PROJECT_SOURCE_DIR}/test/data DESTINATION ${PROJECT_BINARY_DIR})

add_executable(xeth-tests EXCLUDE_FROM_ALL ${TEST_SOURCES} ${PROJECT_BINARY_DIR}/test/main.cpp)

target_include_directories(
    xeth-tests
    PUBLIC
    ${Boost_INCLUDE_DIRS}
    ${JSONCPP_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/test
    ${PROJECT_BINARY_DIR}/libethrpc/include
    ${PROJECT_BINARY_DIR}/libethcrypto/include
    ${PROJECT_BINARY_DIR}/libethstealth/include
)


target_link_libraries(xeth-tests
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
    ${LEVELDB_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)

if(GMP_LIBRARIES)
    target_link_libraries(xeth-tests ${GMP_LIBRARIES})
endif()

