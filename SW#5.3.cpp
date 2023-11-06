#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <random>
#include <cmath>


int random(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);// конструкцмя для генирации рандомного числа
}

int** matrix(int rows, int cols) { //двумерная масив типа инт
    int** array = new int*[rows]; 
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = random(-100, 100);
        }
    }

    return array;
}

int firstStep(int x) {
    if (x < 0 && x % 2 == -1) {
        return x / 3;
    }
    return x;
}

double* findSmallestInColumns(int** matrix, int rows, int cols) {
    double* smallestInColumns = new double[cols];

    for (int j = 0; j < cols; ++j) {
        double smallest = DBL_MAX;
        for (int i = 0; i <= rows; ++i) {
            if (static_cast<double>(matrix[i][j]) < smallest) {
                smallest = static_cast<double>(matrix[i][j]);
            }
        }
        smallestInColumns[j] = smallest;
    }

    return smallestInColumns;
}

int main() {
    int n = 3;
    int m = 4;
    int** arr = matrix(n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    int** firstArr = arr;

    std::cout << "\nFirst step\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = firstStep(arr[i][j]);
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nSecond step\n";

    double* newArr = findSmallestInColumns(arr, n, m);

    std::cout << "\nSmallest element in each column:\n";

    for (int j = 0; j < n; ++j) {
        std::cout << "Column " << j << ": " << newArr[j] << "\n";
    }

    return 0;
}

















//std::cout << "\n";

//for (int i = 0; i < n; ++i) {
//    for (int j = 0; j < m + 1; ++j) {
//        arr[i][j] = firstStep(arr[i][j]);
//    }
//}

//std::cout << "first step" << std::endl;

//for (int i = 0; i < n; ++i) {
//    for (int j = 0; j < m + 1; ++j) {
//        std::cout << arr[i][j] << " ";
//    }
//}


































