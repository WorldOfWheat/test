def getOper(x):
    _x = ''
    for i in x:
        if i == ' ':
            continue
        _x += i
    x = _x

    return x[13]

def main():
    n = int(input())
    result = ''
    _result = ''
    k = 1
    for i in range(n):
        string = input()  
        if string[0] == 'f':
            result += _result + '+' + getOper(string)
            _result = ''
        else:
            _result += getOper(string)
    result += _result
    print('O(' + result[1:] + ')')
    
if __name__ == '__main__':
    main()