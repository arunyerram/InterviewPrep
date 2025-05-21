import sys

def func(nume, deno):
  if(deno == 0):
    raise ZeroDivisionError(nume, deno)
  return nume/deno

def main():
  try:
    result = func(10, 0)

  except ZeroDivisionError:
    print("Division by zero error")
    sys.exit(0)
  else:
    print("result is", result)
  finally:
    print("In finally block")

  print("After finally block")

main()


'''
sys.exit([arg])
Exit from Python. This is implemented by raising the SystemExit exception, 
so cleanup actions specified by finally clauses of try statements are honored,
and it is possible to intercept the exit attempt at an outer level.

The optional argument arg can be an integer giving the exit status (
defaulting to zero), or another type of object. If it is an integer, 
zero is considered 'successful termination' and any nonzero value is 
considered 'abnormal termination' by shells and the like. 

Since exit() ultimately 'only' raises an exception, it will only exit the
process when called from the main thread, and the exception is not intercepted.
'''