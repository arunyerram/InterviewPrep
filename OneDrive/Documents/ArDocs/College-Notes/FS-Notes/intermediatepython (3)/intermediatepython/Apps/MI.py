class base1:
  def __init__(self):
    print("base1 Constructor called")

  def m1(self):
    print("base1 m1 called")

  def m2(self):
    print("base1 m2 called")

class base2:
  def __init__(self):
    print("base2 Constructor called")

  def m1(self):
    print("base2 m1 called")

  def m3(self):
    print("base2 m3 called")

class derived(base1, base2):
  def __init__(self):
    print("derived Constructor called")

  def m2(self):
    print("derived m2 called")

  def m4(self):
    print("derived m4 called")

obj = derived()
obj.m1()
obj.m2()
obj.m3()
obj.m4()