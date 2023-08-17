#include <iostream>
#include <cmath>
#include <vector>

bool check_number(long number, std::vector<long> primes)
{
    auto is_prime = true;
    for (auto prime : primes) {
        if (prime >= number) {
            break;
        }
        if (number % prime == 0) {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}

void check_numbers(long min_prime, long max_prime, std::vector<long> primes)
{
    auto n = min_prime;
    if (n == 2) {
        std::cout << n << '\n';
        n++;
    } else if (n % 2 == 0) {
        n++;
    }
    for (; n <= max_prime; n++) {
        if (check_number(n, primes)) {
            std::cout << n << '\n';
        }
    }
}

void consult_numbers(long min_prime, long max_prime, std::vector<long> primes)
{
    auto i = 0;
    while (i < primes.size() and primes[i] <= max_prime) {
        if (primes[i] >= min_prime) {
            std::cout << primes[i] << '\n';
        }
        i++;
    }
}

int main() 
{
    long tests_amount;
    long min_prime, max_prime;
    std::vector<long> min_primes;
    std::vector<long> max_primes;
    auto high_limit = 0;

    scanf("%ld", &tests_amount);
    for (auto test = 0; test < tests_amount; test++){
        scanf("%ld %ld", &min_prime, &max_prime);
        min_primes.push_back(min_prime);
        max_primes.push_back(max_prime);
        if (max_prime > high_limit) {
            high_limit = max_prime;
        }
    }

    // Calculate primes
    double testing_limit_aux = sqrt(high_limit);
    long testing_limit = ceil((double)testing_limit_aux);
    std::vector<bool> numbers(testing_limit + 1, false);
    std::vector<long> primes;
    for (auto i = 2; i <= testing_limit; i++) {
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

        if (max_prime <= testing_limit) {
            consult_numbers(min_prime, max_prime, primes);
        } else if (min_prime > testing_limit) {
            check_numbers(min_prime, max_prime, primes);
        } else {
            consult_numbers(min_prime, testing_limit, primes);
            check_numbers(testing_limit + 1, max_prime, primes);
        }

        if (test != tests_amount - 1) {
            std::cout << '\n';
        }
    }
}