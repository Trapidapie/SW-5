#include <iostream>
#include <vector>


std::vector<std::vector<int>> createMatrix(int rows, int cols) {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter the value for matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    return matrix;
}

int main() {
    int numRows1, numCols1, numRows2, numCols2;
    std::cout << "row1: ";
    std::cin >> numRows1;
    std::cout << "column1: ";
    std::cin >> numCols1;
    std::cout << "row2: ";
    std::cin >> numRows2;
    std::cout << "column2: ";
    std::cin >> numCols2;

    if (numCols1 == numRows2) {
        std::vector<std::vector<int>> matrix1 = createMatrix(numRows1, numCols1);
        std::vector<std::vector<int>> matrix2 = createMatrix(numRows2, numCols2);

        std::vector<std::vector<int>> matrix(numRows1, std::vector<int>(numCols2));

        for (int i = 0; i < numRows1; ++i) {
            for (int j = 0; j < numCols2; ++j) {
                for (int k = 0; k < numCols1; k++) {
                    matrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }

        return 0;
    }
}