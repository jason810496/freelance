# python-xlsx

using Numpy + Pandas + Matplotlib to visualize Data

Numpy / Pandas : create , delete , modify data list 
Matplotlib : visualize Data

## Numpy
### arange
```py
np.arange(3)
return>>> array([0, 1, 2])

np.arange(3,7)
return>>> array([3, 4, 5, 6])

np.arange(3,7,2)
return>>> array([3, 5])
```
### Set random seed
`np.random.seed( X )`
### Create random data list
- choice
```python
X = 10
Arr_Size = 20
arr = np.random.choice(X,Arr_Size)
```
return a np array in `Arr_Size` Size with random int element in range of [ 0 , `X`]

- randint
```python
Low = 10
High = 30
Row = 50
Column = 2
np.random.randint(Low,High,size=(Row, Column))
```

random int element in [`Low` , `High`] , np_array in `Row` X `Column`
## Pandas
### Series
### DataFrame

For visualizing data , either `df.plot.PLOT_TYPE` or `plt.PLOT_TYPE` could be use . (note that `df` stands for `pandas.DataFrame` and `plt` stands for `matplotlib.pyplot `) 
## Matplotlib 

All the following examples are in `Matplotlib-0.py`

- Pie plot

- Bar plot

- Scatter plot

- Line

- Box

### annotation

utilities : 
- add test to plot in various shape ( rect , circle  
- add arrow with text point From P1(x1,y1) to P2(x2,y2) 

Example: a arrow point from `(0.2,0.2)` to `(0.8,0.8)`
```py
ax.annotate("",
            xy=(0.2, 0.2), xycoords='data',
            xytext=(0.8, 0.8), textcoords='data',
            arrowprops=dict(arrowstyle="->",
                            connect8ionstyle="arc3"),
            )
```

`xy` : the position arrow point to
`xytest` : the position of the text
- `arrowsytle`

list of arrowstyle ( screenshot from matplotlib )

- `connectionstyle`
list of connectionstyle ( screenshot from matplotlib )

### various shape of box with text
```py
fig , ax = plt.subplots()
t = ax.text(
    x1, y1, "The_text_comment", color='The_text_color', rotation=45, size=15,
    bbox=dict(boxstyle="rarrow,pad=0.3" ) )
``` 
- `rarrow` : right arrow box
- `pad` : padding (same as css properity)

list of boxstyle

[document of annotation](https://matplotlib.org/3.5.1/tutorials/text/annotations.html#plotting-guide-annotation)

For example , the circle box with text can be presented by the following :
```py
ax.text(0.2,0.8, 'acircle with text', color='black', 
        bbox=dict(boxstyle="circle,pad=0.2",facecolor='none', edgecolor='green'))
```

### config

#### Resize image

```python
from matplotlib.pyplot import figure

figure(figsize=(8, 6), dpi=80)
```

#### plt.rc

[ list of rc params ](https://matplotlib.org/3.5.1/api/matplotlib_configuration_api.html?highlight=rc#matplotlib.rcParams)


## Package requirements

xlrd

numpy

panda

openpyxl

matplotlib


### Reference

[document of annotation](https://matplotlib.org/3.5.1/tutorials/text/annotations.html#plotting-guide-annotation)

#### read .xlsx file

1. openpyxl

2. pandas

3. xlrd (fail)

#### convert pandas DataFrame to list
```python
tolist()

products_list = df.values.tolist()
```

### Preparation


#### pip install with requirements.txt

```shell
python -m pip install -r requirements.txt

pip install -r requirements.txt
```
https://note.nkmk.me/en/python-pip-install-requirements/

#### Using .xlsx file in Ubuntu 


install LiberOffice :

```shell
sudo apt-get update
sudo apt-get install libreoffice
```




