from Crypto.Util.number import getPrime
from secret import flag

# RSA numbers
p = getPrime(512)
q = getPrime(512)
n = p * q
e = 65537

encrypted = []
for char in flag:
    assert 0 <= ord(char) <= 127
    # RSA encrypt
    encrypted.append(pow(ord(char), e, n))

print(f'{n = }')
print(f'{e = }')
print(f'{encrypted = }')
