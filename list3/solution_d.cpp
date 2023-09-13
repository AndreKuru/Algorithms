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


        printf("Discarded cards: ");
        while(deck.size() > 2){
            printf("%d, ", deck.front());
            deck.pop();

            deck.push(deck.front());
            deck.pop();
        }
        printf("%d\n", deck.front());
        deck.pop();

        printf("Remaining card: %d\n", deck.front());
        scanf("%d", &n);
    }
}