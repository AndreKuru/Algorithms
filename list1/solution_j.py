games_amount = int(input())

wins_amount = 0
for _ in range(games_amount):
    car_door = int(input())
    if car_door > 1:
        wins_amount += 1

print(wins_amount)