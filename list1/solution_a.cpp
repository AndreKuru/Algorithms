#include <iostream>
#include <cmath>
#include <vector>

int main() 
{
    int tests_amount;
    int min_prime, max_prime;
    std::vector<int> min_primes;
    std::vector<int> max_primes;
    auto high_limit = 0;

    scanf("%d", &tests_amount);
    for (auto test = 0; test < tests_amount; test++){
        scanf("%d %d", &min_prime, &max_prime);
        min_primes.push_back(min_prime);
        max_primes.push_back(max_prime);
        if (max_prime > high_limit) {
            high_limit = max_prime;
        }
    }

    // Calculate primes
    std::vector<bool> numbers(high_limit + 1, false);
    std::vector<int> primes;
    auto testing_limit = ceil((high_limit));
    for (auto i = 2; i < testing_limit; i++) {
        if (numbers[i] == false) {
            primes.push_back(i);
            for (auto j = i * i; j < numbers.size(); j += i) {
                numbers[j] = true;
            }
        }
    }
    
    // Answers
    for (auto test = 0; test < tests_amount; test++){
        if (min_primes[test] < 2) {
            min_prime = 2;
        } else {
            min_prime = min_primes[test];
        }
        max_prime = max_primes[test];

        auto i = 0;
        while (i < primes.size() and primes[i] < max_prime) {
            if (primes[i] > min_prime) {
                std::cout << primes[i] << '\n';
            }
            i++;
        }

        if (test != tests_amount - 1) {
            std::cout << '\n';
        }
    }
}