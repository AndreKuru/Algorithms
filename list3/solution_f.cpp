#include <stdio.h>
#include <bitset>
#include <stdexcept>

const int MILLION = 1000005;

void set_time(std::bitset<MILLION>& time, int start, int end)
{
    for (int i = start; i < end; i++){
        if (time[i]){
            throw std::invalid_argument("Time overlap");
        } 
        time[i] = 1;
    }
}

void set_time_recursive(std::bitset<MILLION>& time, int start, int end, int interval)
{
    for (int i = 0; start + i < MILLION; i += interval){
        if (end + i < MILLION) {
            set_time(time, start + i, end + i);
        } else {
            set_time(time, start + i, MILLION - 1);
        }
    }
}

int main()
{
    std::bitset<MILLION> time;
    int n, m;
    scanf("%d %d%*c", &n, &m);

    while(not (n == 0 and m == 0)){
        auto i = 0;
        auto j = 0;
        try {
            time.reset();
            for (; i < n; i++){
                int start, end;
                scanf("%d %d%*c", &start, &end);
                set_time(time, start, end);
            }

            for (; j < m; j++){
                int start, end, interval;
                scanf("%d %d %d%*c", &start, &end, &interval);
                set_time_recursive(time, start, end, interval);
            }
            printf("NO CONFLICT\n");
        } catch(const std::invalid_argument& e){
            if (i >= n) {++j;}

            for (++i; i < n; ++i) {
                scanf("%*d %*d%*c");
            }
            for (; j < m; ++j) {
                scanf("%*d %*d %*d%*c");
            }
            printf("CONFLICT\n");
        }

        scanf("%d %d%*c", &n, &m);
    }
}