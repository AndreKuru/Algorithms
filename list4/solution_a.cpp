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

bool next_numerator(std::string& number_str){
    auto found = false;
    //auto it = std::prev(number_str.end());
    auto it = number_str.begin();
    for (auto i = 0; i < 6; ++i) {++it;}
    std::reverse(std::next(it), number_str.end());

    for (; it != number_str.begin(); --it) {
        if (*std::prev(it) < *it) {
            found = true;
            break;
        }
    }

    if (not found) {
        return false;
    }


    auto a = std::prev(it);
    auto b = it;
    ++it;
    for (; it != number_str.end(); ++it) {
        if (*it <= *b and *it > *a) {
            b = it;
        }
    }

    std::swap(*a, *b);
    std::reverse(std::next(a), number_str.end());
    return true;
}

int main()
{
    int expected_result;
    auto blank_line = false;
    scanf("%d%*c", &expected_result);
    while(expected_result != 0) {
        auto cont = 0;
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
            auto old_numerator = number_str.substr(0, 5);

            auto debug = false;
            auto old_denominator = number_str.substr(5);
            auto new_denominator = old_denominator;
            auto new_denominator_rev = new_denominator;
            if (debug){
                printf("****IN*****\n");
            }
            do {
                ++cont;
                auto numerator = number_str.substr(0, 5);
                auto denominator = number_str.substr(5);
                std::reverse(denominator.begin(), denominator.end());
                number_str = numerator + denominator;
                if (debug){
                    auto numerator = number_str.substr(0, 5);
                    new_denominator = number_str.substr(5);
                    new_denominator_rev = new_denominator;
                    std::reverse(new_denominator_rev.begin(), new_denominator_rev.end());
                    printf("%s %s|%s\n", numerator.c_str(), new_denominator.c_str(), new_denominator_rev.c_str());
                    is_new_number_str = next_numerator(number_str);
                }

                is_new_number_str = std::next_permutation(number_str.begin(), number_str.end());
            } while(old_numerator == number_str.substr(0, 5) and is_new_number_str); 
            if (debug){
                printf("****OUT****\n");
                auto is_reverse = old_denominator == new_denominator_rev;
                printf("%s => %s | %s\n", old_denominator.c_str(), new_denominator.c_str(), is_reverse ? "reverse" : "not");
            }
        }
        // printf("cont: %d\n", cont);

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