tests_amount = int(input())

input()

for test in range(tests_amount):
    words = list()
    normalized = dict()
    word = input()
    while word:
        words.append(word)
        word_normalized = sorted(word.replace(" ", ""))
        normalized[word] = word_normalized

        try:
            word = input()
        except EOFError:
            break

    words.sort()
    for i in range(len(words)):
        word = words[i]
        for another_word in words[i + 1:]:
            if normalized[word] == normalized[another_word]:
                print(f"{word} = {another_word}")

    if test < tests_amount - 1:
        print()