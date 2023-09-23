#include <iostream>
#include <vector>
#include <string>

void print_lines(std::vector<int> lines) {
    if (lines[0] > 0) {
        std::cout << "1 ";
        for (int i = 0; i < lines[0]; ++i) {
            std::cout << "*";
        }
        std::cout << " " << lines[0] << std::endl;
    }

    if (lines[1] > 0) {
        std::cout << "2 ";
        for (int i = 0; i < lines[1]; ++i) {
            std::cout << "*";
        }
        std::cout << " " << lines[1] << std::endl;
    }

    if (lines[2] > 0) {
        std::cout << "3 ";
        for (int i = 0; i < lines[2]; ++i) {
            std::cout << "*";
        }
        std::cout << " " << lines[2] << std::endl;
    }
}

void is_correct_cin(int line, int amount) {
    if (line == 0 && amount == 0) {}
    else if ((line < 1 || line > 3) || (amount < 1 || amount > 5)) {
        std::cout << "Неверный ввод, попробуйте снова\n";
    }
}

std::vector<int> player_input() {
    std::cout << "Make a move (write line number and amount of *)\n";
    
    int line = 0;
    int amount = 0;

    std::cin >> line >> amount;
    is_correct_cin(line, amount);
    std::vector<int> move = {line, amount};

    return move;
}

std::vector<int> make_move(std::vector<int> move, std::vector<int> lines) {
    int line = move[0] - 1;
    int amount = move[1];

    lines[line] -= amount;

    return lines;
}

bool is_ended(std::vector<int> lines) {
    if (lines[0] == 0 && lines[1] == 0 && lines[2] == 0) {
        return 1;
    } else return 0;
}

int main() {
    try {
        std::vector<int> lines = {3, 4, 5};
        std::vector<int> move(2);
        
        while (true) {
            print_lines(lines);
            move = player_input();

            if (move[0] == 0 && move[1] == 0) {
                std::cout << "Досрочный выход";
                break;
            }

            lines = make_move(move, lines);
            if (is_ended(lines)) {
                std::cout << "Кто-то победил";
                break;
            }
        }
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Какая-то неведомая ошибка";
        return 2;
    }
    return 0;
}