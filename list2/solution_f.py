tests_amount = int(input())

sums = list()
for _ in range(tests_amount):
    temp0_celsius, temp1_fahrenheit = [float(x) for x in input().split()]
    temp0_fahrenheint = 9/5 * temp0_celsius + 32
    sum_fahrenheint = temp0_fahrenheint + temp1_fahrenheit
    sum_celsius = (sum_fahrenheint - 32) * 5 / 9
    sums.append(sum_celsius)

for sum in sums:
    print(f"{sum:0.2f}".rstrip('0').rstrip('.'))
