#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <exception>

void unstack_coach(std::queue<int> &expected_coaches, std::stack<int> &station)
{
        if (station.empty() or
            station.top() != expected_coaches.front()){
            throw std::invalid_argument("Mismatch between expected coach and station");
        }

        station.pop();
        expected_coaches.pop();
}

void check_train(int train_size, std::queue<int> expected_coaches)
{
    std::stack<int> station;
    for(int incoming_coach = 1; incoming_coach <= train_size; incoming_coach++){
        if (incoming_coach < expected_coaches.front()){
            station.push(incoming_coach);
        } else {

            // While next coach must already arrived search in the station
            while (incoming_coach > expected_coaches.front()){
                unstack_coach(expected_coaches, station);
            }
            expected_coaches.pop();
        }
    }

    // Unstack all coaches
    while(not expected_coaches.empty()){
        unstack_coach(expected_coaches, station);
    }
}

int main()
{
    auto blank_line = false;
    int train_size;
    scanf("%d%*c", &train_size);
    while(train_size > 0){
        if (blank_line){
            printf("\n");
        } else {
            blank_line = true;
        }

        while(true){
            std::string line;
            std::getline(std::cin, line);
            std::stringstream buf(line);

            int coach;
            std::queue<int> expected_coaches;
            while(buf >> coach){
                expected_coaches.push(coach);
            }

            if (expected_coaches.front() == 0){
                break;
            }

            try{
                check_train(train_size, expected_coaches);
                printf("Yes\n");
            } catch (const std::invalid_argument& e){
                printf("No\n");
            }
        }
        scanf("%d%*c", &train_size);
    }
}