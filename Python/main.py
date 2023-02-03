from collections import defaultdict
from sortedcontainers import SortedList
import os

welcomeMsg = '''-----------------------------------------------------------
歡迎使用去重工具 v1.0
作者：小麥 WorldOfWheat
GitHub： https://github.com/WorldOfWheat/FilesUniqueTool
-----------------------------------------------------------'''

successfulMsg = '''-----------------------------------------------------------
執行完成
-----------------------------------------------------------'''

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
        if (_input.lower() == 'true') or (_input.lower() == 'false') or (_input == '1') or (_input == '0'):
            break
        print('輸入格式錯誤')
    result.append(True if (_input.lower() == 'true') or (_input == 1) else False)
            
    return result

def uniquePath(path, withDir):
    allFiles = os.listdir(path)
    _map = {}
    for i in allFiles:
        fullPath = path + '\\' + i
        if os.path.isdir(fullPath):
            if withDir:
                uniquePath(fullPath, True)
            continue
        fileBytes = open(fullPath, 'rb')
        data = fileBytes.read(512)
        fileBytes.close()
        if _map.get(data.hex(), None) == None:
            _map[data.hex()] = SortedList()
        _map.setdefault
        _map[data.hex()].add(fullPath)
    for i in _map:
        for j in _map[i][:-1]:
            print(j)
            os.remove(j)

def main():
    print(welcomeMsg)
    _input = getInput()
    uniquePath(_input[0], _input[1])
    print(successfulMsg)

if __name__ == '__main__':
    main()
    os.system('pause')