n = int(input())
arr = [int(i) for i in input().split()]

ans = 0
for i in range(n):
    if i == 0:
        continue

    d = arr[i] - arr[i-1]
    if (d >= 0):
        continue

    d = abs(d)
    ans += d
    arr[i] += d

print(ans)
