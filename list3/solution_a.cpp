#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

int main(){

    char word[55];
    scanf("%s", word);

    while(strcmp(word, "#")){
        if (std::next_permutation(word, word + strlen(word))){
            printf("%s\n", word);
        } else {
            printf("No Successor\n");
        }
        scanf("%s", word);
    }
}