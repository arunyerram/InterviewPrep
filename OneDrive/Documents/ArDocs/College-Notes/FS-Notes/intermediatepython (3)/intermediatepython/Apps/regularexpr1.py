import re

data = "Python is used in Machine Learning"

result = re.search("^Python.*Learning$", data)
if (result):
   print("Match")
else:
   print("No match")

searchObj = re.search("\s", data)
print("First white-space character is located @ position:", searchObj.start())

searchObj = re.split("\s", data)
print(searchObj)

searchObj = re.sub("\s", "_", data)
print(searchObj)

searchObj = re.search("used", data)
print(searchObj)