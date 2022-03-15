import matplotlib.pyplot as plt

import pandas as pd

Label_list = []
Value = []
  

# Load the xlsx file
excel_data = pd.read_excel('DATA/test0.xlsx')

Raw_list = excel_data.values.tolist()
  
for row in Raw_list:

    Label_list.append(row[0])
    Value.append(row[1])

plt.pie( Value,labels = Value ,autopct = '%.2f%%')
plt.title('Preference of OS', fontsize = 20)

plt.savefig("IMAGE/test0.svg")

plt.show()