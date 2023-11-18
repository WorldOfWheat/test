from Crypto.Hash import SHA512, SHA1, MD5
import os
import sqlite3

class Node:
    def __init__(self, value):
        self.value = value
        self.child = []

    def add_child(self, child):
        self.child.append(child)

    def get_value(self):
        return self.value

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

def get_all_paths(node):
    current_path = node.get_value()

    if (os.path.isfile(current_path)):
        return node

    for i in os.listdir(current_path):
        node.child.append(Node(os.path.join(current_path, i)))
        get_all_paths(node.child[-1])

    return node

def main():
    root = Node('.')

    paths = get_all_paths(root)
    print(paths.get_value())
    for i in paths.child:
        print("\t", end='')
        print(i.get_value())
        if (len(i.child)):
            for j in i.child:
                print("\t\t", end='') 
                print(j.get_value())
    # for i in paths:
    #     with open(i, 'rb') as f:
    #         data = f.read()
    #         hash1, hash2, hash3 = get_hash(data)
    #         print(f'{i} {hash1} {hash2} {hash3}')
    # print(get_hash('hello world'))


if __name__ == '__main__':
    main()
