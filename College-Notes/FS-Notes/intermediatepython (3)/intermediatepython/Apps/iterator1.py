s = ['a', 'b']
i = iter(s)
print(next(i))
print(next(i))

print()

class Reverse:
  "Iterator for looping over a sequence backwards"
  def __init__(self, data):
    self.data = data
    self.index = len(data)

  def __iter__(self):
    return self

  def __next__(self):
    if self.index == 0:
      raise StopIteration
    self.index = self.index - 1
    return self.data[self.index]

obj = Reverse('Genesis')
for char in obj:
  print(char)