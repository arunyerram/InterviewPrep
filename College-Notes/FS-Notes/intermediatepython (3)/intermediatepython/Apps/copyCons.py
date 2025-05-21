
from copy import copy, deepcopy

class test(object):
  def __init__(self):
    print('init')
    self.val = 10
    self.lst = [2,3,4]

  def __copy__(self):
    print('__copy__', self.__dict__)
    cls = self.__class__
    result = cls.__new__(cls)
    print(result.__dict__)
    result.__dict__.update(self.__dict__)
    print(result.__dict__)
    return result

  def __deepcopy__(self, memo):
    cls = self.__class__
    result = cls.__new__(cls)
    memo[id(self)] = result
    print(result)
    for k, v in self.__dict__.items():
      print(k, v)
      setattr(result, k, deepcopy(v, memo))
    return result

obj = test()
obj.val = 11
obj1, obj2 = copy(obj), deepcopy(obj)
obj.val = 12
obj.lst.append(5)
print(obj1.val, obj1.lst)
print(obj2.val, obj2.lst)


'''
It is possible to control how copies are made using the __copy__ and __deepcopy__ hooks.
__copy__() is called without any arguments and should return a shallow copy of the object.
__deepcopy__() is called with a memo dictionary, and should return a deep copy of the
object. 

Any member attributes that need to be deep-copied should be passed to copy.deepcopy(),
along with the memo dictionary, to control for recursion (see below).
'''