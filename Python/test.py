from random import randrange

def main():
    nums = [1, 1, 2]
    nums = sorted(nums)
    nums = list(dict.fromkeys(nums))
    print(nums)

if __name__ == '__main__':
    main()
