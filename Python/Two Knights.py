n = int(input())

def two_knight(x):
    return (((x ** 2) * (x ** 2 - 1)) // 2) - 2 * (2 * (x - 2) * (x - 1))

for i in range(1, n + 1):
    print(two_knight(i))