while True:
  try:
    val = int(input("Please enter a number: "))
    print(val)
    break
  except ValueError:
    print("Entered data is not numeric. Try again.")