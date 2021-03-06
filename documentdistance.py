import math

#http://6.006.scripts.mit.edu/~6.006/spring08/wiki/index.php?title=Document_Distance_Problem_Definition

def createWordsAndCountOccurrences(fileString):
    wordCount = {}
    i = -1
    j = 0
    for x in range(len(fileString)):
        if fileString[x].isalpha() is False:
            word = fileString[i + 1:j].lower()
            if word != "":
                try:
                    wordCount[word] += 1
                except KeyError:
                    wordCount[word] = 1
            i = j
        j += 1

    return wordCount


def dotProduct(v, u):
    res = 0
    for x in range(len(v)):
        res += v[x] * u[x]

    return res


def lengthOfVector(v):
    num = 0
    for x in v:
        num += x ** 2

    return num ** (1 / 2)


def mergeLists(a, b):
    liste = []
    for x in a:
        liste.append(x)
    for x in b:
        liste.append(x)

    return list(set(liste))


def dd(file1, file2):
    f1 = open(file1, "r")
    f2 = open(file2, "r")

    f11 = f1.read()
    f22 = f2.read()

    f1.close()
    f2.close()

    wordCount1 = createWordsAndCountOccurrences(f11)
    wordCount2 = createWordsAndCountOccurrences(f22)

    words = mergeLists(wordCount1.keys(), wordCount2.keys())

    v1 = []
    v2 = []

    for x in words:
        try:
            v1.append(wordCount1[x])
        except KeyError:
            v1.append(0)

        try:
            v2.append(wordCount2[x])
        except KeyError:
            v2.append(0)

    return ((math.acos(dotProduct(v1, v2) / (lengthOfVector(v1) * lengthOfVector(v2))) / math.pi) * 180).__format__(".2f")
