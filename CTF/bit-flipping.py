from pwn import *

def byte_xor(x, y):
    return bytes([i ^ j for i, j in zip(x, y)])

token = 'c63ada1009d872306f3c2ff629222a3be543676918b4c777795c53b34f4f3eec'

a = bytes.fromhex(token[0:32])
b = bytes.fromhex(token[32:len(token)])

a = xor(a, (b'\x01') + ((b'\x00') * 15))


print(a.hex() + b.hex())
