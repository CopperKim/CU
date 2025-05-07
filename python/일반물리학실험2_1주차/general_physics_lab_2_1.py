# import pandas as pd

# file = pd.read_csv("/Users/CU/vscode/python/일반물리학실험2_1주차/일반물리학실험2_1주차_3번.csv") # 파일 불러오기
# file = file[[col for col in file.columns if "Time" in col or "Angle" in col]] # Time, Angle column만 추출
# df_list = list(file[file.columns[i:i+2]] for i in range(0, 8, 2)) # 각 Time, Angle 쌍을 서로 다른 데이터프레임으로 저장
# for df in df_list : 
#     cur_length = df.columns[0]
#     print(cur_length)

#     df.columns = ["Time", "Angle"]
    
#     start_idx = 1 # 첫 극대점을 기준으로 시작 
#     while ( not (df["Angle"][start_idx - 1] <= df["Angle"][start_idx] and \
#                  df["Angle"][start_idx] > df["Angle"][start_idx+1]) ) : start_idx += 1

#     count = 0 
#     last_idx = start_idx # 10 번째 극대점의 인덱스를 저장
#     cur_idx = start_idx 

#     while(count < 10) : # 극대점을 10회 찾을 동안 반복
#         while ( not (df["Angle"][cur_idx - 1] <= df["Angle"][cur_idx] and \
#                  df["Angle"][cur_idx] > df["Angle"][cur_idx+1]) ) : cur_idx += 1
#         count += 1
#         print(cur_idx - last_idx)
#         last_idx = cur_idx
#         cur_idx += 2
    
#     print("count :", count)
#     print("start_idx :", start_idx)
#     print("last_idx :" , last_idx)
#     print("period of oscillation :", (df["Time"][last_idx]-df["Time"][start_idx])/count) # 진동 주기를 계산
#     print()

import numpy as np
import matplotlib.pyplot as plt

# 데이터 예제
x = [2, 4, 6, 8, 10, 12, 14]  # X 값 (0~10 범위, 20개)
y = [1.085, 0.84, 0.77, 0.744, 0.745, 0.765, 0.8]  # Y 값 (지수 함수와 코사인 곱)

# 그래프 그리기
plt.figure(figsize=(8, 4))

# 데이터 점 표시
plt.scatter(x, y, color='red', label='Data Points', marker='o')

# 그래프 설정
plt.xlabel('Distance between center of mass and rotaional axis (cm)')
plt.ylabel('Period of Oscillation (s)')
plt.xlim(0, 15)
plt.ylim(0, max(y) + 0.25)
plt.title('Period of Oscillation according to Distance between center of mass and roational axis')
plt.legend()
plt.grid(True)

# 그래프 출력
plt.show()