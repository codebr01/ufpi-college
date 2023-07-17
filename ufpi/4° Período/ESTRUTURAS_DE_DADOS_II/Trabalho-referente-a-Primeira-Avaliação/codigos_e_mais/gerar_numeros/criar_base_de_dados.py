from random import shuffle

l = []
for i in range(50000):
    num = int(input())
    l.append(num)

shuffle(l)

for i in l:
    print(i)
