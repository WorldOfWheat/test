# from Crypto.Util.number import getStrongPrime
# import secrets
# from secret import flag


class Hasher:
    def __init__(self, nbits: int):
        self.p = getStrongPrime(nbits)
        self.b = secrets.randbelow(self.p)
        self.nbytes = (nbits + 7) // 8

    def hash(self, s: bytes) -> bytes:
        result = 0
        for byte in s:
            result = result * self.b + byte
            result %= self.p
        return result.to_bytes(self.nbytes, 'big')


class Signer:
    def __init__(self, nbits: int):
        self.secret = secrets.token_bytes(16)
        self.hasher = Hasher(nbits)

    def sign(self, nonce: bytes, message: bytes) -> bytes:
        assert len(nonce) == 8
        hash = self.hasher.hash(self.secret + nonce + message)
        return nonce + hash

    def verify(self, message: bytes, signature: bytes) -> bool:
        nonce = signature[:8]
        return self.sign(nonce, message) == signature


if __name__ == '__main__':
    signer = Signer(512)

    for idx in range(10):
        print('What to do?')
        print('1. Sign a password')
        print('2. Verify a password')
        print('3. Exit')
        choice = input('> ')

        if choice == '1':
            password = input('Password? ').encode()

            if password.isdigit() and 8 <= len(password) <= 16:
                nonce = str(idx).encode() * 8
                print(signer.sign(nonce, password).hex())
            else:
                print('Err Password can only be 8 to 16 numbers')

        elif choice == '2':
            password = input('Password? ').encode()
            signature = bytes.fromhex(input('Signature? '))

            if signer.verify(password, signature):
                # if b'GIVE ME THE FLAG!!' in password:    # <-- easy version, just simple LEA
                if password == b'GIVE ME THE FLAG!!':    # <-- hard version
                    print(flag)
                else:
                    print('Ok Verified')
            else:
                print('Err Unverified')

        elif choice == '3':
            print('Bye')
            break

        else:
            print('???')
