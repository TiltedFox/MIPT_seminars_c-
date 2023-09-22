#include <iostream>
#include <string>

using vchar = std::vector<char>;

void rules_of_game() {
    std::cout << "<<Bulls and Cows>>" << std::endl << "Computer sets a number of 4 unique digits" << std::endl
    << "Try to guess it" << std::endl << "Bull means you  got a correct digit on a correct position" << std::endl
    << "Cow means toy got a correct digit6 but on a wrong position" << std::endl << "Game is on" << std::endl;
}

void validate(const vchar& guess) {
    unsigned int counter = 0;
    for (unsigned int i = 0; i < guess.size(); ++i) {
        if (guess[i] < '0' || guess[i] > '9')
            throw std::runtime_error{"The number contains incorrect digits"};
        for (unsigned int k = 0; k < guess.size(); ++k) {
            if (guess[i] == guess[k])
            ++counter;
        }
        if (counter != 0)
            throw std::runtime_error("You have same numbers in your guess");
    }
}

vchar user_guess() {
    std::cout << "Write your guess: " << std::endl;
    vchar guess = {0, 0, 0, 0};
    char number = 0;
    for (unsigned int i = 0; i < guess.size(); ++i) {
        std::cin >> number;
        guess.push_back(number);
    }
    validate(guess);
    return guess;
}



int main() {
    try {
        rules_of_game();
        unsigned int cows = 0;
        unsigned int bulls = 0;

        std::srand(std::time(nullptr));
        vchar numbers = {0, 0, 0, 0};
        for (unsigned int i = 0; i < numbers.size(); ++i) {
            numbers.push_back(std::rand() % 10);
        }
        for (int i = 0; i < 4; ++i) {
            std::cout << numbers[i];
        }
        std::cout << '\n';

        vchar guess = user_guess();
        
        for (unsigned int i = 0; i < guess.size(); ++i) {
            for (unsigned int k = 0; numbers.size(); ++k) {
                if (guess[i] == numbers[k]) 
                    if (i == k) ++bulls;
                else ++cows;
            }
        }

    }
    catch (std::exception& a) {
        std::cerr << a.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Something went wrong";
        return 2;
    }
    return 0;
}