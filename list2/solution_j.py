tests_amount = int(input())

final_cards = list()
for _ in range(tests_amount):
    y = 0
    cards = input().split()
    pile = cards[:-25]
    for _ in range(3):
        x : str = pile.pop()[0]
        if x.isnumeric():
            x = int(x)
        else:
            x = 10
        y += x

        removing_cards = 10 - x
        if removing_cards:
            pile = pile[:-removing_cards]

    final_pile = pile + cards[-25:]
    final_cards.append(final_pile[y - 1])


for i in range(len(final_cards)):
    print(f"Case {i + 1}: {final_cards[i]}")