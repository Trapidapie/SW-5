#include <iostream>
#include <ostream>
#include <random>
#include <chrono>

int* randomArray(int len, int minValue, int maxValue) {
    int* array = new int[len];
    for (int i = 0; i < len; ++i) {
        array[i] = rand() % (maxValue - minValue + 1) + minValue;
    }
    return array;
}

int* linearSort(int arr[], int n) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration.count() << "ms"<< std::endl;
    return arr;
}



int main() {
    int n;
    std::cout << "n: ";
    std::cin >> n;
    int* arr = randomArray(n, -1000, 1000);

    std::cout << "Original Array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n" << std::endl;


    arr = linearSort(arr, n);
    std::cout << "Sorted Array by linearSort: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n" << std::endl;

    delete[] arr;
    return 0;
}