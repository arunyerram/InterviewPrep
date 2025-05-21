import re

str = "The rainS in Spain"
x = re.search(r"\bS\w+", str)
if x:
  print(x.span())
  print(x.string)
  print(x.group())

x = re.search(r"inS\b", str)
if x:
  print(x.span())
  print(x.string)
  print(x.group())
  