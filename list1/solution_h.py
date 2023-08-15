blocks_amount, colors_amount = [int(x) for x in input().split()]

colors_sequence = list()
blocks_colors = dict()
for _ in range(blocks_amount):
    number, color = [int(x) for x in input().split()]
    colors_sequence.append(color)
    blocks_colors[number] = color

try:
    for i in range(blocks_amount):
        if blocks_colors[i + 1] != colors_sequence[i]:
            raise Exception("N")
    print("Y")
except Exception as error:
    print(error)