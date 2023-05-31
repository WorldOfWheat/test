import os

def main():
    print("-------------------------------------------------")
    print("Please input the commit message:")
    print("-------------------------------------------------")
    commit_message = ""
    commit_message = input();

    os.system("git add .")
    os.system("git commit -S -a -m " + "\"" + commit_message + "\"")
    # os.system("git push origin main")

    print("-------------------------------------------------")
    print("Should run again? Input '1' or '0' to select:")
        print("----------------------------------------------------------------")
    while (True):
        select_input = input()
        if select_input == "1" or select_input == "0":
            break
        print("-----------------------------------------------------")
        print("Wrong Input! Input Should be '1' or '0'!")
        print("-----------------------------------------------------")
    again = bool(int(select_input));
    if again:
        main()

if __name__ == '__main__':
    main()