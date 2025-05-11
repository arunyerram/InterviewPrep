class test(object):
  def __init__(self):
    print ("Init")

  def __del__(self):
    print ("del", id(self))

obj1 = test()
obj2 = test()
print(id(obj1), id(obj2))
obj1 = obj2
print("one")
obj2 = ""
print("two")
