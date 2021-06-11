# algorithm to sort a string with letters from alphabet of 'L' and 'C' so that no equal letters remain beside each other
# input is length of string and string
# sort by inverting prefix and placing it at the end of the string
# output is amount of necessary operations and index of last prefix letter per operation 

def fancysort(ant, pref):
    i = 0
    A = []
    while True:
        sjekk = pref
        for x in range(ant-1):
            if pref[x+1] == pref[x] and pref[ant-1] != pref[x]:
                a = pref[:x+1]
                a = a[::-1]
                b = pref[(x+1):ant]
                pref = b + a
                i += 1
                A.append(x+1)
                break

        if sjekk == pref:
            T = True
            for x in range(ant-1):
                if pref[x] == pref[x+1]:
                    T = False
                    break
            if T is False:
                print('IMPOSSIBLE')
                break
            else:
                print(i)
                for x in A:
                    print(x, end=' ')
                break


N = int(input())
streng = input()
fancysort(N, streng)
