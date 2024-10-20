import requests
from bs4 import BeautifulSoup
import os 
import re

headers = {'User-Agent' : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/129.0.0.0 Safari/537.36'}

folder_path = os.path.dirname(os.path.realpath(__file__))
files = os.listdir(folder_path)
pattern = re.compile(r'^(\d+)\.cpp$')

for fileName in files : 
    match = pattern.match(fileName)
    if (match) :
        url = 'https://www.acmicpc.net/problem/' + (str(fileName))[:-4]
        data = requests.get(url, headers=headers)

        soup = BeautifulSoup(data.text, 'html.parser')

        old_file_path = os.path.join(folder_path, fileName)
        new_file_name = (str(soup.find('title')))[len(fileName)-1:]
        new_file_path = os.path.join(folder_path, new_file_name)
        os.rename(old_file_path, new_file_path)