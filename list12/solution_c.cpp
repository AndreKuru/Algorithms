#include <stdio.h>
#include <string>

int main() {
    unsigned a, b;
    char op; 
    auto c = std::string();
    auto correct_answers = 0;

    printf("TESTE\n");
    while (scanf("%u%c%u=%c", &a, &op, &b, &c) != EOF) {
        printf("TESTE\n");
        printf("%c\n", c.c_str());
        printf("%zu\n", c.size());
        if (c.at(0) == '?') {
            continue;
        }
        printf("TESTE\n");
        auto correct_c = 0u;
        if (op == '+') {
            correct_c = a + b;
        } else {
            correct_c = a - b;
        }

        printf("%c\n", c.c_str());
        if (correct_c == std::stoi(c)) {
            ++correct_answers;
        }
    }

    printf("%d\n", &correct_answers);
}