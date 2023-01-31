from decimal import Decimal, getcontext
from random import randrange
import sys

def main():
    return
    a, b = '', ''
    for i in range(90):
        a += str(randrange(1, 9))
        b += str(randrange(1, 9))
    
    k = str('{:f}'.format(Decimal(a) / Decimal(b)))
    print(k)

if __name__ == '__main__':
    sys.setrecursionlimit(100000)
    print(getcontext().prec)

    main()
