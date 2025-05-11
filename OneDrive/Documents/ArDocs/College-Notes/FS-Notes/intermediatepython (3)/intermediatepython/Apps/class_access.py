class employee(object):
  def __private(self):
    print("private method declaration")

  def public(self):
    print("public method declaration")

  def __init__(self, name, sal):
    self.__name = name    # private attribute (double underscore)
    self._salary = sal  # protected attribute (single underscore)

  def callprivate(self):
    self.__private()

obj = employee("Ravi", 100000)
obj.public()
#obj.__private()
obj.callprivate()
obj._employee__private()

print(obj._salary)
#print(obj.__name)
print(obj._employee__name)
