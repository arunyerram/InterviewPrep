class employee:
  def __init__(self, id, name, dept):
    self.id = id      
    self._name = name     # proj is protected (one underscore)
    self.dept = dept
  
  def show(self):
    print("Employee details ",self.id, self._name, self.dept)

class manager(employee):
  def __init__(self, id, name, dept, role, bonus):
    # calling parent class constructor
    employee.__init__(self, id, name, dept)
    self.role = role   
    self.__bonus = bonus    # private member variable (two underscores)
  
  def show_bonus(self):
    print("Bonus of",self.role,"is",self.__bonus)

e = employee("e101", "Subbu", "HR")
m = manager("e202", "Ravi", "IT", "Sales", "100000")

e.show()

# only the instance itself can change the __bonus variable
# and to show the value we have created a public function show_bonus()

m.show()
m.show_bonus()
#print(m.__bonus) # since it is private it is inaccessible directly
print(m._manager__bonus)

