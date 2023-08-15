minimum_sleep, flight_duration, meals_amount = [int(x) for x in input().split()]

max_sleep = 0
sleep_start = 0
rested = False
for _ in range(meals_amount):
    meal_time = int(input())
    if meal_time - sleep_start >= minimum_sleep:
        rested = True
        break
    sleep_start = meal_time

if flight_duration - sleep_start >= minimum_sleep:
    rested = True

if rested:
    print("Y")
else:
    print("N")