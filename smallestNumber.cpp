// Copyright (c) 2021 Luke Beausoleil All rights reserved
//
// Created by: Luke Beausoleil
// Created on: June 2021
// This program finds the average of ten random numbers

#include <iostream>
#include <random>
#include <array>

template<size_t N>
int MinOfNumbers(std::array<int, N> numbers) {
    // this function finds the greatest number among the list
    int tempMin = numbers[0];

    for (int loopCounter : numbers) {
        if (loopCounter <= tempMin) {
            tempMin = loopCounter;
        }
    }

    return tempMin;
}

int main() {
    // this function generates random numbers and calls another function

    // declaration
    std::array<int, 10> numbers;  // array
    int singleNumber;  // variable

    // process -- generate random numbers
    std::cout << "The numbers are [ ";  // output
    for (int loopCounter = 0; loopCounter < 10; loopCounter++) {
        std::random_device rseed;
        std::mt19937 rgen(rseed());  // mersenne_twister
        std::uniform_int_distribution<int> idist(1, 100);  // [1,100]
        singleNumber = idist(rgen);
        numbers[loopCounter] = singleNumber;
        std::cout << singleNumber << " ";  // output
    }
    std::cout << "]" << std::endl;  // output

    // output
    int min = MinOfNumbers(numbers);
    std::cout << "The smallest number is " << min << "\nDone." << std::endl;
}
