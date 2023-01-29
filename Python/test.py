import sys

def sum(x):
    print(x)       
    if x[0:4] == [3, 1, 7, 8]:
        return 'ok'
    
    for i in range(0, 3):
        if x[i] == 10:
            x[i+1] += 1
            x[i] = 0
    
    x[0] += 1
    
    return sum(x)
        
def main():
    arr = [0, 0, 0, 0]
    print(sum(arr))

if __name__ == '__main__':
    sys.setrecursionlimit(100000)
    print(sys.getrecursionlimit())

    main()