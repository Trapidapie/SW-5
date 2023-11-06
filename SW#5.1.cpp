#include <iomanip>
#include <iostream>
#include <vector>

std::vector<double> vectorNum() {
    std::vector<double> vector;

    while (true) {
        double x;
        std::cout << "Value (or any non-numeric input to exit): ";
        if (!(std::cin >> x)) {
            break;
        }
        vector.push_back(std::round(x * 100.0) / 100.0);
        //vector.push_back((x * 100.0) / 100.0);
    }
    return vector;
}

int main() {
    std::vector<double> result = vectorNum();

    if (result.empty()) {
        std::cout << "Vector is empty." << std::endl;
        return 0;
    }

    double maxNumber = *std::max_element(result.begin(), result.end());
    double minNumber = *std::min_element(result.begin(), result.end());

    std::cout << "Max: " << maxNumber << std::endl;
    std::cout << "Min: " << minNumber << std::endl;

    return 0;
}
