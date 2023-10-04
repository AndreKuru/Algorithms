#include <stdio.h>
#include <vector>
#include <iterator>
#include <algorithm>

using domino = std::pair<int, int>;

bool check_new_piece(std::vector<domino>& selected_pieces, domino& initial_piece, domino& final_piece, int spaces_amount, domino& new_piece)
{
    if (selected_pieces.empty()) {
        if (new_piece.first != initial_piece.second) {
            return false;
        }
    } else {
        auto last_piece = selected_pieces.back();
        if (new_piece.first != last_piece.second) {
            return false;
        }
    }

    if (selected_pieces.size() >= spaces_amount - 1 and new_piece.second != final_piece.first) {
        return false;
    }

    return true;
}

bool try_more_pieces(std::vector<domino>& fill_pieces, std::vector<domino>& selected_pieces, domino& initial_piece, domino& final_piece, int spaces_amount);

bool try_piece(std::vector<domino>& fill_pieces, std::vector<domino>& selected_pieces, domino& initial_piece, domino& final_piece, int spaces_amount, domino& new_piece)
{
    if (check_new_piece(selected_pieces, initial_piece, final_piece, spaces_amount, new_piece)) {
        selected_pieces.push_back(new_piece);
        if (selected_pieces.size() < spaces_amount) {
            if (try_more_pieces(fill_pieces, selected_pieces, initial_piece, final_piece, spaces_amount)) {
                return true;
            } else {
                selected_pieces.pop_back();
            }
        } else {
            // printf("\n");
            // printf("%d %d\n", initial_piece.first, initial_piece.second);
            // for (auto piece: selected_pieces) {
            //     printf("%d %d\n", piece.first, piece.second);
            // }
            // printf("%d %d\n", final_piece.first, final_piece.second);
            return true;
        }
    }

    return false;
}

bool try_more_pieces(std::vector<domino>& fill_pieces, std::vector<domino>& selected_pieces, domino& initial_piece, domino& final_piece, int spaces_amount)
{
    for (auto new_piece: fill_pieces) {
        auto used_pieces = 0;
        auto it = selected_pieces.begin();
        while (1) {
            it = std::find_if(
                it, 
                selected_pieces.end(), 
                [&new_piece](const domino& piece) {
                    return (piece.first == new_piece.first and piece.second == new_piece.second) or 
                        (piece.second == new_piece.first and piece.first == new_piece.second);
                }
            );

            if (it != selected_pieces.end()) {
                ++it;
                ++used_pieces;
            } else {
                break;
            }
        }

        // if (it == selected_pieces.end()){
        if (used_pieces < 1){
            if (try_piece(fill_pieces, selected_pieces, initial_piece, final_piece, spaces_amount, new_piece)) {
                return true;
            } else if (new_piece.first != new_piece.second) {
                auto swaped_new_piece = new_piece;
                std::swap(swaped_new_piece.first, swaped_new_piece.second);
                if (try_piece(fill_pieces, selected_pieces, initial_piece, final_piece, spaces_amount, swaped_new_piece)) {
                    return true;
                }
            }
        }
    }

    return false;
}
    
    

int main()
{
    int spaces_amount;
    scanf("%u%*c", &spaces_amount);
    while (spaces_amount > 0) {
        int fill_pieces_amount, piece_value0, piece_value1;
        scanf("%d%*c", &fill_pieces_amount);

        scanf("%d %d%*c", &piece_value0, &piece_value1);
        auto initial_piece = std::make_pair(piece_value0, piece_value1);
        scanf("%d %d%*c", &piece_value0, &piece_value1);
        auto final_piece = std::make_pair(piece_value0, piece_value1);

        auto fill_pieces = std::vector<domino> {};
        for (auto i = 0; i < fill_pieces_amount; ++i) {
            scanf("%d %d%*c", &piece_value0, &piece_value1);
            auto fill_piece = std::make_pair(piece_value0, piece_value1);
            fill_pieces.push_back(fill_piece);
        }

        auto selected_pieces = std::vector<domino> {};
        if (try_more_pieces(fill_pieces, selected_pieces, initial_piece, final_piece, spaces_amount)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

        scanf("%u%*c", &spaces_amount);
    }

}