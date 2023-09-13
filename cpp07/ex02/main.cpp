#include <iostream>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 10

int main(int, char**) {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    // Fill the Array and mirror with random values
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // Print the initial contents of the Array
    std::cout << "Initial Array: " << numbers << std::endl;

    // Test the copy constructor and assignment operator
    {
        Array<int> tmp = numbers;
        Array<int> test;
        test = tmp;

        // Modify tmp, it should not affect numbers or test
        tmp[0] = 999;
    }

    // Verify that numbers and mirror still match
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "Values don't match at index " << i << std::endl;
            return 1;
        }
    }

    // Print the modified contents of the Array
    std::cout << "Modified Array: " << numbers << std::endl;

    // Modify the Array with new random values
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }

    // Print the updated contents of the Array
    std::cout << "Updated Array: " << numbers << std::endl;

    // Test out-of-bounds exceptions
    try {
        int value = numbers[MAX_VAL]; // Should throw an exception
        std::cout << value << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    try {
        int value = numbers[-2]; // Should throw an exception
        std::cout << value << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    // Test resizing the Array
    numbers = Array<int>(5); // Resize to a smaller size
    std::cout << "Resized Array (smaller): " << numbers << std::endl;

    numbers = Array<int>(15); // Resize to a larger size
    std::cout << "Resized Array (larger): " << numbers << std::endl;

    delete[] mirror;
    return 0;
}
