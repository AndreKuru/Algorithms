tests_amount = int(input())

input()
for test in range(tests_amount):
    words = list()
    anagrams = dict()
    word = input()
    while word:
        words.append(word)
        anagram = "".join(sorted(word.replace(" ", "")))
        if anagram not in anagrams:
            anagrams[anagram] = [word]
        else:
            anagrams[anagram] += [word]

        try:
            word = input()
        except EOFError:
            break

    pairs = list()
    for equal_words in anagrams.values():
        equal_words.sort()
        for i in range(len(equal_words)):
            word = equal_words[i]
            for another_word in equal_words[i + 1:]:
                pairs.append(f"{word} = {another_word}")

    pairs.sort()
    for pair in pairs:
        print(pair)

    if test < tests_amount - 1:
        print()