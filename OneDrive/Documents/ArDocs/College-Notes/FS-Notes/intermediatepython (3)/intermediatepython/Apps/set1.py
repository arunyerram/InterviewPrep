colors = set()
colors.add("red")
print(colors)
colors.update(['green', 'blue', 'yellow', 'red', 'white', 'blue'])
print(colors)

for color in colors:
  print(color)

print(min(colors), max(colors), len(colors))

colors.discard('blue')
print(colors)

print(colors.pop())
print(colors)

colors.clear()
print(colors)