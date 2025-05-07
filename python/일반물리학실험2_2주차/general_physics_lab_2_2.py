import pandas as pd
import matplotlib.pyplot as plt

file = pd.read_csv("/Users/CU/vscode/python/일반물리학실험2_2주차/일반물리학실험2_2주차_1번.csv")

df_up = pd.concat([file["Time 1 (s)"], file["Angle 1 12 (rad)"], file["Angle 1 34(rad)"]], axis = 1)
df_up = df_up.iloc[115:972, :]
df_none = pd.concat([file["Time 2 (s)"], file["Angle 2 12 (rad)"], file["Angle 2 34 (rad)"]], axis = 1)
df_none = df_none.iloc[:400,:]
df_down = pd.concat([file["Time 3 (s)"], file["Angle 3 12 (rad)"], file["Angle 3 34 (rad)"]], axis = 1)
df_down = df_down.iloc[:400, :]

# 그래프 그리기
plt.figure(figsize=(8, 4))

# 데이터 점 표시
# plt.plot(df_up[df_up.columns[1]], df_up[df_up.columns[2]], color='red', linestyle='-', marker='.')
# plt.plot(df_none[df_none.columns[1]], df_none[df_none.columns[2]], color='blue', linestyle='-', marker='.')
plt.plot(df_down[df_down.columns[1]], df_down[df_down.columns[2]], color='black', linestyle='-', marker='.')

# 그래프 설정
plt.xlabel(r'$\phi$ (rad)')
plt.ylabel(r'$\theta$ (rad)')
# plt.xlim(min(df_up[df_up.columns[1]].min(), df_none[df_none.columns[1]].min(), df_down[df_down.columns[1]].min()) , \
#          max(df_up[df_up.columns[1]].max(), df_none[df_none.columns[1]].min(), df_down[df_down.columns[1]].min()) )
# plt.ylim(min(df_up[df_up.columns[2]].min(), df_none[df_none.columns[2]].min(), df_down[df_down.columns[2]].min()) , \
#          max(df_up[df_up.columns[2]].max(), df_none[df_none.columns[2]].min(), df_down[df_down.columns[2]].min()) )
plt.title(r'result when $\dot{\theta}<0$')
plt.legend()
plt.grid(True)

# 그래프 출력
plt.show()