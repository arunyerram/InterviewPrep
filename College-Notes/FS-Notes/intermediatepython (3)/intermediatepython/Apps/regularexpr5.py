import re

data = "Python is used in Machine Learning"
result = re.findall("in", data)
print(result)

mailIds = 'rtapadia@gmail.com, info2hotmail.com, testing@yahoomail.com'
emails = re.findall(r'[\w\.-]+@[\w\.-]+.[\w\.-]', mailIds)
print("Found emails:", emails)
for email in emails:
  print(email)

str = "Genesis   Insoft Limited   Hyderabad."
lst = re.split("\s", str)
print(lst)

# Split @ the 3rd occurrence
lst = re.split("\s", str, 2)
print(lst)

pattern = re.compile('python')
result = pattern.findall('training in python. Scripting language python')
print(result)
result1 = pattern.findall('training in python @ qualcomm')
print(result1)