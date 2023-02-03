from bisect import bisect_left

def main():
    alphabat = 'codeforces'
    alphabat = sorted(alphabat)
    
    n = int(input())
    for _ in range(n):
        k = input()
        index = bisect_left(alphabat, k)
        if index == n:
            print('no')
            continue
        if k == alphabat[index]:
            print('yes')
            continue
        else:
            print('no')
    
if __name__ == '__main__':
    main()