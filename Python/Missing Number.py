def main():
    n = int(input())
    m = list(map(int, input().split()))

    se = set(m)
    for i in range(1, n + 1):
        if (not (i in se)):
            print(i)
            return

if __name__ == '__main__':
    main()