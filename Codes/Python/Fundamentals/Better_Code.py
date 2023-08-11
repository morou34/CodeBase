#----------------------------------------
condition = True
if condition:
	x = 1
else:
	x = 0
print('x =',x)

#----------------------------------------
x = 1 if condition else 0
print('x =',x)

# Trick 2:
num1 = 10_000_000_000
num2 = 100_000_000
total = num1 + num2
print(total)
print(f"{total:,}")


#----------------------------------------
cities = ['New York', 'Tokyo', 'Seoul', 'Moscow', 'London']

for index, city in enumerate(cities, start=1):
	print(f'{city}:{index}')

#----------------------------------------
names = ['Peter Parker', 'Clark Kent', 'Wade Wilson', 'Bruce Wayne']
heros = ['Spiderman', 'Superman', 'Deadpool', 'Batman']
for index, name in enumerate(names):
	hero = heros[index]
	print(f'{name} is actually {hero}') 
print()
#zip stops once the shortest list is exhausted
for name, hero in zip(names, heros):
	print(f'{name} is actually {hero}') 
#return all in a tuple, zip returns a tuple
for value in zip(names, heros):
	print(value)

#----------------------------------------
# unpacking
a, b, *c = (1, 2, 3, 4, 5)
print(a, b ,c)

a, b, *c , d = (1, 2, 3, 4, 5)
print(a, b ,c, d)

#----------------------------------------
# setting class instance attributes from variables
# accessing attributes in loops
class Car:
	pass

car = Car()

car_info = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
} 

for key, value in car_info.items():
	setattr(car, key, value)

print(car.brand, '|', car.model, '|', car.year)

for key in car_info.keys():
	print(getattr(car, key))

#----------------------------------------
from getpass import getpass

#username = input('username: ')
#password = getpass('password: ')
print('logging in ...')














