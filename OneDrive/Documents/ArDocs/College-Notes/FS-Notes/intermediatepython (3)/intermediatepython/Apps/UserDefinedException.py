class WithdrawException(Exception):
  def __init__(self, value):
    self.value = value
    self.message = "Cannot withdraw as the amount to withdraw is more than allowed"

class account:
  def __init__(self, name, number, balance):
    self.name = name
    self.number = number
    self.balance = balance

  def withdraw(self, amt):
    newbalance = self.balance - amt
    if(newbalance < 1000):
      raise(WithdrawException(amt))
    self.balance = newbalance

  def deposit(self, amt):
    self.balance += amt

  def show(self):
    print("Name is " + self.name)
    print("number is ", self.number)
    print("Balance is ", self.balance)

customer = account("Cust1", 200, 4000)

try:
  customer.deposit(2000)
  customer.withdraw(8500)
  customer.show()
except WithdrawException as we:
  print(we.message, we.value)
  print(type(we))
except Exception as e:
  print(repr(e))