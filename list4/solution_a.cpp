#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

std::string find_denominator(std::string numerator_str, int expected_result)
{
    auto numerator = std::stod(numerator_str);
    auto denominator_decimal = numerator / expected_result;
    auto denominator = int(denominator_decimal);
    if (denominator != denominator_decimal) {
        return std::string();
    }

    auto denominator_str = std::to_string(denominator);
    if (denominator_str.size() < 4) {
        return std::string();
    }
    if (denominator_str.size() < 5) {
        denominator_str = '0' +  denominator_str;
    }

    auto all_numerals = numerator_str + denominator_str;
    auto all_numerals_set = std::set<char> (all_numerals.begin(), all_numerals.end());

    if (all_numerals_set.size() == all_numerals.size()) {
        return denominator_str;
    }

    return std::string();
}

void try_num(std::string& number_str, int expected_result, std::vector<std::pair<std::string, std::string>>& answers)
{
    auto numerator = number_str.substr(0, 5);
    auto denominator = find_denominator(numerator, expected_result);

    if (denominator != std::string()) {
        auto answer = std::make_pair(numerator, denominator);
        answers.push_back(answer);
    }
}

int main()
{
    int expected_result;
    auto blank_line = false;
    scanf("%d%*c", &expected_result);
    while(expected_result != 0) {
        if (blank_line) {
            printf("\n");
        } else {
            blank_line = true;
        }

        auto number_str = std::string("0123456789");
        auto answers = std::vector<std::pair<std::string, std::string>>{};
        auto is_new_number_str = true;
        while(is_new_number_str) {
            try_num(number_str, expected_result, answers);

            auto numerator = number_str.substr(0, 5);
            auto denominator = number_str.substr(5);
            std::reverse(denominator.begin(), denominator.end());
            number_str = numerator + denominator;

            is_new_number_str = std::next_permutation(number_str.begin(), number_str.end());
        }

        if (answers.empty()) {
            printf("There are no solutions for %d.\n", expected_result);
        } else {
            for (auto answer : answers) {
                printf("%s / %s = %d\n", answer.first.c_str(), answer.second.c_str(), expected_result);
            }
        }
        
        scanf("%d%*c", &expected_result);
    }
}