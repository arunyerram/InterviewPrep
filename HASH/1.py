from collections import defaultdict

n = int(input())
array = []
hash_map = defaultdict(int)

for i in range(0, n):
    num = int(input())
    array.append(num)
    hash_map[num] += 1

q = int(input())

for i in range(0, q):
    query = int(input())
    count = hash_map[query]
    print(count)
