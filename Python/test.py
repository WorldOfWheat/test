from Crypto.Hash import SHA512, SHA1, MD5
import os
import sqlite3

class Node:
    def __init__(self, value):
        self.value = value
        self.child = []
        self.hashs = [3]

    def add_child(self, child):
        self.child.append(child)

    def get_value(self):
        return self.value

def get_hash(data):
    # data = data.encode()

    md5 = MD5.new();
    sha1 = SHA1.new();
    sha512 = SHA512.new();

    md5.update(data[0])
    sha1.update(data[1])
    sha512.update(data[2])

    hash1 = md5.digest()
    hash2 = sha1.digest()
    hash3 = sha512.digest()
    return (hash1, hash2, hash3)

def get_all_paths(node):
    current_path = node.get_value()

    if (os.path.isfile(current_path)):
        return node

    dirs = os.listdir(current_path)
    print(current_path, dirs)
    if (len(dirs) == 0):
        return node

    for i in dirs:
        child_path = os.path.join(current_path, i)
        node.child.append(Node(child_path))
        get_all_paths(node.child[-1])

    return node

def get_all_hashs(node):
    if (len(node.child) == 0):
        if (os.path.isdir(node.get_value())):
            node.hashs = (b'', b'', b'')
            return node.hashs
        
        with open(node.get_value(), 'rb') as f:
            data = f.read()
            node.hashs = get_hash((data, data, data))
            return node.hashs
    hashs = (b'', b'', b'') 
    for i in node.child:
        single_hash = get_all_hashs(i)
        hashs = get_hash(
            (
            hashs[0] + single_hash[0], 
            hashs[1] + single_hash[1], 
            hashs[2] + single_hash[2]
            )
        )
    node.hashs = hashs
    return hashs

def print_tree(node, count = 0):
    print('\t' * count, end='')
    if (len(node.child) == 0):
        print(node.value, node.hashs[0].hex())
        return
    print(node.value, node.hashs[0].hex())
    for i in node.child:
        print_tree(i, count + 1)

def main():
    root = Node('.')

    paths = get_all_paths(root)
    # for i in paths.child:
    #     print(i.get_value())
    hashs = get_all_hashs(paths)
    md5_hash = hashs[0].hex()
    sh1_hash = hashs[1].hex()
    sha512_hash = hashs[2].hex()
    print(md5_hash, sh1_hash, sha512_hash)
    print_tree(paths)


if __name__ == '__main__':
    main()
