from collections import defaultdict
from random import randrange
from sortedcontainers import SortedList

dict = {}
dict['test'] = SortedList()
for _ in range(50):
    dict['test'].add(randrange(1, 51))

print(dict['test'])

dict2 = defaultdict(SortedList())