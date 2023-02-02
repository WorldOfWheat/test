from collections import OrderedDict
from random import randrange

def main():
    d = OrderedDict()
    arr = []
    for i in range(50):
        arr.append(randrange(1, 51))
    #print(arr)
    d = d.fromkeys(arr)
    print(d)

if __name__ == '__main__':
    main()
