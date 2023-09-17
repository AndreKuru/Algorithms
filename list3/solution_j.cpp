#include <stdio.h>
#include <map>
#include <set>

int main()
{
    int tests_amount, friends_amount, stamps_amount, stamp_id;

    scanf("%d", &tests_amount);
    for (int test = 0; test < tests_amount; test++) {
        std::map<int, std::set<int>> stamps_owneds;
        std::map<int, double> unique_owners;

        scanf("%d", &friends_amount);
        for (int friend_id = 0; friend_id < friends_amount; friend_id++) {

            scanf("%d", &stamps_amount);
            for (int stamp = 0; stamp < stamps_amount; stamp++) {
                scanf("%d", &stamp_id);
                stamps_owneds[stamp_id].insert(friend_id);
            }
        }
        auto total_of_uniques = 0;
        for (auto it = stamps_owneds.begin(); it != stamps_owneds.end(); it++) {
            if (it->second.size() == 1) {
                auto friend_id = *it->second.begin();
                unique_owners[friend_id]++;
                auto uniques = unique_owners[friend_id];
                total_of_uniques++;
            }
        }

        printf("Case %d:", test + 1);
        for (int friend_id = 0; friend_id < friends_amount; friend_id++) {
            auto percent = unique_owners[friend_id] / total_of_uniques * 100;
            printf(" %f%%", percent);
        }
        printf("\n");
    }
}