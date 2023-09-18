#include <iostream>

int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int number_of_number = 0;
    std::cin >> number_of_number;
    std::cout << fibonacci(number_of_number);

    return 0;
}