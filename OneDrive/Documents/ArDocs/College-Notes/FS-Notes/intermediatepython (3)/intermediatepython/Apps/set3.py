s1 = set([2,3])
s2 = set([2,3,4])

print(s1.issubset(s2))
print(s2.issubset(s1))

print(s1.issuperset(s2))
print(s2.issuperset(s1))

print(s1, id(s1))

s1.add(5)
s1.remove(2)    # key error if the element doesn't exist
s1.discard(2)
print(s1, id(s1))

s4 = s2.copy()
print(s4)
s1.update(s2)
print(s1, id(s1))

print(3 in s4)
print(1 in s4)
print(3 not in s4)
print(1 not in s4)

print(s1.isdisjoint(s2))  # true if null intersection

s4.pop()
print(s4)
s4.pop()
print(s4)
s1.clear()
print(s1)
