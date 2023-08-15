cases = int(input())
for _ in range(cases):
    x, y = input().split()
    x = int(x[::-1])
    y = int(y[::-1])
    result = x + y
    result = int(str(result)[::-1])
    print(result)