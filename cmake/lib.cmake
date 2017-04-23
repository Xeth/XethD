find_package(JsonCPP REQUIRED)
find_package(LevelDB REQUIRED)
find_package(CryptoPP REQUIRED) 

if(ENABLE_GMP)
    find_package(GMP)
endif()

add_definitions(-DBOOST_PP_VARIADICS)


if(ENABLE_GMP)
    if(GMP_LIBRARIES)
        add_definitions(-D__HAS_GMP__)
    endif()
endif()

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS "-fPIC")
endif()

file(GLOB_RECURSE LIBRARY_SOURCES
    "src/*.cpp"
)

file(GLOB_RECURSE MAIN_CPP "src/main.cpp")
list(REMOVE_ITEM LIBRARY_SOURCES ${MAIN_CPP})


add_library(xethdlib STATIC ${LIBRARY_SOURCES})
target_include_directories(
    xethdlib
    PUBLIC
    ${Boost_INCLUDE_DIRS}
    ${JSONCPP_INCLUDE_DIR}
    ${CRYPTOPP_INCLUDE_DIR}
    ${LEVELDB_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_BINARY_DIR}/libethrpc/include
    ${PROJECT_BINARY_DIR}/libethcrypto/include
    ${PROJECT_BINARY_DIR}/libbitprofile/include
    ${PROJECT_BINARY_DIR}/libethstealth/include
)

add_dependencies(xethdlib ethrpc)
add_dependencies(xethdlib ethcrypto)
add_dependencies(xethdlib ethstealth)
