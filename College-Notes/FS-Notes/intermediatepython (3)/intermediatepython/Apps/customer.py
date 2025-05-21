number = input("Enter number to search: ")

filein = open('customer.txt')

for record in filein:
  if(number in record):
    print(record)

filein.close()