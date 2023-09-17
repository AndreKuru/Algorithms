#include <stdio.h>
#include <set>
#include <map>
#include <iterator>

int main() 
{
    int numbers_amount, test = 0;
    scanf("%d%*c", &numbers_amount);
    while(numbers_amount > 0) {
        ++test;
        printf("Case %d:\n", test);
        std::set<int> numbers;
        for (auto i = 0; i < numbers_amount; ++i) {
            int number;
            scanf("%d%*c", &number);
            numbers.insert(number);
        }

        std::set<int> sums;
        for (auto first_it = numbers.begin(); first_it != numbers.end(); ++first_it) {
            for (auto second_it = std::next(first_it); second_it != numbers.end(); ++second_it) {
                sums.insert(*first_it + *second_it);
            }
        }

        int querys_amount;
        scanf("%d%*c", &querys_amount);
        for (auto i = 0; i < querys_amount; ++i) {
            int query;
            scanf("%d%*c", &query);
            auto greater_or_equal = sums.lower_bound(query);
            auto lesser = std::prev(greater_or_equal);

            int sum;
            if (greater_or_equal == sums.end()) {
                sum = *lesser;
            } else if (lesser == sums.end()) {
                sum = *greater_or_equal;
            } else {
                if (std::abs(*greater_or_equal - query) <= std::abs(*lesser - query)) {
                    sum = *greater_or_equal;
                } else {
                    sum = *lesser;
                }
            }

            printf("Closest sum to %d is %d.\n", query, sum);
        }
        scanf("%d%*c", &numbers_amount);
    }
}