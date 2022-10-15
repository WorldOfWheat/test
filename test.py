from pwn import *

r = remote('120.114.62.214', 2400)

#####

def solve():
    

#####

for i in r.recvlines(7):
	print(i)
solve()

r.close()