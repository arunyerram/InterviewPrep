class Squares(object):
  def __init__(self, start, stop):
    self.start = start
    self.stop = stop

  def __iter__(self): 
    return self

  def __next__(self):
    if self.start >= self.stop:
      raise StopIteration

    result = self.start * self.start
    self.start += 1
    return result

  def current(self):
    return self.start

obj = Squares(5, 10)
objIter = iter(obj)
print(obj.current())
print(next(objIter))
print(obj.current())

for item in objIter:
  print(item)