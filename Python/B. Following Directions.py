def main():
    t = int(input())
    for _ in range(t):
        input()
        string = input()
        x, y = 0, 0
        flag = False
        for i in string:
            if i == 'U':
                y += 1
            elif i == 'D':
                y -= 1
            elif i == 'L':
                x -= 1
            else:
                x += 1
            if x == 1 and y == 1:
                print('yes')
                flag = True
                break
        if flag:
            continue
        print('no')
    
if __name__ == '__main__':
    main()