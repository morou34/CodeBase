# For example, if we run 9119 through the function, 
# 811181 will come out, because 92 is 81 and 12 is 1.
import math 

def square_digits_1(num):
	result = ''
	for dg in str(num):
		value = int(math.pow(int(dg), 2))
		result += str(value)
	return int(result)


def square_digits_2(num):
    return int(''.join([str(n * n) for n in map(int, str(num))]))


def square_digits_3(num):
	return ''.join([str(int(c)**2) for c in str(num)])

result = square_digits_3(9119)
print(result)
#-------------------------------------------------------------------------------------
# Bob is preparing to pass IQ test. The most frequent task in this test is to find out 
# which one of the given numbers differs from the others. Bob observed that one number 
# usually differs from the others in evenness. Help Bob — to check his answers, he needs 
# a program that among the given numbers finds one that is different in evenness, 
# and return a position of this number.

# ! Keep in mind that your task is to help Bob solve a real IQ test, which means 
# indexes of the elements start from 1 (not 0)

def iq_test(string):

	str_numbers = (string.split(' '))
	binary_list = [int(num) % 2 for num in str_numbers]
	total = reduce(lambda x,y: x+y, binary_list)
	if total > 1:
		return binary_list.index(0) + 1
	else:
		return binary_list.index(1) + 1

nums = "2 4 7 8 10"
nums1 = "1 2 1 1"
print(iq_test(nums1))
#-------------------------------------------------------------------------------------
def isPrime(n):
	n = abs(n)
	if n == 0 or n == 1:
		return False
	else:
		for i in range(2, int(n/2)+1):
			if n % i == 0:
				return False
	return True

numbers = [0, 1, 2 , 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 100, 101, 102, 103]
res = map(isPrime, numbers) 
print(numbers)
#-------------------------------------------------------------------------------------
