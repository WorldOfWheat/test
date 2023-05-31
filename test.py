import os

def main():
    print("Please input the commit message:")
    commit_message = ""
    commit_message = input();

    os.system("git add .")
    os.system("git commit -S -m " + commit_message)
    os.system("git push origin main")

    print("Should run again? Input '1' or '0' to select:")
    while (True):
        select_input = input()
        if select_input == "1" or select_input == "0":
            break
        print("Wrong Input! Input Should be '1' or '0'!")
    again = bool(int(select_input));
    if again:
        main()

if __name__ == '__main__':
    main()