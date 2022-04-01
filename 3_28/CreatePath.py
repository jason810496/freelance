
# BOX
import random

n = 6
total = 0 
PointList = [ [142,371] , [142,570] , [429,570] , [429,716] , [837,716] , [837,923] ]

for i in range(n-1):
    # x same
    if PointList[i][0] == PointList[i+1][0]:
        total+=PointList[i+1][1] - PointList[i][1]+1
    else: # y same
        total+=PointList[i+1][0] - PointList[i][0]+1

DataStr = str(total)+"\n"

Upper = 50
Lower = 0

def Rand():
    return random.randint(Lower, Upper)


for k in range(n-1):
    if PointList[k+1][0] == PointList[k][0] :
        x = PointList[k][0]
        y1 = PointList[k][1]
        y2 = PointList[k+1][1]

        for y in range(y1,y2,1):
            DataStr += f"{x} {y} {Rand()} {Rand()} {Rand()} {Rand()} {Rand()}\n"

    else:
        y= PointList[k][1]
        x1 = PointList[k][0]
        x2 = PointList[k+1][0]

        for x in range(x1,x2,1):
            DataStr += f"{x} {y} {Rand()} {Rand()} {Rand()} {Rand()} {Rand()}\n"
        

# and the last one

DataStr += f"{PointList[n-1][0]} {PointList[n-1][1]} {Rand()} {Rand()} {Rand()} {Rand()} {Rand()}\n"

f= open("PATH.txt" , "w")
f.write(DataStr)
f.close()
# PATH