#include <stdio.h>
#include <vector>
#include <algorithm>

int main()
{
    int tests_amount;
    scanf("%d%*c", &tests_amount);

    for (auto test = 0; test < tests_amount; ++test) {
        int bars_length, bars_amount, bar;
        auto bars = std::vector<int> {};
        scanf("%d%*c", &bars_length);
        scanf("%d%*c", &bars_amount);
        for (auto i = 0; i < bars_amount; ++i) {
            scanf("%d%*c", &bar);
            bars.push_back(bar);
        }

        auto has_solution = false;
        auto bmask_limit = 1 << bars_amount;
        for (auto bmask = 0; bmask < bmask_limit; ++bmask) {
            auto selected_bars_sum = 0;
            for (auto i = 0; i < bars_amount; ++i) {
                if (bmask & (1 << i)) {
                    selected_bars_sum += bars.at(i);
                }
            }

            if (selected_bars_sum == bars_length) {
                has_solution = true;
                break;
            }
        }

        if (has_solution) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}