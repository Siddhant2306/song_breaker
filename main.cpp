#include <iostream>
#include <fftw3.h>

int main() {
    // --- Define size ---
    const int N = 8;

    // --- Input: real numbers ---
    double in[N] = {1, 2, 3, 4, 0, 0, 0, 0};

    // --- Output: complex numbers ---
    fftw_complex out[N/2 + 1];

    // --- Create FFT plan ---
    fftw_plan plan = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);

    // --- Execute FFT ---
    fftw_execute(plan);

    // --- Print results ---
    std::cout << "FFT Output:\n";
    for (int i = 0; i < N/2 + 1; ++i) {
        std::cout << "Index " << i << ": "
                  << out[i][0] << " + " << out[i][1] << "i\n";
    }

    // --- Cleanup ---
    fftw_destroy_plan(plan);

    return 0;
}
