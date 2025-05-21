s1 = frozenset([2,3,1])
s2 = frozenset([3,4,5])
s3 = frozenset([])

s3 = s1.union(s2)
print(s3)
s3 = s1 | s2                  # Union alternative notation
print(s3)
print(len(s3))

for value in s3:
  print(value, end = " ")

print()

s3 = s1.intersection(s2)
print(s3)
s3 = s1 & s2                  # Intersection alternative notation
print(s3)

s3 = s1.difference(s2)
print(s3)
s3 = s1 - s2                  # Difference alternative notation
print(s3)

s3 = s1.symmetric_difference(s2)
print(s3)
s3 = s1 ^ s2                  # Symmetric difference alternative notation
print(s3)
