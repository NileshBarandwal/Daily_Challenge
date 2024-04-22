#include <iostream>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void gnomeSort(int arr[], int size) {
    int index = 0;

    while (index < size) {
        if (index == 0 || arr[index - 1] <= arr[index]) {
            index++;
        } else {
            std::swap(arr[index], arr[index - 1]);
            printArray(arr, size);
            index--;
        }
    }
}

int main() {
    int size;
    //std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Declare the array with the given size
    int* arr = new int[size];  // Dynamic allocation

    // Ask for the elements of the array
    //std::cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    //std::cout << "Starting array:\n";
    printArray(arr, size);

    //std::cout << "Swapping sequence:\n";
    gnomeSort(arr, size);

    //std::cout << "Final sorted array:\n";
    //printArray(arr, size);

    // Clean up dynamically allocated memory
    delete[] arr;

    return 0;
}
