import re

file = open("issues.txt", "r")   

for line in file:                                 
  print(line, end="")

file.seek(0,0)
print()

print("Code, ProjectCode, Count")
for line in file:                                 
  if re.search('->',line):
    print(','.join(re.findall('[0-9]+',line)))

file.close()