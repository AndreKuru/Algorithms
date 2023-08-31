#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <ctype.h>

int main()
{
    int numbers[10000];
    int number, i = 0;
    
    while(scanf("%d", &number) != EOF){
        numbers[i] = number;
        int numbers_size = sizeof(numbers)/sizeof(numbers[0]);
        int median, median_position = numbers_size / 2;
        if (i % 2 == 0){
            std::nth_element(numbers, numbers + median_position, numbers + numbers_size);
            std::nth_element(numbers, numbers + median_position + 1, numbers + numbers_size);
            auto middle_1 = numbers[median_position];
            auto middle_2 = numbers[median_position + 1];
            median = middle_1 / middle_2;
        } else{
            std::nth_element(numbers, numbers + median_position, numbers + numbers_size);
            median = numbers[median_position];
        }
        printf("%d\n", median);
    }
}