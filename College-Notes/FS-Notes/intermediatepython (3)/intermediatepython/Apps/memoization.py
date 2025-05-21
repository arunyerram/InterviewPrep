'''
Memoization effectively refers to remembering results of method calls based on the 
method inputs and then returning the remembered result rather than computing the result 
again.
'''

def factorial(k):
  if k < 2: return 1
  return k * factorial(k - 1)

print(factorial(5))

factorial_memo = {}

def factorialM(k):
  if k < 2: return 1
  if k not in factorial_memo:
    factorial_memo[k] = k * factorialM(k-1)
  return factorial_memo[k]

print(factorialM(5))
