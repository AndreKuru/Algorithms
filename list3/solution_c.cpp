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
        int cost = numbers.top();
        for (int i = 1; i < numbers_amount; i++){
            numbers.pop();
            cost = cost + numbers.top();
            sum += cost;
        }

        printf("%d\n", sum);

        scanf("%d%*c", &numbers_amount);
    }

}