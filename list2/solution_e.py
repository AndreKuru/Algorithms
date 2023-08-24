tests_amount = int(input())

tests = list()
_ = input()

for _ in range(tests_amount):
    words = list()
    words_value = list()
    line = input()
    while line:
        words.append(line)
        line = input()

    words.sort()
    tests.append(words)

for t in range(len(tests)):
    words = tests[t]
    anagrams = dict()
    normalized = dict()
    for i in range(len(words)):
        word = words[i]
        if word not in normalized:
            word_normalized = sorted(word.replace(" ", ""))
            normalized[word] = word_normalized

        for j in range(i + 1, len(words)):
            another_word = words[j]
            if another_word not in normalized:
                word_normalized = sorted(another_word.replace(" ", ""))
                normalized[another_word] = word_normalized
            
            if normalized[word] == normalized[another_word]:
                if i not in anagrams:
                    anagrams[i] = [j]
                else:
                    anagrams[i] += [j]

    for i in anagrams:
        for j in anagrams[i]:
            print(f"{words[i]} = {words[j]}")
    
    if t < len(tests) - 1:
        print("")