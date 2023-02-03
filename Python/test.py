def main():
    with open('input.txt', 'r') as file:
        n, m = map(int, file.readline().split(' '))
        arr = list(map(int, file.readline().split(' ')))

    go = [[0 for _ in range(64)] for _ in range(n)]  
    score = [[0 for _ in range(64)] for _ in range(n)]
    for i in range(0, n):
        go[i][0] = (i + 1) % n
        score[i][0] = arr[i]
    for i in range(1, 60):
        for j in range(0, n):
            go[j][i] = go[go[j][i-1]][i-1]
            score[j][i] = score[j][i-1] + score[go[j][i-1]][i-1]

    result = 0
    pos = 0
    for i in range(0, 60):
        if (m >> i) & 1:
            result += score[pos][i]
            pos = go[pos][i]
    print(pos)

    
if __name__ == '__main__':
    main()