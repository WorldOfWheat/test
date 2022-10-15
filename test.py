def solve():
    n, m = [int(i) for i in input().split()]
    k = int(input())
    ans = 0
    for i in range(k):
        cnt = 0
        cnt2 = 0
        arr = [int(i) for i in input().split()]
        for i in range(0, len(arr) - 1):
            if (arr[i] == n):
                cnt = cnt + 1
            if (arr[i] == m):
                cnt2 = cnt2 + 1
            if (arr[i] == -n):
                cnt = cnt - 1
            if (arr[i] == -m):
                cnt2 = cnt2 - 1
        if (cnt >= 1 and cnt2 >= 1):
            ans = ans + 1

    print(ans)
    
solve()