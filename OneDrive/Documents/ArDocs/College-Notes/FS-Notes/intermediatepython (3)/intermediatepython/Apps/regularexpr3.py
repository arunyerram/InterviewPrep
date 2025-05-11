import re

phone = "123-456-7890" 
num = re.sub('#.*$', "", phone)
print("Phone Num : ", num)

Number = "123 qualcomm 456genesis  "

# Replace the first 5 occurrences
num = re.sub('\D', "", Number, 5)     
print("Num1 : ", num)

num = re.sub('\d', "", Number)     
print("Num2 : ", num)

num = re.sub('\w', "A", Number)     
print("Num3 : ", num)

# Replace the first 4 occurrences
num = re.sub('\W', "%", Number, 4)     
print("Num4 : ", num)

num = re.sub('\s', "#", Number)   
print("Num5 : ", num)

# Replace the first 2 occurrences
num = re.sub('\s', "#", Number, 2)   
print("Num6 : ", num)