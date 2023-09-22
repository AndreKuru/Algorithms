#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>
#include <bitset>

//void find_solutions(std::set<std::vector<int>>& solutions, std::bitset<12> bm, std::vector<bool> bmask_vector, int bmask, int numbers_amount, std::vector<int>& numbers, int sum_expected)
void find_solutions(std::set<std::vector<int>>& solutions, int bmask, int numbers_amount, std::vector<int>& numbers, int sum_expected)
{
    auto solution = std::vector<int> {};
    auto sum = 0;
    for (auto i = 0; i < numbers_amount; ++i) {
        if (bmask & (1 << i)) {
            solution.push_back(numbers.at(i));
            sum += numbers.at(i);
        }

    }
    if (sum == sum_expected) {
        auto solutions_amount = solutions.size();
        solutions.insert(solution);

        //if (solutions_amount != solutions.size()) {
    }
}

template<std::size_t N>
void reverse_bitset(std::bitset<N>& b, int size = N) {
    for(std::size_t i = 0; i < size/2; ++i) {
        bool t = b[i];
        b[i] = b[size-i-1];
        b[size-i-1] = t;
    }
}

// N aceita conjunto vazio
bool next_subset(std::bitset<12>& bmask, int size)
{

    // Procura primeiro 1
    for (auto i = 0; i < size; i++) {
        if (bmask[i] == 1) {
            // Procura o primeiro 0
            for (auto j = i + 1; j < size; j++) {
                if (bmask[j] == 0) {
                    // seta 1
                    bmask[j] = 1;
                    return true;
                }
            }

            // Se não achar mais 0
            // "move" o primeiro 1 para a direita
            bmask[i] = 0;
            // zera o resto
            for (auto j = i + 2; j < size; j++) {
                bmask[j] = 0;
                return true;
            }
        }
    }
    return false;
}

// old order
bool next_subset_old(std::bitset<12>& bmask, int size)
{
    // Init
    if (bmask.none()) {
        bmask[0] = 1;
        return true;
    }

    // Se tem 1 na direita
    if (bmask[size - 1] == 1) {
        auto ones_at_the_end = 0;
        auto last_0_index = -1;
        // Conta quantos 1s seguidos
        for (auto i = size - 1; i >= 0; --i) {
            if (bmask[i]) {
                ++ones_at_the_end;
                bmask[i] = 0;
            } else {
                last_0_index = i;
                break;
            }
        }

        // Se ainda há 0s
        if (ones_at_the_end < size) {
            
            // Procura o primeiro 1 antes da cadeia do final
            for (auto i = last_0_index; i >= 0; --i) {
                if (bmask[i] == 1) {
                    // Move esse 1 para a direita
                    bmask[i] = 0;
                    ++i;
                    // Assim como a cadeia do final q foi apagada
                    for (auto j = 0; j < ones_at_the_end + 1; ++j) {
                        bmask[i + j] = 1;
                    }
                    return true;
                }
            }

            // Se só tem 0s a esquerda
            // Coloca todos os 1s no começo e acrescenta mais um
            for (auto j = 0; j < ones_at_the_end + 1; ++j) {
                bmask[j] = 1;
            }
            return true;
        }

        return false;
    } else {
        for (auto j = size - 2; j >= 0; --j) {
            // Procura 1 pela direita
            if (bmask[j] == 1) {
                //Move 1 PARA a direita
                bmask[j] = 0;
                bmask[j + 1] = 1;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int sum_expected, numbers_amount;
    while (scanf("%d %d ", &sum_expected, &numbers_amount) != EOF and numbers_amount > 0) {
        auto numbers = std::vector<int>{};
        for (int i = 0; i < numbers_amount; ++i) {
            int number;
            scanf("%d ", &number);
            numbers.push_back(number);
        }

        std::vector<bool> bmask_vector(numbers_amount, false);
        auto bmask = std::bitset<12>();
        bmask.reset();
        // auto bmask = std::string("");
        // for (auto i = 0; i < numbers.size(); ++i) {
        //     bmask += "0";
        // }
        // auto bmask_ceil = bmask;
        // std::replace(bmask_ceil.begin(), bmask_ceil.end(), '0', '1');

        auto solutions = std::set<std::vector<int>> {};
        auto bit_to_set = bmask_vector.begin();
        auto is_new_subset = true;
        printf("Sums of %d:\n", sum_expected);
        for (auto bmask = 1; bmask < 1 << numbers_amount; ++bmask) {
            find_solutions(solutions, bmask, numbers_amount, numbers, sum_expected);
        }

        auto solutions_ordered = std::vector<std::vector<int>>(solutions.begin(), solutions.end());
        std::sort(solutions_ordered.rbegin(), solutions_ordered.rend());
        for (auto& solution: solutions_ordered) {
            auto it = solution.begin();
            printf("%d", *it);
            for (it = std::next(solution.begin()); it !=  solution.end(); ++it) {
                printf("+%d", *it);
            }
            printf("\n");
        }
        //while (is_new_subset) {
        //    auto bmask_int = std::accumulate(bmask_vector.rbegin(), bmask_vector.rend(), 0, [](int x, int y) { return (x << 1) + y; });
        //    auto bmask_long = bmask.to_ulong();
        //    find_solutions(solutions, bmask, bmask_vector, bmask_int, numbers_amount, numbers, sum_expected);
        //    is_new_subset = next_subset(bmask, numbers_amount);
        //}

        if (solutions.empty()) {
            printf("NONE\n");
        }
    }
}