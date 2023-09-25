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

bool is_correct_cin(int line, int amount, std::vector<int> lines) {
    if (line == 0 && amount == 0)
        return 1;

    if (line < 0 || line > 3) {              //Проверка на номер строки
        return 0;
    }
    else if (lines[line - 1] == 0) {         //Проверка на наличие звезд в строке
        return 0;
    }
    else if (amount < 1) {                   //Проверка на положительно число звезд
        return 0;
    }
    else if (lines[line - 1] < amount) {     //Проверка на количество звезд в строке
        return 0;
    }
    else return 1;
}

std::vector<int> player_input(std::vector<int> lines) {
    std::cout << "Ваш ход. Напишите номер строки и колчиство *\n";
    
    int line = 0;
    int amount = 0;
    std::vector<int> move = {0, 1};

    std::cin >> line >> amount;

    if (is_correct_cin(line, amount, lines)) {
        move = {line, amount};
    } else {
        std::cout << "Неправильный ввод данных, попробуйте снова. \n";
        return {-1, -1};
    }
    std::cout << "--------------------------------------------\n";

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

bool nim_sum(std::vector<int> lines) {
    int s = 0;
    for (int amount : lines) {
        s ^= amount;
    }

    if (s == 0)
        return 1;
    
    return 0;
}

std::vector<int> bot_input(std::vector<int> lines) {
    std::vector<int> old_lines = lines;

    for (int i = 0; i < lines.size(); ++i) {

        for (int amount = lines[i]; amount > 0; amount--) {
            lines[i] -= 1;
            if  (nim_sum(lines)) {
                return lines;
            }
        }
        lines = old_lines;
    }

    lines = old_lines;
    for (int i = 0; i < lines.size(); ++i) {

        if (lines[i] > 0) {
            lines[i] -= 1;
            return lines;
        }
    }
    return {0,0};
}

int main() {
    try {
        std::vector<int> lines = {3, 4, 5};
        std::vector<int> move = {-1, 0};
        int whose_turn = 1;

        while (true) {
            print_lines(lines);
            

            while (whose_turn == 1) {
                move = player_input(lines);              //Ход человека
                
                if (move[0] == 0 && move[1] == 0) {      //Проверка на досрочный выход
                    std::cout << "Досрочный выход";
                    whose_turn = 2;
                    break;
                } else if (move[0] == -1 && move[1] == -1) {}
                else { 
                    lines = make_move(move, lines);
                    whose_turn = 0;
                }
            }

            if (whose_turn == 2) {
                break;
            }
            if (is_ended(lines)) {                   //Проверка на победу 
                std::cout << "Вы победили!";
                break;
            }

            lines = bot_input(lines);
            whose_turn = 1;

            if (is_ended(lines)) {                   //Проверка на победу 
                std::cout << "Вы проиграли";
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