import module1

f1 = module1.textfile('module1.py')
f2 = module1.textfile('moduledemo.py')
print ("the number of text files open is", module1.textfile.ntfiles)
print ("here is some information about them (name, lines, words):")
for f in [f1, f2]:
  print (f.name, f.nlines, f.nwords, f.nchars)

f1.grep('self')
