from bisect import bisect_left, bisect_right
from math import sqrt

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    maxi= max(n, m)
    corner = maxi ** 2 - maxi + 1
    
    if maxi % 2 == 1:
        if n > m:
            ans = corner - (maxi - m)
        else:
            ans = corner + (maxi - n)
    else:
        if n > m:
            ans = corner + (maxi - m)
        else:
            ans = corner - (maxi - n)
    
    print(ans)
