tests_amount = int(input())

sums = list()
for i in range(tests_amount):
    temp0_celsius, temp1_fahrenheit = [float(x) for x in input().split()]
    temp0_fahrenheint = 9/5 * temp0_celsius + 32
    sum_fahrenheint = temp0_fahrenheint + temp1_fahrenheit
    sum_celsius = (sum_fahrenheint - 32) * 5 / 9
    print(f"Case {i + 1}: {sum_celsius:0.2f}")