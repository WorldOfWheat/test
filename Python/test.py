import os

TEST = True

def printTitle():
    print('---------------------------------------')
    print('')

def gitPull(path):
    try:
        os.chdir(path)
        if not TEST:
            os.system('git pull origin main')
    except:
        raise

def gitPush(path):
    try:
        os.chdir(path)
        if not TEST:
            os.system('git add .')
            os.system('git commit -a --allow-empty-message -m ""')
            os.system('git push origin main')
    except:
        raise   

def main():
    f = open('D:\\Git\\test\\Python\\path.txt', 'r')
    allPath = f.readlines()
    f.close()

    printTitle()
    if allPath[-1][-1] != '\n':
        allPath[-1] += '\n'

    LENGTH = len(allPath)
    for i in range(LENGTH):
        path = allPath[i]
        if path[0] == '#' or path[0] == '\n':
            continue
        path = path[:-1]

        print(str((i + 1)) + ': ', end='')
        try:
            gitPull(path)
            gitPush(path)
        except:
            print('路徑無效', path)

if __name__ == '__main__':
    main()
