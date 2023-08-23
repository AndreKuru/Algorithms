palindromes = list()
sentence = input()
while sentence != "DONE":
    sentence = sentence.replace(' ', '')
    sentence = sentence.replace('.', '')
    sentence = sentence.replace(',', '')
    sentence = sentence.replace('!', '')
    sentence = sentence.replace('?', '')
    sentence = sentence.lower()

    if sentence == sentence[::-1]:
        palindromes.append(True)
    else:
        palindromes.append(False)

    sentence = input()

for palindrome in palindromes:
    if palindrome:
        print("You won't be eaten!")
    else:
        print("Uh oh..")