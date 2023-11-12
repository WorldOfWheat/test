import os

def main():
    os.system("git status") # 顯示所有變改

    print("-----------------------------------")
    print("Please input the commit message:")
    print("-----------------------------------")
    
    # 輸入 commit message
    commit_message = ""
    commit_message = input();

    # 重新push用
    again = True
    while (again):
        # 上傳指令
        os.system("git add .")
        os.system("git commit -S -a -m " + "\"" + commit_message + "\"")
        os.system("git push origin main")

        print("----------------------------------------------")
        print("Should run again? Input '1' or '0' to select:")
        print("----------------------------------------------")

        # 待輸入是否重新執行
        while (True):
            select_input = input()
            if select_input == "1" or select_input == "0":
                break
            print("-----------------------------------------")
            print("Wrong Input! Input Should be '1' or '0'!")
            print("-----------------------------------------")
        again = bool(int(select_input));

if __name__ == '__main__':
    main()