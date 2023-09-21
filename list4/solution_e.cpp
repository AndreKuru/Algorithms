#include <stdio.h>
#include <vector>
#include <algorithm>

int main()
{
    int tape_space, tracks_amount, track;
    while (scanf("%d %d ", &tape_space, &tracks_amount) != EOF) {
        auto tracks = std::vector<int> {};
        for (auto i = 0; i < tracks_amount; ++i) {
            scanf("%d ", &track);
            tracks.push_back(track);
        }
        auto tracks_alternative = tracks;
        std::sort(tracks_alternative.begin(), tracks_alternative.end());
        
        auto best_tracks = std::vector<int> {};

        auto best_sum = 0;
        auto has_solution = false;
        auto bmask_limit = 1 << tracks.size();
        for (auto bmask = 0; bmask < bmask_limit; ++bmask) {

            auto sum = 0;
            for (auto i = 0; i < tracks.size(); ++i) {
                if (bmask & (1 << i)) {
                    sum += tracks.at(i);
                }
            }
        
            if (best_sum < sum and sum <= tape_space) {
                best_sum = sum;
                best_tracks = std::vector<int> {};
                for (auto i = 0; i < tracks.size(); ++i) {
                    if (bmask & (1 << i)) {
                        best_tracks.push_back(tracks.at(i));
                    }
                }
                
                if (best_sum == tape_space) {
                    break;
                }
            }
        }

        for (auto& track: best_tracks) {
            printf("%d ", track);
        }

        printf("sum:%d\n", best_sum);
    }
}