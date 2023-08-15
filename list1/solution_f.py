ships_amount = int(input())
coordinates_used = set()

try:
    for _ in range(ships_amount):
        vertical, length, row, column = [int(x) for x in input().split()]

        if vertical:
            if row + length > 10 or column > 10:
                raise Exception("N")
            increment = lambda row, column: (row + 1, column)
        else:
            if row > 10 or column + length > 10:
                raise Exception("N")
            increment = lambda row, column: (row, column + 1)

        for _ in range(length):
            if (row, column) in coordinates_used:
                raise Exception("N")
            else:
                coordinates_used.add((row, column))
            row, column = increment(row, column)
#                row += 1
#        
#            for _ in range(length):
#                if column > 10 or  (row, column) in coordinates_used:
#                    raise Exception("N")
#                else:
#                    coordinates_used.add((row, column))
#                column += 1
#        

    print("Y")
except Exception as error:
    print(error)