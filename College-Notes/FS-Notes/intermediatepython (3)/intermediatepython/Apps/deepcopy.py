import copy

ol = [[1, 2, 3], [4, 5, [11, 12], 6], [7, 8, 9]]
nl = copy.deepcopy(ol)

print("Old list:", ol)
print("New list:", nl)
print(id(ol), id(nl))

ol.append([4, 4, 4])

print("Old list:", ol)
print("New list:", nl)

ol[1][1] = 'AA'

print("Old list:", ol)
print("New list:", nl)