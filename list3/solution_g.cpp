#include <stdio.h>
#include <vector>
#include <algorithm>

class Problem
{
    int correct_solution_time;
    std::vector<int> penalties;
    public:
        Problem();
        void add_penalty(int penalty){penalties.push_back(penalty);}
        void set_correct_solution_time(int new_time){
            if (correct_solution_time == -1) {
                correct_solution_time = new_time;
            }
        }
        int get_penalty(){
            if (correct_solution_time == -1){
                return -1;
            }

            int penalties_amount = 0;
            for (auto penalty : penalties){

                if (penalty < correct_solution_time){
                    penalties_amount++;
                }
            }

            return correct_solution_time + penalties_amount * 20;
        }
        bool is_solved(){return correct_solution_time > -1;}
};

Problem::Problem()
{
    correct_solution_time = -1;
}

class Contestant
{
        int id;
        Problem problems[10];
    public:
        Contestant(int);
        Problem get_problem(int problem_id){return problems[problem_id];}
        int get_id(){return id;}
        int get_final_penalty(){
            auto final_penalty = 0;
            for (auto problem : problems){
                final_penalty = std::max(final_penalty, problem.get_penalty());
            }

            return final_penalty;
        }
        int get_total_solved(){
            auto solveds_amount = 0;
            for (auto problem : problems){
                if (problem.is_solved()){
                    solveds_amount++;
                }
            }
            return solveds_amount;
        }
};

Contestant::Contestant(int i)
{
    id = i;
}

Contestant& find_contestant(std::vector<Contestant> contestants, int id)
{
    for (auto contestant:contestants){
        if (contestant.get_id() == id){
            return contestant;
        }
    }

    Contestant contestant(id);
    contestants.push_back(contestant);
    return contestant;
}

bool my_compare(Contestant a, Contestant b)
{
    if (a.get_total_solved() == b.get_total_solved()){
        if (a.get_final_penalty() == b.get_final_penalty()){
            return a.get_id() < b.get_id();
        }
        return a.get_final_penalty() < b.get_final_penalty();
    }
    return a.get_total_solved() < b.get_total_solved();
}

int main()
{
    int tests_amount;
    scanf("%d%*c", &tests_amount);

    std::vector<Contestant> contestants;
    int contestant_id, problem_id, problem_time;
    char problem_state;
    while(scanf("%d %d %d %c", &contestant_id, &problem_id, &problem_time, &problem_state) != EOF){
        auto contestant = find_contestant(contestants, contestant_id);      // TODO
        auto problem = contestant.get_problem(problem_id - 1);              // TODO
        
        if (problem_state == 'C'){
            problem.set_correct_solution_time(problem_time);
        } else if (problem_state == 'I') {
            problem.add_penalty(problem_time);
        }
    }

    std::sort(contestants.begin(), contestants.end(), my_compare);

    for (auto contestant : contestants){
        printf("%d %d %d\n", contestant.get_id(), contestant.get_total_solved(), contestant.get_final_penalty());
    }

    // Contestant Problems_solved penalty_acumulated
}