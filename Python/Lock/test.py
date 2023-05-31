import os

def main():
    os.system("manage-bde -lock " + os.getcwd()[0:2] + " -fd")

if __name__ == '__main__':
    main()
