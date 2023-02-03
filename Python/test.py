def main():
    with open('input.txt', 'r') as file:
        n, m = map(int, file.readline().split(' '))
        arr = list(map(int, file.readline().split(' ')))
        arr = list(map(lambda x : x - 1, arr))

    go = [[0 for _ in range(64)] for _ in range(n)]  
    for i in range(0, n):
        go[i][0] = arr[i]
    for i in range(1, 60):
        for j in range(0, n):
            go[j][i] = go[go[j][i-1]][i-1]

    m -= 1
    pos = 0
    for i in range(0, 60):
        if (m >> i) & 1:
            pos = go[pos][i]
    print(pos + 1)
    
if __name__ == '__main__':
    main()