import re

list = ["Issue12 testing", "Bug  development", "CR22 documentation"]

for element in list:
  matchObj = re.match("([ibc]\w+)\W+(d\w+)", element, re.M|re.I)
  if matchObj:
    print(matchObj.groups())
  else:
    print("No match found for:", element)

data = "Qualcomm Python Training. Training starts in India at 9:30 AM IST."
matchObj = re.match('Qualcomm\W+(\w+)\W+Training(.*?)India', data, re.M|re.I|re.S)

if matchObj:
  print("Matched string : ", matchObj.group())
  print("Matched string 1: ", matchObj.group(1))
  print("Matched string 2: ", matchObj.group(2))
else:
   print("No match result")

data = "Qualcomm Python Training. Training starts in India at 9:30 AM IST."

searchObj = re.search('Training(.*) in (.*?) .*', data, re.M|re.I|re.S)

if searchObj:
   print("Search string : ", searchObj.group())
   print("Search string 1 : ", searchObj.group(1))
   print("Search string 2 : ", searchObj.group(2))
else:
   print("No search result")
