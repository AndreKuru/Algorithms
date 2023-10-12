#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

bool unique_chars_compare(std::pair<char,std::string>& pair0, std::pair<char,std::string>& pair1)
{
    return pair0.first < pair1.first;
}

bool search_code(std::vector<std::pair<char,std::string>>& unique_chars, std::string& encrypted_text, unsigned pos, std::vector<std::string>& solutions, std::string current_solution)
        
{
    for (auto unique_char: unique_chars) {
        if (encrypted_text.find(unique_char.second, pos) == pos)
            current_solution += unique_char.first;
            pos += unique_char.second.size();
            if (pos < encrypted_text.size()) {
                search_code(unique_chars, encrypted_text, pos, solutions, current_solution);
            } else {
                solutions.push_back(current_solution);
            }
    }

}

int main()
{
    int unique_chars_amount;
    scanf("%d%*c", &unique_chars_amount);
    while (unique_chars_amount > 0) {
        auto unique_chars = std::vector<std::pair<char,std::string>> {};
        for (auto i = 0; i < unique_chars_amount; ++i) {
            char c, code[105];
            scanf("%c %s ", &c, code);
            std::string code_str = code;
            auto unique_char = std::make_pair(c, code_str);
            unique_chars.push_back(unique_char);
        }

        std::sort(unique_chars.begin(), unique_chars.end(), unique_chars_compare);

        char text[105];
        scanf("%s ", text);
        std::string encrypted_text = text;


        scanf("%d%*c", &unique_chars_amount);
    }
}