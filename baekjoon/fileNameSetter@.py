import os
import re

# 현재 디렉토리 내 모든 파일 목록 가져오기
files = os.listdir('.')

# 파일명이 .cpp로 끝나는지 확인할 정규표현식 패턴
pattern = re.compile(r'\.cpp$')

for file in files:
    print(file)
    # 정규표현식을 이용해 파일 확장자가 .cpp인지 확인
    if re.search(pattern, file):
        new_file = file.replace(' ', '_')  # 공백을 '_'로 치환
        if new_file != file:
            os.rename(file, new_file)
            print(f"Renamed '{file}' to '{new_file}'")