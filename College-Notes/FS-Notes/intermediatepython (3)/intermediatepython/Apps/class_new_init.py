# In our case the code returns test._dict('key') which is the same class as cls, 
# so __init__ will be executed.

class test(object):
  """Use __new__ when you need to control the creation of a new instance"""
  _dict = dict()

  def __new__(cls):
    """new method to create an instance"""
    if ('key' in test._dict):
      print("Exists")
      print(type(test._dict['key']))
      return test._dict['key']
    else:
      print("New")
      return super().__new__(cls)

  def __init__(self):
    """init method to initialize the state.  It is like a constructor"""
    print ("Init")
    test._dict['key'] = self

obj1 = test()
obj2 = test()
print(id(obj1), id(obj2))

print(obj1.__doc__)
print(obj1.__new__.__doc__)
print(obj1.__init__.__doc__)