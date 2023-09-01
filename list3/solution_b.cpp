#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <ctype.h>

int main()
{
    int numbers[10000];
    int number, last = 0;
    
    while(scanf("%d", &number) != EOF){
        numbers[last] = number;
        // int numbers_size = sizeof(numbers)/sizeof(numbers[0]);
        int median, median_position = last / 2;
        std::nth_element(numbers, numbers + median_position, numbers + last + 1);
        if (last % 2 == 1){
            std::nth_element(numbers, numbers + median_position + 1, numbers + last + 1);
            auto middle_1 = numbers[median_position];
            auto middle_2 = numbers[median_position + 1];
            median = (middle_1 + middle_2) / 2;
        } else{
            median = numbers[median_position];
        }
        printf("%d\n", median);
        last++;
    }
}