cmake_minimum_required(VERSION 3.20)
project(song_breaker CXX) 

set(CMAKE_CXX_STANDARD 17)


set(FFTW_INCLUDE_DIR "C:/fftw-3.3.10/api")
set(FFTW_LIB_DIR "C:/fftw-3.3.10/build/Release")

include_directories(${FFTW_INCLUDE_DIR})

add_executable(song_breaker main.cpp) 


target_link_directories(song_breaker PRIVATE ${FFTW_LIB_DIR})
target_link_libraries(song_breaker PRIVATE fftw3.lib)

add_custom_command(TARGET song_breaker POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/fftw-3.3.10/build/Release/fftw3.dll"
        $<TARGET_FILE_DIR:song_breaker>)