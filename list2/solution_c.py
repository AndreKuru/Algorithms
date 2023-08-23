#def sum_points(cards: list[int]) -> int:
def sum_points(cards):
    points = [c if c <= 10 else 10 for c in cards]
    return sum(points)

common_cards_amount = int(input())
john_cards = [int(x) for x in input().split()]
mary_cards = [int(x) for x in input().split()]
common_cards = [int(x) for x in input().split()]
all_cards = john_cards + mary_cards + common_cards

max_card = 23 - (sum_points(mary_cards) + sum_points(common_cards))
mary_winner = False
if max_card >= 1:
    if sum_points(mary_cards) >= sum_points(john_cards):
        min_card = max_card
    else:
        min_card = 24 - (sum_points(john_cards) + sum_points(common_cards))

    for card in range(min_card, max_card + 1):
        if all_cards.count(card) < 4:
            print(card)
            mary_winner = True
            break

if not mary_winner:
    print(-1)