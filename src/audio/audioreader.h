#pragma once
#include <sndfile.h>

class AudioReader {
public:
   static constexpr sf_count_t framesToRead = 1024;
    SF_INFO sfinfo{};
    SNDFILE* file{nullptr};

    AudioReader default();

    AudioReader(const char* path);
    ~AudioReader();

    void reader_output();

};
