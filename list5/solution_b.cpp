#include <stdio.h>
#include <vector>
#include <algorithm>

int main()
{
    int books_amount;
    while (scanf("%d%*c", &books_amount) != EOF) {
        auto books = std::vector<int>{};
        int book, money;
        for (auto i = 0; i < books_amount; ++i) {
            scanf("%d ", &book);
            books.push_back(book);
        }
        scanf("%d ", &money);

        std::sort(books.begin(), books.end());

        int book1, book2;
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (*it > money/2) {
                break;
            }
            
            auto complement = money - *it;
            if (std::binary_search(books.begin(), books.end(), complement)) {
                if (*it == complement) {
                    auto range = std::equal_range(books.begin(), books.end(), complement);
                    if (range.first != prev(range.second)) {
                        book1 = *it;
                        book2 = complement;
                    }
                } else {
                    if (*it <= complement) {
                        book1 = *it;
                        book2 = complement;
                    } else {
                        book1 = complement;
                        book2 = *it;
                    }
                }
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", book1, book2);

    }
}