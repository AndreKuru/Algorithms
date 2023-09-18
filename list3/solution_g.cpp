#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

class Problem
{
    public:
        int correct_solution_time;
        int penalties;
        Problem();

        void add_penalty()
        {
            if (correct_solution_time < 0) {
                ++this->penalties;
            }
        }
        void set_correct_solution_time(int first_correct_solution){
            if (correct_solution_time == -1) {
                this->correct_solution_time = first_correct_solution;
            }
        }
        int get_penalty(){
            if (correct_solution_time == -1){
                return 0;
            }
            return correct_solution_time + penalties * 20;
        }
        bool is_solved(){return correct_solution_time > -1;}
};

Problem::Problem():
    correct_solution_time{-1},
    penalties{0}
    {}

class Contestant
{
    int id;
    public:
        Problem problems[9];
        Contestant() = default;
        Contestant(int i):
            id{i}
        {}

        int get_id()
        {
            return id;
        }

        int get_final_time()
        {
            auto final_time = 0;
            for (auto& problem : problems){
                final_time += problem.get_penalty();
            }

            return final_time;
        }

        int get_total_solved(){
            auto solveds_amount = 0;
            for (auto& problem : problems){
                if (problem.is_solved()){
                    solveds_amount++;
                }
            }
            return solveds_amount;
        }
};


Contestant& find_contestant(std::vector<Contestant>& contestants, int id)
{
    for (auto& contestant:contestants){
        if (contestant.get_id() == id){
            return contestant;
        }
    }

    Contestant contestant(id);
    contestants.push_back(contestant);
    return contestants.back();
}

bool my_compare(Contestant& a, Contestant& b)
{
    if (a.get_total_solved() == b.get_total_solved()){
        if (a.get_final_time() == b.get_final_time()){
            return a.get_id() < b.get_id();
        }
        return a.get_final_time() < b.get_final_time();
    }
    return a.get_total_solved() > b.get_total_solved();
}

int main()
{
    int tests_amount;
    scanf("%d%*c", &tests_amount);

    auto blank_line = false;
    for (auto test = 0; test < tests_amount; ++test) {
        std::vector<Contestant> contestants;
        int contestant_id, problem_id, problem_time;
        char problem_state;
        auto buffer = std::string();

        if (blank_line) {
            printf("\n");
        } else {
            blank_line = true;
            std::getline(std::cin, buffer);
        }
        while(std::getline(std::cin, buffer) && not buffer.empty()){
            auto sstr = std::stringstream(buffer);
            sstr >> contestant_id;
            sstr >> problem_id;
            sstr >> problem_time;
            sstr >> problem_state;

            auto& contestant = find_contestant(contestants, contestant_id);

            if (problem_state == 'C'){
                contestant.problems[problem_id - 1].set_correct_solution_time(problem_time);
            } else if (problem_state == 'I') {
                contestant.problems[problem_id - 1].add_penalty();
            }
        }
        std::sort(contestants.begin(), contestants.end(), my_compare);

        for (auto& contestant : contestants){
            printf("%d %d %d\n", contestant.get_id(), contestant.get_total_solved(), contestant.get_final_time());
        }
    }

}