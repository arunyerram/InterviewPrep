from collections import Counter
import re

text = """Python is Interactive :
Python has an interactive console where you get a Python prompt (command line)
and interact with the interpreter directly to write and test your programs. 
This is useful for mathematical programming.

Interpreted : Python programs are interpreted, takes source code as input, and
then compiles (to portable byte-code) each statement and executes it 
immediately. No need to compiling or linking

Extendable : Python is often referred to as a "glue" language, meaning that it
is capable to work in mixed-language environment. The Python interpreter is 
easily extended and can add a new built-in function or modules written in 
C/C++/Java code."""

words = re.findall('\w+',text)

print(Counter(words).most_common(10))
