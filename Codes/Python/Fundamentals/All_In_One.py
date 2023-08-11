# python limit float to 2 decimals: 2 digits
x = 12.326547895112
x_ = round(x, 2) # 12.33
print(f'x = {x:.2f}') # 12.33

#------------------------------------------------------
# if else print condition 
print('smaller' if  4 < 5 else 'Greater')

#------------------------------------------------------
import datetime
days = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']
day = datetime.date(2023, 7, 15) #Year/Month/Day
index = day.weekday()
print('day is:',days[index])

#------------------------------------------------------
join(self, iterable)
    Concatenate any number of strings.
    Example: '.'.join(['AA', 'BB', 'CC']) -> 'AA.BB.CC'
	The string whose method is called is inserted in between each given string.

#------------------------------------------------------
python to .exe file: 
installation: pip install pyinstaller
command: pyinstaller --onefile main.py
___________________________________________
python virtual envirnment
creation: python -m venv venv
activation: venv/Scripts/activate
diactivation: deactivate

#------------------------------------------------------
Python count() function: count elements of a list or string

-> Python string.count() function is used to count for the occurrence of the input 
substring in the particular String.

inp_str = "JournalDev -- AskPython @ JournalDev"
str_cnt = inp_str.count("JournalDev")
print(str_cnt)
output = 2

-> The list.count() function checks for the number of times a particular element 
occurs in a particular list.

inp_lst = ['Apple','Banana','Apple','Grapes','Jackfruit','Apple'] 
lst_cnt = inp_lst.count('Apple')
print(lst_cnt)
output = 3
#------------------------------------------------------
index() method: can be used to get the index value of a particular element of the List.
sythax: list.index(element,start,end)

lst = [10,20,30,10,50,10,45,10] 
print("Index at which element 10 is present :",lst.index(10))
Index at which element 10 is present : 0
#------------------------------------------------------
reading from a file, encoding mode utf-8
with open("text.txt", 'r', encoding='utf-8' ) as file:
    data = file.read()
#------------------------------------------------------
if any: checking if any item of the list in another list or string
strings = ['name', 'nickname', 'lol']
phrase = 'hello my ndame lol is Mouaad'
if any(x in phrase for x in strings):

#------------------------------------------------------


#------------------------------------------------------


#------------------------------------------------------


#------------------------------------------------------


#------------------------------------------------------


