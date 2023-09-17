#include <stdio.h>
#include <queue>

int main()
{
    int n;
    scanf("%d", &n);

    while(n > 0){
        std::queue<int> deck;
        for (int i = 1; i <= n ; i++){
            deck.push(i);
        }


        printf("Discarded cards:");
        auto first_case = true;
        while(deck.size() >= 2){
            if (not first_case) {
                printf(", %d", deck.front());
            } else {
                first_case = false;
                printf(" %d", deck.front());
            }
            deck.pop();

            deck.push(deck.front());
            deck.pop();
        }
        printf("\n");

        printf("Remaining card: %d\n", deck.front());
        scanf("%d", &n);
    }
}