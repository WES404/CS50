def main():

    text = input("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentence(text)

    L = (100 * letters) / words
    S = (100 * sentences) / words

    index = 0.0588 * L - 0.296 * S - 15.8

    x =  int(round(index))

    if x >= 16:
        print("Grade 16+")

    elif x < 1:
        print("Before Grade 1")

    else:
        print("Grade ", x)


def count_letters(x):

    count = 0

    for i in range(len(x)):
        if x[i].isalpha():
            count += 1

    return count


def count_words(x):

    count = 0
    for i in range(len(x)):
        if x[i] == ' ':
            count += 1

    return count + 1

def count_sentence(x):

    count = 0
    for i in range(len(x)):
        if x[i] == '!' or x[i] == '?' or x[i] == '.':
            count += 1

    return count

main()