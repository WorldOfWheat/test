def dfs(x):
    print(x, end=' ');

    if x == 1:
        return

    if x % 2 == 1:
        dfs(3 * x + 1)
    else:
        dfs(x // 2)

n = int(input())
dfs(n)
