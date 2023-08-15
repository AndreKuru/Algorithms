total_amount = int(input())
letters = input()
chunk = False
result = 0
for i in range(1, total_amount):
    if not chunk:
        if letters[i] == 'a' and letters[i - 1] == 'a':
            chunk = True
            result += 2
    else:
        if letters[i] == 'a':
            result += 1
        else:
            chunk = False

print(result)