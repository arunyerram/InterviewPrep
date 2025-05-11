class Account:
  ''' Account class '''
  def __init__(self, name, number, balance):
    print("initializer called with 3 arguments")
    self.accName = name
    self.accnumber = number
    self.accbalance = balance

  def withdraw(self, amount):
    self.accbalance -= amount

  def deposit(self, amount):
    self.accbalance += amount

  def show(self):
    print('Account name :', self.accName)
    print('Account number :', self.accnumber)
    print('Account balance :', self.accbalance)

customer = Account('Ravi', 'S101', 5000)
customer.withdraw(1000)
customer.deposit(2000)
customer.show()   # Account.show(customer)

print ("Account.__doc__:", Account.__doc__)
print ("Account.__name__:", Account.__name__)
print ("Account.__module__:", Account.__module__)