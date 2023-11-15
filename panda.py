import pandas as pd

df = pd.read_excel('C:/Users/LLJ24/Downloads/pydata02.xlsx')
df.head()

#获取列名
all_cols = df.columns
print(all_cols)
cols = list(df.columns)

#获取列数据
col_data = df[u'大气温度']
#mul_col_data = df[u'日期',u'大气温度',u'气象站气压',u'相对湿度',u'类别']

#获取行数据
#row_data = df.iloc[row_index]
all_data = df.values
mul_row_data = df.iloc[2:4]

#获取单元格数据
#cell_data = df.iloc[row_index][col_index]


print(col_data.quantile())
print(col_data.median())

#缺失值,行axis=1
df.isnull().any()
print(df[u'大气温度'].isnull().sum())

print(df[u'类别'].nunique())
print(df[u'类别'].unique())

print(df[u'类别'].value_counts())

for i in range(0,216,8):
   print(df[u'气象站气压'][i:i+8].mean())
   
from sklearn import tree
clf = tree.DecisionTreeClassifier(criterion="entropy")
clf = clf.fit(df[u'大气温度'],df[u'气象站气压'],df[u'相对湿度'])
result = clf.socre(28,800,80)