'''
"a" - Append - will append to the end of the file

"w" - Write - will overwrite any existing content


f = open("demofile3.txt", "w")
f.write("Woops! I have deleted the content!")
f.close()

#open and read the file after the appending:
f = open("demofile3.txt", "r")
print(f.read()) 


// read data by line

file1 = open('myfile.txt', 'r')
while True:
    count += 1
 
    # Get next line from file
    line = file1.readline()
 
    # if line is empty
    # end of file is reached
    if not line:
        break
    print("Line{}: {}".format(count, line.strip()))
 
file1.close()
'''

# BOX
import random


x1 = 182
y1 = 535
x2 = 259
y2 = 983

DataStr = f"{x1} {y1} {x2} {y2}\n" 
# n = (x2-x1+1)*(y2-y1+1)

Upper = 50
Lower = 0
def Rand():
    return random.randint(Lower, Upper)

for i in range(x1,x2+1,1):
    for j in range(y1,y2+1,1):
        print(i,j)
        DataStr += f"{i} {j} {Rand()} {Rand()} {Rand()} {Rand()} {Rand()}\n"

f= open("BOX.txt" , "w")
f.write(DataStr)
f.close()
# PATH