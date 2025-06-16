#include <iostream>
#include <cstdlib>                                 // for rand() and RAND_MAX
#include <ctime>                                  // for time()

// Monte Carlo function to estimate Pi
double estimatePi(int totalPoints) {
    int insideCircle = 0;

    for (int i = 0; i < totalPoints; i++) {
        // Generate random x and y between 0 and 1
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;

        // Check if the point is inside the circle
        if (x * x + y * y <= 1.0) {
            insideCircle++;
        }
    }

                                                                      // Estimate Pi
    return 4.0 * insideCircle / totalPoints;

    
}

int main() {
    srand(time(0));                                          // Seed random number generator

    int samples[] = {100, 500,1030, 1400, 2480, 1000000};

    std::cout << "Monte Carlo Pi Estimation:\n";
    std::cout << "---------------------------\n";

    for (int i = 0; i < 5; i++) {
        int total = samples[i];
        double pi = estimatePi(total);
        std::cout << "Samples: " << total << " -> Estimated Pi: " << pi << "\n";
    }

    return 0;
}
