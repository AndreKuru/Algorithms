#include <stdio.h>
#include <vector>
#include <iterator>

bool check_new_piece(std::vector<std::pair<int, int>>& selected_pieces, std::pair<int, int>& initial_piece, std::pair<int, int>& final_piece, int spaces_amount, std::pair<int, int>& new_piece)
{
    if (selected_pieces.empty()) {
        if (new_piece.first == initial_piece.second) {
            return true;
        }
    } else {
        auto last_piece = selected_pieces.back();
        if (new_piece.first == last_piece.second) {
            if (selected_pieces.size() < spaces_amount - 1) {
                return true;
            } else if (new_piece.second == final_piece.first) {
                return true;
            }
        }
    }

    return false;
}

bool try_more_pieces(std::vector<std::pair<int, int>>& fill_pieces, std::vector<std::pair<int, int>>& selected_pieces, std::pair<int, int>& initial_piece, std::pair<int, int>& final_piece, int spaces_amount)
{
    for (auto new_piece: fill_pieces) {
        if (check_new_piece(selected_pieces, initial_piece, final_piece, spaces_amount, new_piece)) {
            selected_pieces.push_back(new_piece);
            if (selected_pieces.size() < spaces_amount) {
                if (try_more_pieces(fill_pieces, selected_pieces, initial_piece, final_piece, spaces_amount)) {
                    return true;
                } else {
                    selected_pieces.pop_back();
                }
            } else {
                return true;
            }
        }
    }

    return false;
}
    
    

int main()
{
    int spaces_amount;
    scanf("%d%*c", &spaces_amount);
    while (spaces_amount > 0) {
        int fill_pieces_amount, piece_value0, piece_value1;
        scanf("%d%*c", &fill_pieces_amount);

        scanf("%d %d%*c", &piece_value0, &piece_value1);
        auto initial_piece = std::make_pair(piece_value0, piece_value1);
        scanf("%d %d%*c", &piece_value0, &piece_value1);
        auto final_piece = std::make_pair(piece_value0, piece_value1);

        auto fill_pieces = std::vector<std::pair<int, int>> {};
        for (auto i = 0; i < fill_pieces_amount; ++i) {
            scanf("%d %d%*c", &piece_value0, &piece_value1);
            auto fill_piece = std::make_pair(piece_value0, piece_value1);
            fill_pieces.push_back(fill_piece);
            if (piece_value0 != piece_value1) {
                auto swaped_fill_piece = std::make_pair(piece_value1, piece_value0);
                fill_pieces.push_back(swaped_fill_piece);
            }
        }

        auto selected_pieces = std::vector<std::pair<int, int>> {};
        if (try_more_pieces(fill_pieces, selected_pieces, initial_piece, final_piece, spaces_amount)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

        scanf("%d%*c", &spaces_amount);
    }

}