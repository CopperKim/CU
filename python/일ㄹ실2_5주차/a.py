import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.metrics import r2_score

p1 = pd.read_csv("/Users/CU/vscode/CU/python/일ㄹ실2_5주차/pressure_1.txt", delimiter = '\t')
p2 = pd.read_csv("/Users/CU/vscode/CU/python/일ㄹ실2_5주차/pressure_2.txt", delimiter = '\t')
v1 = pd.read_csv("/Users/CU/vscode/CU/python/일ㄹ실2_5주차/volume_1.txt", delimiter = '\t')
v2 = pd.read_csv("/Users/CU/vscode/CU/python/일ㄹ실2_5주차/volume_2.txt", delimiter = '\t')
t1 = pd.read_csv("/Users/CU/vscode/CU/python/일ㄹ실2_5주차/temperature_1.txt", delimiter = '\t')
t2 = pd.read_csv("/Users/CU/vscode/CU/python/일ㄹ실2_5주차/temperature_2.txt", delimiter = '\t')

# pv graph 

p = np.array(p1[p1.columns[1]])
v = np.array(v1[v1.columns[1]])

lnp = np.log(p)
lnv = np.log(v)

coeffs1 = np.polyfit(lnp, lnv, 1)
est_y = lnp * coeffs1[0] + coeffs1[1]

print(coeffs1)
gamma = -1/coeffs1[0]
print(gamma)

pvgamma = p * (v ** gamma)

print(pvgamma)

const = np.average(pvgamma)
est_pvgamma = np.array([const] * p.size)

print("average pv^gamma : ", const)

# # 그래프 그리기
# plt.figure(figsize=(8, 4))

# # 데이터 점 표시
# plt.scatter(x, y, color='red', marker='.')

# # 그래프 설정
# plt.xlabel('ln T')
# plt.ylabel('ln V')
# plt.title('ln T vs ln V graph')
# plt.legend()
# plt.grid(True)

# 그래프 출력
# plt.show()

# tv graph
