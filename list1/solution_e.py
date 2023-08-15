boxes_amount = int(input())
max_balance = balance = 100
for _ in range(boxes_amount):
    box = int(input())
    balance += box
    if balance > max_balance:
        max_balance = balance
print(max_balance)