L = [1]
C = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
n = 1
while n <= 2005:
    L.append(0)
    n = n + 1
for i in range(0, 2002):
    for j in range(0, 10):
        if((not (i == 0 and j == 0)) and (i + C[j] <= 2002)):
            L[i + C[j]] = L[i + C[j]] + L[i]
F = [0]
n = 1
while n <= 2002:
    F.append(F[n - 1] + L[n])
    n = n + 1

try:
    while True:
        n = input()
        n = int(n)
        if(n < 6):
            print(F[n])
        else:
            print(F[n] + 1)
except EOFError:
    pass