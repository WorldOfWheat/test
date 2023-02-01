from random import randrange

def main():
    set1 = set()
    for i in range(50):
        set1.add(randrange(1, 500))
    arr = list(set1)
    _arr = arr
    arr = sorted(arr)
    print(str(arr) + '\n' + str(_arr))
    print(_arr.index(arr[0]))

if __name__ == '__main__':
    main()
