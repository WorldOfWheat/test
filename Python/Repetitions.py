s = input()

ans = 1
count = 1
for i in range(len(s)):
    if i == 0:
        continue

    if s[i] == s[i-1]:
        count = count + 1
    else:
        count = 1
    ans = max(ans, count)

print(ans)