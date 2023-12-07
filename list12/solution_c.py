import sys

correct_answers = 0
for line in sys.stdin:
    account, answer = line.split('=')
    if answer.find('?') >= 0:
        continue

    if account.find('+') >= 0:
        a, b = [int(x) for x in account.split('+')]
        c = a + b
    else:
        a, b = [int(x) for x in account.split('-')]
        c = a - b
    
    if c == int(answer):
        correct_answers += 1

print(correct_answers)