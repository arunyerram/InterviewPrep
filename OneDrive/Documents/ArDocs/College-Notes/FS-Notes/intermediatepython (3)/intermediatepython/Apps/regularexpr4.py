import re

phone = 'Telephone: 040-12345678';

searchNo = re.search('Telephone:\s+(\d{3}-\d{8}$)', phone, re.M)

if searchNo:
   print("Search string : ", searchNo.group())
   print("Search string 1 : ", searchNo.group(1))
else:
   print("No search result")

line="What is the best time to call you, time now is 10:30 AM";

searchData = num = re.sub('the.*time', "tested", line)
print("searchData : ", searchData)

searchData = num = re.sub('the.*?time', "tested", line)
print("searchData : ", searchData)