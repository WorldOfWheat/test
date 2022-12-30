import os
import sys

from Crypto.Cipher import AES

from secret import FLAG

iv = os.urandom(16)
key = os.urandom(32)


def pad(text):
    padding = 16 - (len(text) % 16)
    return text + bytes([padding]) * padding


def unpad(text):
    padding = text[-1]
    assert 0 < padding <= 16
    assert text.endswith(bytes([padding]) * padding)
    return text[:-padding]


def encrypt(username, is_admin=b"0"):
    cipher = AES.new(key, AES.MODE_CBC, iv)
    enc = cipher.encrypt(pad(username) + pad(is_admin))
    return enc


def decrypt(text):
    cipher = AES.new(key, AES.MODE_CBC, iv)
    text = cipher.decrypt(text)
    return text[:-16], unpad(text[-16:])


def login():
    username = input("> username: ").encode()
    print(f"Token: {encrypt(username).hex()}")


def verify():
    token = bytes.fromhex(input("> token: "))
    username, is_admin = decrypt(token)

    try:
        print(f"Hi, {username.decode()}")
    except UnicodeDecodeError:
        print(f"Hi, {username.hex()}")

    if is_admin == b"1":
        print(f"Here is your flag: {FLAG}")
        print("[FLAG] bit-flipping", file=sys.stderr)


def main():
    while True:
        print("> login")
        print("> verify")
        print("> server.py")
        print("> exit")
        cmd = input("> Command: ")
        if cmd == "exit":
            sys.exit(1)
        elif cmd == "login":
            login()
        elif cmd == "verify":
            verify()
            sys.exit(1)
        elif cmd == "server.py":
            print(open("./server.py", "r").read())
        else:
            cipher = AES.new(key, AES.MODE_CBC, iv)
            print(cipher.encrypt(pad(b"Bad hacker")).hex())


if __name__ == "__main__":
    try:
        main()
    except EOFError:
        sys.exit(1)
