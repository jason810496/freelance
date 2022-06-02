
arr = {
    "Jam":16,
    "sam":21,
    "Mark":17,
    "Ken":24,
    "Ben":18
}

# original data 
print( arr )

# add new data

name = input(" new member name\n")

age = input(" new member age\n")

arr[name] = age

# new data 
print( arr )

lower = int(input("input lower:\n") )

upper = int(input("input upper:\n") )

print( f" The list of members with ages between {lower} and {upper} years old:\n")
for key in arr:
    if lower<=int(arr[key]) and int(arr[key])<=upper :
        print( key )

