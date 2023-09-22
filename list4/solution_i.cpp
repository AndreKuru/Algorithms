#include <stdio.h>
#include <algorithm>
#include <vector>

bool check_queen(std::vector<int> queens){
    // column is current queen selected
    auto selected_row = *queens.rbegin();
    // check
    auto i = 0;
    for (auto it = std::next(queens.rbegin()); it != queens.rend(); ++it) {
        ++i;
        //row
        if (*it == selected_row) {
            return false;
        }
        //diagonal up
        if (*it == selected_row + i) {
            return false;
        }
        // diagonal down
        if (*it == selected_row - i) {
            return false;
        }
    }

    return true;
}

void try_queen(std::vector<std::vector<int>>& solutions, std::vector<int> queens){
    queens.push_back(0);
    for (auto row = 0; row < 8; ++row) {
        queens.back() = row;
        if (check_queen(queens)) {
            if (queens.size() < 8) {
                try_queen(solutions, queens);
            } else {
                solutions.push_back(queens);
            }
        }

    }
}

int main()
{
    auto queens = std::vector<int> {};
    auto solutions = std::vector<std::vector<int>> {};
    try_queen(solutions, queens);

    queens = std::vector<int> {};
    int queen;
    auto test = 0;
    while (scanf("%d ", &queen) != EOF) {
        ++test;
        queens.push_back(queen - 1);
        for (auto i = 1; i < 8; ++i) {
            scanf("%d ", &queen);
            queens.push_back(queen - 1);
        }

        auto min_moves = 8;
        for (auto& solution: solutions) {
            auto it_reference = solution.begin();
            auto it = queens.begin();
            auto moves = 0;
            for (auto i = 0; i < 8; ++i) {
                if (*it_reference != *it) {
                    ++moves;
                }
                ++it_reference;
                ++it;
            }

            if (min_moves > moves) {
                min_moves = moves;
            }
        }

        printf("Case %d: %d\n", test, min_moves);
        queens = std::vector<int> {};
    }
}