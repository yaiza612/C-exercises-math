#include <iostream>
#include <random>

int main() {
    std::random_device rd; // Seed generator
    std::mt19937 gen(rd()); // Use Mersenne Twister engine
    std::uniform_real_distribution<double> dis(0.0, 1.0); // Distribution between 0 and 1

    std::cout << "Generating 10 random numbers between 0 and 1:" << std::endl;

    for (int i = 0; i < 10; ++i) {
        // Generate a random number between 0 and 1
        double random_number = dis(gen);
        std::cout << random_number << std::endl;
    }

    return 0;
}