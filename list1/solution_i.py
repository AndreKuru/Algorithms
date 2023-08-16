def score_game(to_left: bool, left_game: int, right_game: int):
    if to_left:
        left_game += 1
    else:
        right_game += 1
    
    return left_game, right_game, 0, 0

def score_point(to_left: bool, left_game: int, right_game: int, left_score: int, right_score: int):
    if to_left:
        left_score += 1
        if (left_score >= 10 
            or (left_score >= 5 
                and left_score - right_score >= 2)):

            return score_game(to_left, left_game, right_game)
    else:
        right_score += 1
        if (right_score >= 10 
            or (right_score >= 5 
                and right_score - left_score >= 2)):

            return score_game(to_left, left_game, right_game)
    
    return left_game, right_game, left_score, right_score

left_game = 0
right_game = 0
left_score = 0
right_score = 0
server_is_left = True

events = input()
for event in events:
    match event:
        case 'S':
            left_game, right_game, left_score, right_score = score_point(server_is_left, left_game, right_game, left_score, right_score)
        case 'R':
            server_is_left = not server_is_left
            left_game, right_game, left_score, right_score = score_point(server_is_left, left_game, right_game, left_score, right_score)
        case 'Q':
            if left_game > 1:
                print(f"{left_game} (winner) - {right_game}")
            elif right_game > 1:
                print(f"{left_game} - {right_game} (winner)")
            else:
                if server_is_left:
                    print(f"{left_game} ({left_score}*) - {right_game} ({right_score})")
                else:
                    print(f"{left_game} ({left_score}) - {right_game} ({right_score}*)")