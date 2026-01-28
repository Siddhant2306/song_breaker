#include <iostream>
#include "audio/audioreader.h"
#include <fftw3.h>
#include <vector>


int main()
{
    std::vector<double> samples(AudioReader::framesToRead);
    fftw_complex out[AudioReader::framesToRead];

    for(int i = 0 ; i < samples.size(); i++)
    {
        
    }

}