winners = list()
losers = list()
line = input()
while(line != "0"):
    n, k = [int(x) for x in line.split()]
    winner = [0] * n
    loser = [0] * n
    for _ in range(int(k*n*(n - 1)/2)):
        line = input()
        p1, m1, p2, m2 = line.split()
        p1 = int(p1)
        p2 = int(p2)

        if m1 == "rock":
            if m2 == "scissors":
                winner[p1 - 1] += 1
                loser[p2 - 1] += 1
            elif m2 == "paper":
                loser[p1 - 1] += 1
                winner[p2 - 1] += 1
        elif m1 == "scissors":
            if m2 == "rock":
                loser[p1 - 1] += 1
                winner[p2 - 1] += 1
            elif m2 == "paper":
                winner[p1 - 1] += 1
                loser[p2 - 1] += 1
        else:
            if m2 == "rock":
                winner[p1 - 1] += 1
                loser[p2 - 1] += 1
            elif m2 == "paper":
                loser[p1 - 1] += 1
                winner[p2 - 1] += 1
        
    winners.append(winner)
    losers.append(loser)
    line = input()

for i in range(len(winners)):
    winner = winners[i]
    loser = losers[i]


    for j in range(len(winner)):
        total_plays = winner[j] + loser[j]
        if total_plays:
            print(f"{winner[j] / (winner[j] + loser[j]):.3f}")
        else:
            print("-")

    if i < len(winners) - 1:
        print("")
