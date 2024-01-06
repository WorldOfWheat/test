arr = list(map(int, input().split()))
n = int(input())

dp = []
dp.append(0)
for i in range(n + 1):
    dp.append(1000000000)

for i in range(1, n + 1):
    current_sum = i

    for j in range(10):
        if (current_sum - arr[j] < 0):
            continue
        dp[i] = min(dp[i], dp[current_sum - arr[j]] + 1)

if dp[n] == 1000000000:
    print("No Solution")
else:
    print(dp[n])
