from Crypto.Hash import SHA512, SHA1, MD5
import os
import sqlite3

def get_hash(data):
    # data = data.encode()

    md5 = MD5.new();
    sha1 = SHA1.new();
    sha512 = SHA512.new();

    md5.update(data)
    sha1.update(data)
    sha512.update(data)

    hash1 = md5.digest().hex()
    hash2 = sha1.digest().hex()
    hash3 = sha512.digest().hex()
    return (hash1, hash2, hash3)

def get_all_paths(current_path):
    if (os.path.isfile(current_path)):
        return [current_path]
    paths = []
    for i in os.listdir(current_path):
        paths.extend(get_all_paths(f'{current_path}/{i}'))
    return paths

def main():
    paths = get_all_paths('.')
    for i in paths:
        with open(i, 'rb') as f:
            data = f.read()
            hash1, hash2, hash3 = get_hash(data)
            print(f'{i} {hash1} {hash2} {hash3}')
    # print(get_hash('hello world'))


if __name__ == '__main__':
    main()
