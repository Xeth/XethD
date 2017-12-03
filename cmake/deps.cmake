find_package(JsonCPP REQUIRED)
find_package(LevelDB REQUIRED)

if(ENABLE_GMP)
    find_package(GMP)
endif()

find_package(JsonCPP REQUIRED)
#set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system filesystem thread program_options random regex date_time chrono REQUIRED)
find_package(LevelDB REQUIRED)
find_package(GMP)


set(CMAKE_THREAD_PREFER_PTHREAD ON)
find_package(Threads REQUIRED)
