class Employee(object):
  def __init__(self, empDict, dept):
    print("__init__")
    super().__setattr__('data', dict())
    self.data = empDict
    self.department = dept
    print(self.__dict__.items())

  def __getattr__(self, name):
    print("__getattr__", name)
    if name in self.data:
      return self.data[name]
    else:
      return 0

  def __setattr__(self, key, value):
    print("__setattr__", key, value)
    if key in self.data:
      self.data[key] = value
    else:
      super().__setattr__(key, value) 
 
emp = Employee({'age': 23, 'name': 'John'}, 'HR')
print(emp.age)
print(emp.name)
print(emp.data)
print(emp.salary)
 
emp.salary = 50000
print(emp.salary)

#delattr(emp, 'salary')
del(emp.salary)
print(emp.salary)