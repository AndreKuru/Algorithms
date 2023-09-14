#include <stdio.h>
#include <map>
#include <set>

int main()
{
    int froshs_amount, most_popular;
    scanf("%d ", &froshs_amount);
    while(froshs_amount > 0) {
        most_popular = 0;
        std::map<std::set<int>, int> popularity;
        for (int frosh = 0; frosh < froshs_amount; frosh++) {
            std::set<int> courses_combination;

            int course;
            for (int i = 0; i < 5; i++) {
                scanf("%d ", &course);
                courses_combination.insert(course);
            }
            popularity[courses_combination]++;

            if (most_popular < popularity[courses_combination]) {
                most_popular = popularity[courses_combination];
            }
        }

        auto froshs_popular = 0;
        for (auto it = popularity.begin(); it != popularity.end(); it++) {
            if (it->second == most_popular) {
                froshs_popular += most_popular;
            }
        }

        printf("%d\n", froshs_popular);

        scanf("%d ", &froshs_amount);
    }
}