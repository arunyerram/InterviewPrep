def wordFrequency(str):
  str = str.split()
  uniqueWords = set(str)
  print(uniqueWords)

  for word in uniqueWords:
    print("Frequency of ", word, " = ", str.count(word))

str = "hello world hello Qualcomm Training at Qualcomm"
wordFrequency(str)      