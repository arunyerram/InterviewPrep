class textfile:
  ntfiles = 0 # count of number of textfile objects
  def __init__(self, fname):
    textfile.ntfiles += 1
    self.name = fname # name
    self.fh = open(fname) # handle for the file
    self.lines = self.fh.readlines()
    self.nlines = len(self.lines) # number of lines
    self.nwords = 0 # number of words
    self.nchars = 0 # number of characters
    self.wordcount()
    self.charcount()

  def wordcount(self):
    "finds the number of words"
    for l in self.lines:
      w = l.split()
      self.nwords += len(w)

  def charcount(self):
    "finds the number of chars"
    for l in self.lines:
      self.nchars += len(l)
 
  def grep(self, target):
    "prints out all lines containing target"
    for l in self.lines:
      if l.find(target) >= 0:
        print(l)