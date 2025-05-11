try:
  print(1/0)
  print(val)
  str='Genesis'
  print(str + 3)

except ZeroDivisionError as z:
  print(repr(z))

except NameError as n:
  print(str(n))

except TypeError as t:
  print(repr(t))

except:
  print("Some unhandled exception occured")
  raise
 