#include <stdio.h>
#include <queue>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    int numbers_amount, number = 0;
    scanf("%d%*c", &numbers_amount);
    while(numbers_amount != 0){
        std::priority_queue<int,std::vector<int>,std::greater<int>> numbers;
        std::string line;
        std::getline(std::cin, line);
        std::stringstream buf(line);

        while (buf >> number) {
            numbers.push(number);
        }

        int sum = 0;
        while (numbers.size() > 1) {
            auto first_min = numbers.top();
            numbers.pop();
            auto second_min = numbers.top();
            numbers.pop();
            auto cost = first_min + second_min;
            numbers.push(cost);
            sum += cost;
        }

        printf("%d\n", sum);

        scanf("%d%*c", &numbers_amount);
    }

}