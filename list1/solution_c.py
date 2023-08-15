numbers = input().split()
result = 'S'
for n in numbers:
    if n == '9':
        result = 'F'
        break

print(result)