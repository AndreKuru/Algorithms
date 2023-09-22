#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>
#include <bitset>

int main()
{
    // Init
    int sum_expected, numbers_amount;
    while (scanf("%d %d ", &sum_expected, &numbers_amount) != EOF and numbers_amount > 0) {
        // Input
        auto numbers = std::vector<int>{};
        for (int i = 0; i < numbers_amount; ++i) {
            int number;
            scanf("%d ", &number);
            numbers.push_back(number);
        }
        printf("Sums of %d:\n", sum_expected);

        // Get solutions
        auto solutions = std::set<std::vector<int>> {};
        for (auto bmask = 1; bmask < 1 << numbers_amount; ++bmask) {
            auto solution = std::vector<int> {};
            auto sum = 0;
            for (auto i = 0; i < numbers_amount; ++i) {
                if (bmask & (1 << i)) {
                    solution.push_back(numbers.at(i));
                    sum += numbers.at(i);
                }

            }
            if (sum == sum_expected) {
                solutions.insert(solution);
            }
        }

        // Sort
        auto solutions_ordered = std::vector<std::vector<int>>(solutions.begin(), solutions.end());
        std::sort(solutions_ordered.rbegin(), solutions_ordered.rend());

        // Print
        for (auto& solution: solutions_ordered) {
            auto it = solution.begin();
            printf("%d", *it);
            for (it = std::next(solution.begin()); it !=  solution.end(); ++it) {
                printf("+%d", *it);
            }
            printf("\n");
        }

        if (solutions.empty()) {
            printf("NONE\n");
        }
    }
}