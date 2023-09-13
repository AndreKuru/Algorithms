#include <stdio.h>
#include <bitset>
#include <stdexcept>

const int MILLION = 1000000;

void set_time(std::bitset<MILLION> &time, int start, int end)
{
    for (int i = start; i < end; i++){
        if (time[i]){
            throw std::invalid_argument("Time overlap");
        } 
        time[i] = 1;
    }
}

void set_time_recursive(std::bitset<MILLION> &time, int start, int end, int interval)
{
    for (int i = 0; i + end < MILLION; i += interval){
        set_time(time, start + i, end + i);
    }
}

int main()
{
    std::bitset<MILLION> time;
    int n, m;
    scanf("%d %d%*c", &n, &m);

    while(not (n == 0 and m == 0)){
        try {
            time.reset();
            for (int i = 0; i < n; i++){
                int start, end;
                scanf("%d %d%*c", &start, &end);
                set_time(time, start, end);
            }

            for (int i = 0; i < m; i++){
                int start, end, interval;
                scanf("%d %d %d%*c", &start, &end, &interval);
                set_time_recursive(time, start, end, interval);
            }
            printf("NO CONFLICT\n");
        } catch(const std::invalid_argument& e){
            printf("CONFLICT\n");
        }

        scanf("%d %d%*c", &n, &m);
    }
}