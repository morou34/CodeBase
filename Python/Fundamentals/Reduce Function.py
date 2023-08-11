import os
import random 
import os.path
from functools import reduce
from Convert_Size import convert

PATH = 'C:/Users/mouaa/Downloads/Video'
os.chdir(PATH)
files = os.listdir()
print(files)
size = sum(map(os.path.getsize, files))
print(f'Total files size is: {size} bytes')
print(f'Total files size is: {convert(size)}')
#----------------------------------------------
# Apply a function of two arguments cumulatively to the items of a sequence,
# from left to right, so as to reduce the sequence to a single value.
# the result of the first two elements is gonna be the input for the next 
# operation with the next element in the sequence 
#----------------------------------------------

def myAdd(a, b):
	result = a + b 
	print(f'{a} + {b} = {result}')
	return result
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
res = reduce(myAdd, nums)
print('res:', res)
print('-------------')
res_ = reduce(myAdd, nums, 100) #reduce with value of initializer = 100
res_lambda = reduce(lambda x, y: x+y, nums, 100)
print('result: ',res_lambda)
#----------------------------------------------
# Finding the Minimum and Maximum Value

numbers = random.sample(range(-50, 50), 20)
print(numbers)

min_value = reduce(lambda x,y: x if x<y else y, numbers)
print('min_value =', min_value)

max_value = reduce(lambda x,y: x if x>y else y, numbers)
print('max_value =', max_value)
#----------------------------------------------
# Checking if All Values Are True

inputs = random.choices([False, True], k = 10)
myinputs = [True, True, True, True]

isAllTrue1 = reduce(lambda x,y: x and y , inputs)
isAllTrue2 = reduce(lambda x,y: x and y , myinputs)

print(inputs)
print(isAllTrue1)
print(myinputs)
print(isAllTrue2)

isAllTrue3 = all(inputs) # Pythonic efficient way for solving the all-true problem
print('All:', isAllTrue3)

isAllTrue4 = any(inputs) # Pythonic efficient way for solving the any-true problem
print('Any:', isAllTrue4)

#----------------------------------------------



