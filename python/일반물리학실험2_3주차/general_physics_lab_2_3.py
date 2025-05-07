import pandas as pd
import matplotlib.pyplot as plt

file1 = pd.read_csv("/Users/CU/vscode/CU/python/일반물리학실험2_3주차/exp3_0.5cm.txt", delimiter='\t')

print(file1)

x1 = file1[file1.columns[0]][:-15]
y1 = file1[file1.columns[1]][:-15]

plt.plot(x1, y1, color="black", linestyle="-", marker=".", label = '0.5cm')

file2 = pd.read_csv("/Users/CU/vscode/CU/python/일반물리학실험2_3주차/exp3_1cm.txt", delimiter='\t')

print(file2)

x2 = file2[file2.columns[0]][3:-10]
y2 = file2[file2.columns[1]][3:-10]

plt.plot(x2, y2, color="red", linestyle="-", marker=".", label = '1cm')

file3 = pd.read_csv("/Users/CU/vscode/CU/python/일반물리학실험2_3주차/exp3_2cm.txt", delimiter='\t')

print(file3)

x3 = file3[file3.columns[0]][3:-10]
y3 = file3[file3.columns[1]][3:-10]

plt.plot(x3, y3, color="blue", linestyle="-", marker=".", label = '2cm')

# 그래프 설정
plt.xlabel(r'Frequency $\mathrm{(s^{-1})}$')
plt.ylabel(r'Angular Velocity Amplitude $\mathrm{(rad \cdot s^{-1})}$')
plt.title(r'Resonance curve of disk')
plt.legend()
plt.grid(True)

# 그래프 출력
plt.show()