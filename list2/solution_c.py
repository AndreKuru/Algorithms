#def sum_points(cards: list[int]) -> int:
def sum_points(cards):
    points = [c if c <= 10 else 10 for c in cards]
    return sum(points)

common_cards_amount = int(input())
john_cards = [int(x) for x in input().split()]
mary_cards = [int(x) for x in input().split()]
common_cards = [int(x) for x in input().split()]
all_cards = john_cards + mary_cards + common_cards

for card in range(1, 14):
    if all_cards.count(card) == 4:
        continue

    if sum_points(mary_cards + common_cards + [card]) == 23:
        print(card)
        break

    if (sum_points(john_cards + common_cards + [card]) > 23 
        and sum_points(mary_cards + common_cards + [card]) < 23):
        print(card)
        break
else:
    print(-1)