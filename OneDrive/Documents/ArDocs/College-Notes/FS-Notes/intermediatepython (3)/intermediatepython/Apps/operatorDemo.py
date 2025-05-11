import inspect

def line_number():
   '''Returns the current line number in our program'''
   return inspect.currentframe().f_back.f_lineno

class MyComplex:
  def __init__(self, rp = 1, ip = 2):
    print("C", "Constructor called")
    self.rpart = rp
    self.ipart = ip

  def __del__(self):
    print("D", "destructor called",  id(self))
  
  def __eq__(self, other):
    print("E", "__eq__ called")
    if (isinstance(other, MyComplex)):
      return ((self.rpart == other.rpart) and (self.ipart == other.ipart))
    else:
      return "NotImplemented"

  def __ne__(self, other):
    print("NE", "__ne__ called")
    # By using the == operator, the returned NotImplemented is handled correctly.
    return not self == other

  def __add__(self, other):
    print("A", "__add__ called")
    if(hasattr(other, "rpart") and hasattr(other, "ipart")):
      return (MyComplex(self.rpart + other.rpart, self.ipart + other.ipart))

obj1 = MyComplex(4)
print(line_number(), id(obj1), obj1.rpart, obj1.ipart)

obj2 = MyComplex(2)
print(line_number(), id(obj2), obj2.rpart, obj2.ipart)

if(obj1 == obj2):
  print(line_number(), "Equal")
else:
  print(line_number(), "Not Equal")

i = 10
print(line_number(), obj1 == i)

obj3 = obj1 + obj2
print(line_number(), id(obj3), obj3.rpart, obj3.ipart)

if(obj1 != obj2):
  print(line_number(), "Not Equal")
else:
  print(line_number(), "Equal")
