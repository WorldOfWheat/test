import os

welcomeMsg = '''-----------------------------------------------------------
歡迎使用批量Git工具 v1.0
作者：小麥 WorldOfWheat
GitHub： https://github.com/WorldOfWheat/BatchGit
-----------------------------------------------------------'''

pathFileNotExistMsg = '''找不到 path.txt，因此系統以自動創建，請於 path.txt 內寫入於自動處理的Git路徑
-----------------------------------------------------------'''

successfulMsg = '''執行完成
-----------------------------------------------------------'''

def gitPull(path):
    try:
        os.chdir(path)
        os.system('git pull origin main')
    except:
        raise

def gitPush(path):
    try:
        os.chdir(path)
        os.system('git add .')
        os.system('git commit -a --allow-empty-message -m ""')
        os.system('git push origin main')
    except:
        raise   

def main():
    print(welcomeMsg) # 印出歡迎訊息

    if not os.path.exists('path.txt'): # 找不到 path.txt
        open('path.txt', 'x') # 新建檔案
        print(pathFileNotExistMsg) # 印找不到檔案的訊息
        raise

    with open('path.txt', 'r') as file:
        allPath = file.readlines()

        if len(allPath) == 0: # 找不到資料
            return
        if allPath[-1][-1] != '\n': # 結尾無換行
            allPath[-1] += '\n' # 補上換行號

        LENGTH = len(allPath)
        for i in range(LENGTH):
            path = allPath[i]
            if path[0] == '#' or path[0] == '\n': # 註解或無資料行跳過
                continue
            path = path[:-1] # 去掉路徑資料結尾的換行號

            print(str((i + 1)) + ': ', end='') # 印出編號
            try:
                gitPull(path)
                gitPush(path)
            except:
                print('路徑無效', path)
    

if __name__ == '__main__':
    try:
        main()
        print(successfulMsg) # 印出執行完成訊息
    except:
        pass

    os.system('pause')
