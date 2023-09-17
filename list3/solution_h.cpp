#include <stdio.h>
#include <set>

int main()
{
    int days_amount;
    scanf("%d%*c", &days_amount);
    while(days_amount > 0) {
        std::multiset<int> urn;
        long int promotion_cost = 0;
        for(auto day = 0; day < days_amount; day++) {
            int bills_amount;
            scanf("%d%*c", &bills_amount);
            for(auto bill = 0; bill < bills_amount; bill++) {
                long bill_price;
                scanf("%ld%*c", &bill_price);
                urn.insert(bill_price);
            }

            auto min = urn.begin();
            auto max = std::prev(urn.end());

            urn.erase(min);
            urn.erase(max);
            promotion_cost += *max - *min;
        }
        printf("%ld\n", promotion_cost);
        scanf("%d%*c", &days_amount);
    }
}