

# A function that check the input number is out of range
# if : out of range -> return true ( so that the user have to input again )
# else : return false ( keep on next section )

def check_range( n ):
    if( n<1 or n>4 ):
        print( "error : number out of range")
        return True

    return False

# Nested loop that print stairs 
def Function1():
    n = 5

    for i in range(n+1): # i : [1,5]
        cnt = n-i
        for j in range(cnt): # print the space 
            print(' ',end='')
        for j in range(i): # print number
            print(i,end='')
        print("")

# list + enumerate
def Function2():
    words = 'I want to all PASS this semester'
    span = 3

    # cut the string in size of 3 and make it a list
    words_list = list( enumerate([words[i:i+span] for i in range(0, len(words), span)] ) )

    # print( words_list 
    # for debug

    # the first 3 element keep remain order
    words_list = words_list[0:3:]+words_list[10:2:-1] # reserse the element from [2,10]

    print( words_list )

def Function3():
    # Data
    playerA = ['A13' , 'A5' , 'B1' , 'C4' , 'D12' ]
    playerB = ['A2' , 'A12' , 'B8' , 'C9' , 'D11' ]
    playerC = ['A11' , 'A4' ,'B11' , 'C13' , 'D8' ]
    playerD = ['A3' , 'A9' , 'B2' ,'C12' , 'D3'  ]

    # A function that get the digit part of string
    def Get_int(word:str):
        temp=""
        for c in word:
            if c.isdigit() :
                temp = temp+ c
        return int(temp)

    # use lamda to sort the string list by its digit part
    playerA.sort(key=lambda x: Get_int(x))
    playerB.sort(key=lambda x: Get_int(x))
    playerC.sort(key=lambda x: Get_int(x))
    playerD.sort(key=lambda x: Get_int(x))

    # print all the result 
    print("sorted playerA :\n" , playerA )
    print("sorted playerB :\n" , playerB )
    print("sorted playerC :\n" , playerC )
    print("sorted playerD :\n" , playerD )

    
def Function4():
    # Data
    A = {0,2,4,6,8,10}
    B = {1,2,3,4,5,6}

    # Intersection operation 
    Intersection = A-B
    # Difference operation 
    Difference = B-A


    # print the result 
    print("Result of Intersection : " , Intersection)
    print("Result of Difference : " , Difference )

         

# main function 

# input the number
num=int(input(" input a number in range of 1 and 4 \n"))

while( check_range(num) ): # if the number out of range : keep in the loop and input the number again 
    num=int(input(" input a number in range of 1 and 4 \n"))

# if else statement that choose ith Function to execute
if num==1:
    Function1()
elif num==2:
    Function2()
elif num==3:
    Function3()
else:
    Function4()