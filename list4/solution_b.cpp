#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

int get_distance(int a, int b, std::string arrangement)
{
    auto a_str = std::to_string(a);
    auto b_str = std::to_string(b);
    auto a_pos = arrangement.find(a_str);
    auto b_pos = arrangement.find(b_str);
    return abs(a_pos - b_pos);
}

bool check_arrangement(std::string arrangement, std::vector<std::tuple<int,int,int>>& constraints)
{
    for (auto constraint: constraints) {
        auto a = std::get<0>(constraint);
        auto b = std::get<1>(constraint);
        auto distance_limit = std::get<2>(constraint);

        if (distance_limit > 0) {
            if (distance_limit < get_distance(a, b, arrangement))
                return false;

        } else if (-distance_limit > get_distance(a, b, arrangement)) {
            return false;
        }
    }
    return true;
}

int main()
{
    int teens_amount, constraints_amount;
    scanf("%d %d%*c", &teens_amount, &constraints_amount); 
    while(not(teens_amount == 0 and constraints_amount == 0)) {
        auto constraints = std::vector<std::tuple<int,int,int>>{};
        for (auto constraint = 0; constraint < constraints_amount; ++constraint) {
            int student_a, student_b, seats_distance;
            scanf("%d %d %d%*c", &student_a, &student_b, &seats_distance);
            constraints.push_back(std::make_tuple(student_a, student_b, seats_distance));
        }

        auto arrangement = std::string("0");
        for (auto teen = 1; teen < teens_amount; ++teen) {
            arrangement += std::to_string(teen);
        }


        auto total_arrangements = 0;
        auto is_new_arrangement = true;
        while(is_new_arrangement) {
            if (check_arrangement(arrangement, constraints)) {
                ++total_arrangements;
            }
            is_new_arrangement = std::next_permutation(arrangement.begin(), arrangement.end());
        }

        printf("%d\n", total_arrangements);
        scanf("%d %d%*c", &teens_amount, &constraints_amount); 
    }
}