ol = [[1, 2, 3], [4, 5, 6], [7, 8, 'a']]

nl = ol
nl[2][2] = 9

print('Old List:', ol)
print('New List:', nl)
print(id(ol), id(nl))

ol.append([1, 1, 1])
print('Old List:', ol)
print('New List:', nl)
print(id(ol), id(nl))