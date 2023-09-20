#include <stdio.h>
#include <cmath>

int main()
{
    int tests_amount;
    scanf("%d%*c", &tests_amount);
    for(auto test = 0; test < tests_amount; ++test) {
        int A, B, C; 
        scanf("%d %d %d%*c", &A, &B, &C);

        auto found = true;
        auto y = -1;
        auto z_reset = int(sqrt(C));
        auto z = z_reset;
        auto x = A -y -z; 
        // negative
        auto y_reset = y;
        while(not(x != y and y != z and x*y*z == B and std::pow(x, 2.0) + std::pow(y, 2.0) + std::pow(z, 2.0) == C)) {
            ++x;
            --z;
            if (x >= y) {
                --y;
                z = z_reset;
                x = A -y -z;
                if (x >= y) {
                    found = false;
                    break;
                }
            }
        }

        // positive
        if (not found) {
            found = true;
            x = 1;
            y = x;
            z = A -x -y;
            while(not(x != y and y != z and x*y*z == B and std::pow(x, 2.0) + std::pow(y, 2.0) + std::pow(z, 2.0) == C)) {
                --z;
                ++y;
                if (y >= z) {
                    ++x;
                    y = x;
                    z = A -x -y;
                    if (y >= z) {
                        found = false;
                        break;
                    }
                }
            }
        }

        if (found) {
            printf("%d %d %d\n", x, y, z);
        } else {
            printf("No solution.\n");
        }

    }
}