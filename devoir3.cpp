#include <iostream>
#include <stdexcept>
#include <vector>

template <typename... Args>
void testFunction(Args... args) {
    std::cout << "Number of parameters: " << sizeof...(args) << std::endl;
    ((std::cout << args << " "), ...);  // Fold expression to print all arguments
    std::cout << std::endl;
}

int main() {
    try {
        // Testing with increasing numbers of parameters
        for (size_t i = 0; i < 10000; ++i) {
            // Create a vector to hold parameters
            std::vector<int> params(i);
            for (size_t j = 0; j < i; ++j) {
                params[j] = j;  // Fill with values
            }

            // Call the function using a variadic template
            // Using a trick to unpack the vector elements
            std::cout << "Calling with " << i << " parameters." << std::endl;
            if (i > 0) {
                // This uses a fold expression for variadic templates
                // Use an array reference to unpack parameters
                testFunction(params[0], params[1], params[2], params[3], params[4]); // Up to 5 for demonstration
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error occurred: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error occurred." << std::endl;
    }
    return 0;
}
