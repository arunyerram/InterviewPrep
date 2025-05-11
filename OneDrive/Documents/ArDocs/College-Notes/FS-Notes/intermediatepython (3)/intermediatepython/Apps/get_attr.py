'''
__getattr__
Python will call __getattr__ method whenever you request an attribute that hasn't
already been defined. In the following example Count has no __getattr__ method.
Now in main when we access both obj1.mymin and obj1.mymax attributes everything 
works fine. But when we access obj1.mycurrent attribute -- Python gives
AttributeError: 'Count1' object has no attribute 'mycurrent'
'''

class Count1():
  def __init__(self,mymin,mymax):
    self.mymin=mymin
    self.mymax=mymax

obj1 = Count1(1,10)
print(obj1.mymin)
print(obj1.mymax)
print(obj1.mycurrent) 

'''
The class Count2 has __getattr__ method. Now when we access obj2.mycurrent
attribute -- python returns whatever we have implemented in __getattr__ method. 
When we try to call an attribute which doesn't exist, python creates that attribute and set it to integer value 0.
'''

class Count2:
  def __init__(self,mymin,mymax):
    self.mymin=mymin
    self.mymax=mymax    

  def __getattr__(self, item):
    print("Count2 __getattr__ ", item)
    self.__dict__[item]=0
    return 0

obj2 = Count2(1,10)
print(obj2.mymin)
print(obj2.mymax)
print(obj2.mycurrent)

'''
__getattribute__
Now lets see the __getattribute__ method. If you have __getattribute__ method
in your class, python invokes this method for every attribute regardless whether 
it exists or not. So why we need __getattribute__ method? One good reason is that
you can prevent access to attributes and make them more secure as shown in the following example.

Whenever someone try to access my attributes that starts with substring 
'cur' python raises AttributeError exception. Otherwise it returns that attribute.
'''

class Count3:
  def __init__(self,mymin,mymax):
    self.mymin=mymin
    self.mymax=mymax
    self.current=None

  def __getattribute__(self, item):
    print("Count3 __getattribute__ ", item)
    if item.startswith('cur'):
      raise AttributeError
    return object.__getattribute__(self,item) 
    # or you can use ---return super().__getattribute__(item)

obj3 = Count3(1,10)

if(isinstance(obj3, object)):
  print("yes")

print(obj3.mymin)
print(obj3.mymax)
print(obj3.current)

'''
If your class contain both getattr and getattribute magic methods then
__getattribute__ is called first. But if __getattribute__ raises AttributeError exception
then the exception will be ignored and __getattr__ method will be invoked. 
'''

class Count4(object):
  def __init__(self,mymin,mymax):
    self.mymin=mymin
    self.mymax=mymax
    self.current=None

  def __getattr__(self, item):
    print("Count4 __getattr__", item)
    self.__dict__[item]=0
    return 0

  def __getattribute__(self, item):
    print("Count4 __getattribute__", item)
    if item.startswith('cur'):
      print("AttributeError")
      raise AttributeError

    return object.__getattribute__(self,item)

obj4 = Count4(1,10)
print(obj4.mymin)
print(obj4.mymax)
print(obj4.current)
