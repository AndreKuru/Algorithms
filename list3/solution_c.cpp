#include <stdio.h>
#include <queue>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    int numbers_amount, number = 0;
    scanf("%d%*c", &numbers_amount);
    while(numbers_amount != 0){
        std::priority_queue<int> numbers;
        std::string line;
        std::getline(std::cin, line);
        std::stringstream buf(line);

        while (buf >> number) {
            numbers.push(number);
        }

        int sum = 0;
        for (int i = 1; i < numbers_amount; i++){
            sum += numbers.top() * i;
            numbers.pop();
        }

        sum += numbers.top() * (numbers_amount - 1);

        printf("%d\n", sum);

        scanf("%d%*c", &numbers_amount);
    }

}