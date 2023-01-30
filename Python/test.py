import sys

def main():
    prefixSum = []
    n, m = map(int(), input().split(' '))
    prefixSum.extend(n + 1)
    for _ in range(m):
        a, b, c = map(int(), input().split(' '))
        a -= 1
        prefixSum[a] += c
        prefixSum[b] -= c



if __name__ == '__main__':
    sys.setrecursionlimit(100000)

    main()
