cmake_minimum_required(VERSION 3.20)
project(song_breaker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ================= FFTW =================
set(FFTW_ROOT "${CMAKE_SOURCE_DIR}/externals/fftw")

set(FFTW_INCLUDE_DIR "${FFTW_ROOT}/include")
set(FFTW_LIB_DIR     "${FFTW_ROOT}/lib")
set(FFTW_BIN_DIR     "${FFTW_ROOT}/bin")

# ================= libsndfile =================
set(SNDFILE_ROOT "${CMAKE_SOURCE_DIR}/externals/libsndfile")

set(SNDFILE_INCLUDE_DIR "${SNDFILE_ROOT}/include")
set(SNDFILE_LIB_DIR     "${SNDFILE_ROOT}/lib")
set(SNDFILE_BIN_DIR     "${SNDFILE_ROOT}/bin")

# ================= Executable =================
file(GLOB SOURCES
    src/audio/*.cpp
    src/*.cpp
)

# Create the executable
add_executable(song_breaker ${SOURCES})

# ================= Includes =================
target_include_directories(song_breaker PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${FFTW_INCLUDE_DIR}
    ${SNDFILE_INCLUDE_DIR}
)

# ================= Library paths =================
target_link_directories(song_breaker PRIVATE
    ${FFTW_LIB_DIR}
    ${SNDFILE_LIB_DIR}
)

# ================= Link libraries =================
target_link_libraries(song_breaker PRIVATE
    libfftw3-3
    sndfile
)

# ================= Copy DLLs =================
add_custom_command(TARGET song_breaker POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${FFTW_BIN_DIR}/libfftw3-3.dll"
        $<TARGET_FILE_DIR:song_breaker>

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SNDFILE_BIN_DIR}/sndfile.dll"
        $<TARGET_FILE_DIR:song_breaker>
)
