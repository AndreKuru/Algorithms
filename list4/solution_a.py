import sys
sys.setrecursionlimit(4000000)

def solve(number_str, expected_result):
    numerator = int(number_str[:5])

    denominator_decimal = numerator / expected_result
    denominator = int(denominator_decimal)
    if denominator != denominator_decimal:
        return False
    
    denominator = str(denominator)
    if len(denominator) < 4:
        return False
    if len(denominator) < 5:
        denominator = '0' + denominator

    total_algarisms = number_str[:5] + denominator
    if len(total_algarisms) == len(set(total_algarisms)):
        return denominator

    return False

def next_permutation(number_str):
    found = False
    # Find the highest index i such that s[i] < s[i+1]. 
    for i in range(1, len(number_str))[::-1]:
        if number_str[i - 1] < number_str[i]:
            found = True
            break
    
    # If no such index exists, the permutation is the last permutation.
    if not found:
        return False

    # Find the highest index j > i such that s[j] > s[i].
    # Such a j must exist, since i+1 is such an index.
    # s[j] == s[i+1], but j == i or j != i
    a = i - 1
    a_char = number_str[a]
    b = i
    b_char = number_str[b]
    for j in range(i + 1, len(number_str)):
        #if min_char >= number_str[j] and number_str[j] > number_str[i]:
        if number_str[j] <= b_char and number_str[j] > a_char:
            b = j
            b_char = number_str[b]
            

    # Swap s[i] with s[j].
    right_half =  number_str[a+1:b] + number_str[a] + number_str[b+1:]
    # Reverse the order of all of the elements after index i till the last element.
    return number_str[:a] + number_str[b] + right_half[::-1]


def try_num(number_str, expected_result, found):
    denominator = solve(number_str, expected_result)
    if denominator:
        new_match = (number_str[:5], denominator)
        if new_match not in found:
            found.append(new_match)

    number_str = next_permutation(number_str)
    if not number_str:
        return found
    return  try_num(number_str, expected_result, found)

expected_result = int(input())
blank_line = False
while(expected_result != 0):
    if blank_line:
        print()
    else:
        blank_line = True

    found = list()
    found = try_num("0123456789", expected_result, found)

    if len(found) == 0:
        print(f"There are no solutions for {expected_result}.")
    else:
        for numerator, denominator in found:
            print(f"{numerator} / {denominator} = {expected_result}")

    expected_result = int(input())