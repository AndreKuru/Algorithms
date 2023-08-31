#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>


using namespace std;

void set_found(int &cell, int word_found){
    if (cell == -1){
        cell = word_found;
    } else if (cell != word_found) {
        cell = -2;
    }
}

int main() {
    bool debug = false;
    int row, column, words_amount;
    scanf("%d %d", &row, &column);

    char matrix[row][column];
    vector<vector<int>> found (row, (vector<int>(column, -1)));

    for (auto i = 0; i < row; i++){
        scanf("%s", matrix[i]);
    }

    scanf("%d", &words_amount);
    vector<string> words;
    string word;
    for (auto i = 0; i < words_amount; i++){
        cin >> word;
        sort(word.begin(), word.end());
        words.push_back(word);
    }

    string anagram;

    for (auto i = 0; i < row; i++){
        for (auto j = 0; j < column; j++){
            
            // By row
            anagram = matrix[i][j];
            for (auto k = j + 1; k < column; k++){
                anagram += matrix[i][k];
                // cout << anagram << endl;                         // debug
                sort(anagram.begin(), anagram.end());

                for (auto w = 0; w < words_amount; w++){
                // cout << words[w] << " = " << anagram << endl;    // debug
                    if (words[w] == anagram){
                        for (auto m = j; m <= k; m++){
                            // printf("w = %d\n", w);               // debug
                            // printf("%d => ", found[i][j]);       // debug
                            set_found(found[i][m], w);
                            // printf("%d\n", found[i][j]);         // debug
                        }
                    }
                }
            }

            // By column
            anagram = matrix[i][j];
            for (auto k = i + 1; k < row; k++){
                anagram += matrix[k][j];
                sort(anagram.begin(), anagram.end());

                for (auto w = 0; w < words_amount; w++){
                    if (words[w] == anagram){
                        for (auto m = i; m <= k; m++){
                            set_found(found[m][j], w);
                        }
                    }
                }
            }

            // By main diagonal
            anagram = matrix[i][j];
            for (auto k = 1; i + k < row and j + k < column; k++){
                anagram += matrix[i + k][j + k];
                sort(anagram.begin(), anagram.end());

                for (auto w = 0; w < words_amount; w++){
                    if (words[w] == anagram){
                        for (auto m = 0; m <= k; m++){
                            set_found(found[i + m][j + m], w);
                        }
                    }
                }
            }

            // By antidiagonal
            if (debug) {printf("i     = %d, j     = %d\n", i, j);}            // debug
            anagram = matrix[i][j];
            for (auto k = 1; i + k < row and j - k >= 0; k++){
                if (debug) {printf("i + k = %d, j - k = %d\n", i + k, j - k);}// debug
                anagram += matrix[i + k][j - k];
                if (debug) {cout << anagram << endl;}                         // debug
                sort(anagram.begin(), anagram.end());

                for (auto w = 0; w < words_amount; w++){
                if (debug) {cout << words[w] << " = " << anagram << endl;}    // debug
                    if (words[w] == anagram){
                        for (auto m = 0; m <= k; m++){
                            if (debug) {printf("w = %d\n", w);}               // debug
                            if (debug) {printf("%d => ", found[i][j]);}       // debug
                            set_found(found[i + m][j - m], w);
                            if (debug) {printf("%d\n", found[i][j]);}         // debug
                        }
                    }
                }
            }
        }
    }

    if (debug){ // debug
        for (auto r = 0; r < row; r++){
            for (auto c = 0; c < column; c++){
                printf("%d", found[r][c]);
            }
            printf("\n");
        }
    }

    auto count = 0;
    for (auto i = 0; i < row; i++){
        for (auto j = 0; j < column; j++){
            if (found[i][j] == -2){
                count++;
            }
        }
    }

    printf("%d", count);

}