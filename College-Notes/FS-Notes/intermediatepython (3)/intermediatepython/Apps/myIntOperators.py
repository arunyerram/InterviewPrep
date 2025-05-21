class myInt:
  def __init__(self, val):
    print("__init__")
    self.num = val

  def __call__(self, val): 
    print("__call__")
    self.num = val

  def __eq__(self, other):
    if self.num == other.num:
      return "both objects are equal"
    else:
      return "both objects are not equal"

  def __lt__(self, other):
    if self.num < other.num:
      return "first object lesser than other"
    else:
      return "first object not lesser than other"

  def __gt__(self, other):
    if self.num > other.num:
      return "first object greater than other"
    else:
      return "first object not greater than other"

  def __ge__(self, other):
    if self.num >= other.num:
      return "first object greater than equal to other"
    else:
      return "first object not greater than equal to other"

  def __str__(self):
    return str(str(self.num))

  def __repr__(self):
    return "myInt(" + str(self.num) + ")"

obj1 = myInt(5) # __init__ Initialise newly created object
print(obj1.num)
obj1(20)        # __call__
print(obj1.num)

obj2 = myInt(5)
print (obj1 > obj2)
print (obj1 >= obj2)
print (obj1 < obj2)
print(obj1 == obj2)

print(obj1)
print(repr(obj1))
