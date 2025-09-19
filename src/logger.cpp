#include "logger.h"
#include <iostream>
#include <limits>

// Add a reading; throw "Full" if array is full
void addReading(const std::string& label, double value,
                std::string labels[], double values[],
                int& size, int capacity) {
    if (size >= capacity) {
        throw std::string("Full");
    }
    labels[size] = label;
    values[size] = value;
    ++size;
}

// Update a value via pointer
void updateValue(double* valuePtr, double newValue) {
    if (valuePtr != nullptr) {
        *valuePtr = newValue;
    }
}

// Print a single reading
void printReading(const std::string& label, const double& value) {
    std::cout << label << ": " << value << std::endl;
}

// Compute average; throw "Empty" if no values
double average(const double values[], int size) {
    if (size == 0) throw std::string("Empty");
    double sum = 0.0;
    for (int i = 0; i < size; ++i) sum += values[i];
    return sum / size;
}

// Find minimum; throw "Empty" if no values
double minValue(const double values[], int size) {
    if (size == 0) throw std::string("Empty");
    double minVal = values[0];
    for (int i = 1; i < size; ++i) {
        if (values[i] < minVal) minVal = values[i];
    }
    return minVal;
}

// Find maximum; throw "Empty" if no values
double maxValue(const double values[], int size) {
    if (size == 0) throw std::string("Empty");
    double maxVal = values[0];
    for (int i = 1; i < size; ++i) {
        if (values[i] > maxVal) maxVal = values[i];
    }
    return maxVal;
}
