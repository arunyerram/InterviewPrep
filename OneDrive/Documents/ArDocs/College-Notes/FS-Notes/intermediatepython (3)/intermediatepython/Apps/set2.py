tuple1 = (1,2,3)
list1 = [2,3,4]

s1 = set(tuple1)
s2 = set(list1)
s3 = {5, 2, 7, 9, 2, 7}
print(s3, type(s3))
print(s1, id(s1))

s1.union(s2)
print(s1.union(s2))
print(s1, id(s1))
s1 = s1 | s2                  # Union alternative notation
print(s1, id(s1))
print(len(s1))

s3 = s1.intersection(s2)
print(s3)
s3 = s1 & s2                  # Intersection alternative notation
print(s3)

s3 = s1.difference(s2)
print(s3)
s3 = s2 - s1                  # Difference alternative notation
print(s3)

s1 = set(tuple1)
s3 = s1.symmetric_difference(s2)
print(s3)
s3 = s1 ^ s2                  # Symmetric difference alternative notation
print(s3)