def solve():
    arr = [int(i) for i in input().split(' ')]
    arr2 = [int(i) for i in input().split(' ')]

    flag = True
    if (not (arr[1] != arr[3] and arr2[1] != arr2[3] and 
        arr[1] == arr[5] and arr2[1] != arr2[5])):
        print("A")
        flag = False
    if (not (arr[len[arr] - 1] == 1 and arr2[len[arr2] - 1] == 0)):
        print("B")
        flag = False
    return
    if (not (arr[1] != arr2[1] and arr[3] != arr2[3] and arr[5] != arr2[5])):
        print("C")
        flag = False
    
    if (flag):
        print("None")

t = int(input())
while t > 0:
    t = t - 1
    solve()