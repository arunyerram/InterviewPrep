# from one import m1 as twom1
# from two import m1 as onem1
# # import one
# # import two
# twom1()
# onem1()

# i = 10
# j = 10
# k = 20

# print(id(i), id(j), id(k))
# j = j+10
# print(id(i), id(j), id(k))


s1 = "hello"
s2 = s1

print(id(s1), id(s2))
s2 = s2 + "world"
print(id(s1), id(s2))
print(s1, s2)
# s1[0] = "H"
print(s1[0])