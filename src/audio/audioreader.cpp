#include "audioreader.h"
#include <iostream>
#include <vector>

AudioReader::AudioReader(const char* path)
{
    file = sf_open(path, SFM_READ, &sfinfo);

    if (!file) {
        std::cerr << sf_strerror(nullptr) << std::endl;
    }
}

AudioReader::~AudioReader()
{
    if (file) {
        sf_close(file);
    }
}

void AudioReader::reader_output()
{
    if (!file) {
        std::cerr << "File not opened\n";
        return;
    }

    std::cout << "Sample Rate: " << sfinfo.samplerate << "\n";
    std::cout << "Channels: " << sfinfo.channels << "\n";
    std::cout << "Frames: " << sfinfo.frames << "\n";


    std::vector<double> samples(framesToRead * sfinfo.channels);

    sf_count_t framesRead = sf_readf_double(file, samples.data(), framesToRead);

    std::cout << "Frames read: " << framesRead << "\n";
    std::cout << "First sample: " << samples[0] << "\n";
}
