#include <stdio.h>
#include <iostream>
#include <string>

int main() {
    auto line = std::string();
    std::getline(std::cin, line);
    while (line != ".") {
        for (decltype(line.size()) i = 1; i <= line.size(); ++i) {
            if (line.size() % i == 0) {
                auto str_reference = line.substr(0, i);
                auto is_reducible_to_reference = true;
                auto cont = 1;

                for (auto j = i; j + i <= line.size(); j += i) {
                    auto str = line.substr(j, i);

                    if (str_reference != str) {
                        is_reducible_to_reference = false;
                        break;
                    }
                    ++cont;
                }

                if (is_reducible_to_reference) {
                    printf("%d\n", cont);
                    break;
                }
            }
        }
        std::getline(std::cin, line);
    }
    
}