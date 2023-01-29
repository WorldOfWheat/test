from hashlib import *

hash = md5()

f = open('C:\\Users\\a3028\\Downloads\\erase.exe', 'rb')
hash.update(f.read())
f.close()
a = hash.hexdigest()

hash=md5()

f = open('C:\\Users\\a3028\\Downloads\\hello.exe', 'rb')
hash.update(f.read())
f.close()
b = hash.hexdigest()

print(a, b)