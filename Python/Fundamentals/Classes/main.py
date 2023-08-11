import os
import datetime

# self: access through the instance
# Employee: access through the class
def emp_info(employee):
	print('------------------------------------------------------------')
	print(f'{employee.full_name()} | {employee.email} | {employee.pay} | {employee.registration}')

class Employee:
	num_of_emps = 0
	raise_amount = 1.04

	def __init__(self, first, last, pay):
		self.first = first
		self.last = last
		self.email = (first + '_' + last + '@gmail.com').lower()
		self.pay = pay
		self.registration = datetime.date.today()
		Employee.num_of_emps += 1

	def full_name(self):
		self.fullName = self.last.upper() + ' ' + self.first.title()
		return self.fullName

	def apply_raise(self):
		self.pay = int(self.pay * self.raise_amount)

	@classmethod
	def raise_amt(cls, amount):
		cls.raise_amount = amount

	@classmethod
	def from_str(cls, info):
		first, last, pay = info.split('-')
		return cls(first, last, int(pay))

	@staticmethod
	def isWorkDay(day):
		myday = day.weekday()
		days = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']
		if  myday == 5 or myday == 6: # saturday or sunday
			return (False, days[myday])
		return (True, days[myday])

	def __str__(self):
		return f'{self.full_name()} | {self.email} | {self.pay} | {self.registration}'


class Developper(Employee):
	raise_amount = 1.10
	def __init__(self, first, last, pay, prog_lang):
		super().__init__(first, last, pay)
		self.prog_lang = prog_lang

class Manager(Employee):
	def __init__(self, first, last, pay, employees = None):
		super().__init__(first, last, pay)
		if employees is None:
			self.employees = []
		else:
			self.employees = employees

	def add_emp(self, emp):
		if emp not in self.employees:
			self.employees.append(emp)

	def remove_emp(self, emp):
		if emp in self.employees:
			self.employees.remove(emp)

	def print_emps(self):
		for emp in self.employees:
			print('-->', emp.full_name())

	def num_of_devs(self):
		return len(self.employees)


#-------------------------------------------- 
emp1 = Employee('vetel', 'harris', 75_000)
emp2 = Employee('McGory', 'alex', 75_000)
emp_info(emp1)
emp_info(emp2)
print(f'Number of employees:', Employee.num_of_emps)

#-------------------------------------------- 
emp1.raise_amount = 1.07
emp1.apply_raise()
emp_info(emp1)
print('Employee 1 raise is:', emp1.raise_amount)
print('Employee 2 raise is:', emp2.raise_amount)
print('Employee class raise is:', Employee.raise_amount)
print()
# Namespace of the class instance
# print(emp1.__dict__)
# print(Employee.__dict__)

#-------------------------------------------- 
Employee.raise_amt(1.09) # equivalent to Employee.raise_amount = 1.09
# print(emp1.__dict__)
print('Employee 1 raise is:', emp1.raise_amount)
# print(emp2.__dict__)
print('Employee 2 raise is:', emp2.raise_amount)
# print(Employee.__dict__)
print('Employee class raise is:', Employee.raise_amount)

#-------------------------------------------- 
info1 = 'jhon-doe-61550'
info2 = 'clay-jack-72350'
info3 = 'smith-steve-83150'

emp3 = Employee.from_str(info1)
emp4 = Employee.from_str(info2)
emp5 = Employee.from_str(info3)
emp_info(emp3)
emp_info(emp4)
emp_info(emp5)
#-------------------------------------------- 

print('raise:', emp5.raise_amount)
emp5.apply_raise()
print()
print('raise 1:', emp5.raise_amount)
emp_info(emp5)
print()
emp5.raise_amount = 1.11
emp5.apply_raise()
print('raise 2:', emp5.raise_amount)
emp_info(emp5)
#-------------------------------------------- 

day = datetime.date(2021, 7, 15)
isworkday = Employee.isWorkDay(day)
print(f'{isworkday[1]}:{day} Is a Work Day.' if isworkday[0] else f'{isworkday[1]}:{day} Is Not a Work Day.')
#-------------------------------------------- 
# INHERETANCE
#-------------------------------------------- 
print()
dev1 = Developper('Hamid', 'Clowi', 33_254, 'Python')
dev2 = Developper('Jimmy', 'McDonalds', 65_500, 'C++')
dev3 = Developper('Alex', 'Atkinson', 75_500, 'C')
dev4 = Developper('Jhon', 'Smith', 85_500, 'Java')
dev5 = Developper('Tara', 'McShane', 90_000, 'C#')

emp_info(dev1)
print('Programming language:', dev1.prog_lang) # developper
print()
#-------------------------------------------- 

mgr1 = Manager('Nick', 'Levar', 80_000, [dev1, dev2, dev3])
print(mgr1.full_name())
print(mgr1.email)
mgr1.print_emps()
print(f'Manager 1 is supervising {mgr1.num_of_devs()} Developper')
print()
mgr1.remove_emp(dev2)
mgr1.print_emps()
print(f'Manager 1 is supervising {mgr1.num_of_devs()} Developper')

print(dev1)
