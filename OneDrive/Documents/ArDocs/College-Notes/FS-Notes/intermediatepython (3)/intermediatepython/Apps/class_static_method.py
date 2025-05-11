from datetime import date 
  
class Person: 
  def __init__(self, name, age): 
    self.name = name 
    self.age = age 
    
  # A class method to create a Person object by birth year. 
  # A class method receives the class as implicit first argument, 
  # just like an instance method receives the instance

  @classmethod
  def fromBirthYear(cls, name, year): 
    return cls(name, date.today().year - year) 
    
  # A static method to check if a Person is adult or not. 
  # A static method does not receive an implicit first argument.

  @staticmethod
  def isAdult(age): 
    return age > 18

  def isChild(self): 
    return self.age <= 18
  
person1 = Person('Subbu', 15) 
person2 = Person.fromBirthYear('Satyam', 1991) 
print(person1.age) 
print(person2.age)   
print(Person.isAdult(12)) 
print(person1.isChild()) 
