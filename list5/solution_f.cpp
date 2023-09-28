#include <stdio.h>
#include <vector>

int main()
{
    int tests_amount;
    scanf("%d%*c", &tests_amount);
    for (auto test = 0; test <tests_amount; ++test) {
        int rungs_amount, rung;
        auto rungs_force_needed = std::vector<int> {};
        scanf("%d%*c", &rungs_amount);
        auto past_height = 0;
        for (auto i = 0; i < rungs_amount; ++i) {
            scanf("%d ", &rung);
            rungs_force_needed.push_back(rung - past_height);
            past_height = rung;
        }

        auto max_initial_force = *rungs_force_needed.begin();
        auto remaining_force = max_initial_force - 1;

        auto rung_force = std::next(rungs_force_needed.begin());

        for (; rung_force != rungs_force_needed.end(); ++rung_force) {
            if (*rung_force > max_initial_force) {
                max_initial_force = *rung_force;
                remaining_force = max_initial_force - 1;
            } else if (*rung_force > remaining_force) {
                ++max_initial_force;
                remaining_force = max_initial_force;
            } else if (*rung_force == remaining_force) {
                --remaining_force;
            }
        }

        printf("Case %d: %d\n", test + 1, max_initial_force);
    }
}