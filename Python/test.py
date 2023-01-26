from collections import defaultdict
import os
import time

def printInfo():
    print('-----------------------------------')
    print('歡迎使用去重工具 v1.0')
    print('作者：小麥')
    print('GitHub： https://github.com/WorldOfWheat')
    print('-----------------------------------')

def getInput():
    result = [] 

    while True:
        _input = input('請輸入要去重的路徑: ')
        try:
            os.chdir(_input)
            break
        except:
            print('路徑無效')
    result.append(_input)

    while True:
        _input = input('是否去重路徑內的所有資料夾 true/false: ')
        if (_input.lower() == 'true') or (_input.lower() == 'false'):
            break
        print('輸入格式錯誤')
    result.append(True if _input.lower() == 'true' else False)
            
    return result

def uniquePath(path, withDir):
    allFiles = os.listdir(path)
    md = defaultdict(list)
    for i in allFiles:
        fullPath = path + '\\' + i
        if os.path.isdir(fullPath):
            if withDir:
                uniquePath(fullPath, True)
            continue
        fileBytes = open(fullPath, 'rb')
        data = fileBytes.read(512)
        fileBytes.close()
        md[data.hex()].append(fullPath)
    for i in md:
        md[i].sort()
        for j in md[i][:-1]:
            os.remove(j)

def main():
    printInfo()
    path = getInput()
    uniquePath(path[0], path[1])
    print('!去重完成!')

if __name__ == '__main__':
    main()