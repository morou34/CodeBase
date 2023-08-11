import datetime
from time import sleep
# datetime.date: access to date (year, month, day) 
# datetime.time: access to time (hours, minutes, seconds, micro-seconds) 
# datetime.date: access to datetime (YY, Month, d, h, min, sec, ms) 

#  get a specific date (year, month, day)
d = datetime.date(1994, 11, 30) # don't add leading zeros 07
print(d) 
# get today's date
tday = datetime.date.today()
print(tday)
print('Year:', tday.year, '\nMonth:', tday.month, '\nDay:', tday.day)

# get weekday() index: 
# Monday --> 0
# Sundat --> 6
days = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']
index = tday.weekday()
print(f'Today is {days[index]}: {tday}')
print('---------------------------------')
#--------------------------------------------------------------
# working with time delta: 
# add days, or weeks to a date
tdelta = datetime.timedelta(days=30)
month_later = tday + tdelta
print(f'{tday} + 30 days = {month_later}')

# add, substracte a date from another date
birthday = datetime.date(2022, 7, 15)
till_birthd = birthday - datetime.date.today()
print('Time to next birthday:', till_birthd.days, 'days') 
print('Time to next birthday:', till_birthd.total_seconds(), 'seconds') 

# working with time
t = datetime.time(1, 23, 45, 123_499) #hours, minutes, seconds, and micro-seconds
print('Time:', t)
print('Hour:', t.hour, '\tMinute:', t.minute, '\tSecond:', t.second, '\tMicro_Second:', t.microsecond)

# working with datetime
dt = datetime.datetime(2021, 8, 31, 8, 0, 45, 112233)
print('datetime:', dt)
# we can access each attribute individulally
print('datetime date:', dt.date())
print('datetime time:', dt.time())
print('datetime -> date -> year:', dt.year)
print('------------------------------')

# adding timedelta to a datetime object
_dt = datetime.datetime.now()
print(dt)
tdelta = datetime.timedelta(weeks=7)
print(_dt + tdelta)
time_d = (dt-_dt)
print('Time to start school is:', time_d.days, 'day, ||', time_d.total_seconds(), 'seconds')

# Displaying the date time in a good readable format

def display_dtime(dtime = None):
	if dtime is None:
		dtime = datetime.datetime.now()
	ftime = dtime.strftime('%B %d, %Y %H:%M:%S')
	print(ftime)


display_dtime()
sleep(1)
display_dtime()
sleep(1)
display_dtime()
sleep(1)
display_dtime()









		












