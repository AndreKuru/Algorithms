users_amount = int(input())

escalator_stop = 0
escalator_direction = 0
user_waiting = False
for _ in range(users_amount):
    user_arrive, user_direction = [int(x) for x in input().split()]

    if user_arrive > escalator_stop and user_waiting:
        escalator_stop += 10
        escalator_direction = int(not escalator_direction)
        user_waiting = False

    if user_arrive >= escalator_stop:
        escalator_direction = user_direction
        escalator_stop = user_arrive + 10
    elif user_direction == escalator_direction:
        escalator_stop = user_arrive + 10
    else:
        user_waiting = True
    
if user_waiting:
    escalator_stop += 10

print(escalator_stop)