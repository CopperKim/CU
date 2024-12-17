import os 
import re

folder_path = os.path.dirname(os.path.realpath(__file__))
files = os.listdir(folder_path)
pattern = re.compile(r'^(\d+)\.cpp$')

for fileName in files : 
    match = pattern.match(fileName)
    if (match) : 
        print(fileName)