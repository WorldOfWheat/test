from random import randrange
from collections import OrderedDict

od = OrderedDict()
for _ in range(5):
    od[randrange(0, 100)] = 0
print(od)
# arr = [];
# for _ in range(100):
#     arr.append(randrange(0, 5));
# for _ in range(int(1e6)):
#     arr.insert(randrange(0, len(arr)), randrange(0, 5))
# print(arr)