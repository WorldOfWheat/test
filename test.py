from pwn import *

r = remote('120.114.62.214', 2400)

#####

def solve():
	r.recvlines(7)

	arr = r.recvline().split()


	arr[2:len(arr)-1].sort()

	r.sendline(str(int(arr[-3])).encode())
	
	print(r.recvall())

	r.close()

#####

solve()

# nc 120.114.62.214 2400