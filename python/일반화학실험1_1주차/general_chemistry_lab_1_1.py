import pandas as pd
import matplotlib.pyplot as plt

file = pd.read_csv("/Users/CU/vscode/python/일반화학실험1_1주차/general_chemistry_lab_1_1week.csv")

# 데이터 예제
distance = file["Distance (Bohr)"]
ground_state_energy = file["total energy of ground state (eV)"]
first_exited_state_energy = file["total energy of first exited state (eV)"]
second_exited_state_energy = file["total energy of second exited state (eV)"]

# 그래프 그리기
plt.figure(figsize=(8, 4))

# 데이터 점 표시
plt.plot(distance, ground_state_energy, color='red', linestyle='-', label='Ground state', marker='.')
plt.plot(distance, first_exited_state_energy, color='blue', linestyle='-', label="First exited state", marker='.')
plt.plot(distance, second_exited_state_energy, color='black', linestyle='-', label="Second exited state", marker='.')

# 그래프 설정
plt.xlabel('Distance between two nuclei (Borh)')
plt.ylabel('Total energy of state (eV)')
plt.xlim(0,8)
plt.ylim(min(ground_state_energy)-10, max(second_exited_state_energy) + 10)
plt.title('Total energy of H2+ orbital according to distance between nuclei')
plt.legend()
plt.grid(True)

# 그래프 출력
plt.show()