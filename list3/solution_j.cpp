#include <stdio.h>
#include <map>
#include <set>

int main()
{
    int tests_amount, friends_amount, stamps_amount;
    std::map<int, std::set<int>> stamps_owneds;

    scanf("%d", &tests_amount);
    for (int test = 0; test < tests_amount; test++) {

        scanf("%d", &friends_amount);
        for (int friend_id = 0; friend_id < friends_amount; friend_id++) {

            scanf("%d", &stamps_amount);
            for (int stamp = 0; stamp < stamps_amount; stamp++) {
                if (stamps_owneds.find(stamp) == stamps_owneds.end()) {
                    stamps_owneds[stamp].insert(friend_id);
                } else {
                    std::set<int> friends_owners;
                    friends_owners.insert(friend_id);
                    stamps_owneds[stamp] = friends_owners;
                }
            }
        }
    }
}