import math

def isPositif(num):
	return num > 0

# filter() yields the items of the input iterable for which function returns True.
numbers = [0, 10, -10, 30, -40, 50, 60, -70, 80, 90, -120, -60]
pos_nums = list(filter(isPositif, numbers))
print(pos_nums)

nums_sqrt = list(map(math.sqrt, pos_nums))
nums = [round(x, 2) for x in nums_sqrt]
print(nums)
y = 12.21565465645522555
print(f'y = {y:.2f}')

#----------------------------------------------------------
def to_fahrenheit(c):
    return round(9 / 5 * float(c) + 32, 2)

slist = ['22', '32', 'Diamond', 'Sky', '44', '20', '47', '36', 'FFC']

nlist = list(map(to_fahrenheit, filter(str.isdigit, slist)))
print('temperatures in Fahrenheit:', nlist)

