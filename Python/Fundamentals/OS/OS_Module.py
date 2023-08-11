import os
from size_converter import convert_size
from datetime import datetime 

# notes from documentation
def notes():
	# 	# Get current working directory
	# os.getcwd()

	# # Change directory, this requires a path to change to
	# os.chdir(path)

	# # List directory, you can pass a path, but by default it is in the current directory
	# os.listdir()

	# # Multiple options for creating directories
	# mkdir()  # Use for making one directory
	# makedirs(). # Use if you want to create multiple directories at once

	# # Remove directories
	# rmdir(file). # Recommended use case
	# removedirs(file)  # Removes intermediate directories if specified

	# # Rename a file or folder
	# os.rename(‘test.txt’, ‘demo.txt’). # This renames text.txt to demo.txt

	# # Look at info about files
	# os.stat(test.txt)
	# # Useful stat results: st_size (bytes), st_mtime (time stamp)

	# # To see entire directory tree and files within
	# # os.walk is a generator that yields a tuple of 3 values as it walks the directory tree

	# for dirpath, dirnames, filenames in os.walk(routepath): 
	#     print(‘Current Path:’, dirpath)
	#     print(‘Directories:’, dirnames)
	#     print(‘Files:’, filenames)
	#     print()

	# # This is useful for locating a file that you can’t remember where it was
	# # If you had a web app, and you wanted to keep track of the file info within a certain directory structure, then you could to thru the os.walk method and go thru all files and folders and collect file information.

	# # Access home directory location by grabbing home environment variable
	# os.environ.get(‘HOME’). # Returns a path
	# # To properly join two files together use os.path.join()
	# file_path = os.path.join(os.environ.get(‘HOME’), ‘test.txt’)
	# # the benefit of os.path.join, is it takes the guess work out of inserting a slash

	# # os.path has other useful methods

	# os.path.basename
	# # This will grab filename of any path we are working on

	# os.path.dirname(‘/tmp/test.txt’)
	# # returns the directory /tmp

	# os.path.split(‘/tmp/test.txt’)
	# # returns both the directory and the file as a tuple

	# os.path.exists(‘/tmp/test.txt’)
	# # returns a boolean

	# os.path.isdir(‘/tmp/test.txt’)
	# # returns False

	# os.path.isfile(‘/tmp/test.txt’)
	# # returns True

	# os.path.splitext(‘/tmp/test.txt’)
	# # Splits file route of the path and the extension
	# # returns (‘/tmp/test’, ‘.txt’)
	# # This is alot easier than parsing out the extension. Splitting off and taking the first value is much better.
	# # Very useful for file manipulation
	pass

# all attributes and methods of os.Module
# print(dir(os))

# get current working directory
print('Getting current directory')

directory = os.getcwd()
print(directory)

# changing directory
print('\nChanged directory')

os.chdir('D:/Python') # chdir: change directory.
print(os.getcwd())

# print all files within the current directory
print('\nListing the files in directory')

os.chdir('D:/Python/[Documentation]')
files = os.listdir() #default: is current directory
print(files)

# creating new folders
print('\nCreating new folders')

os.chdir('Os')
if not os.path.exists('Folder1'):
	os.mkdir('Folder1') # creates one folder
if not os.path.exists('Folder2'):
	os.makedirs('Folder2/subFolder') # creates folders and sub folders
print(os.listdir())

# removing folders
print('\nDeleting Folders')

os.rmdir('Folder1')
os.removedirs('Folder2/subFolder')
print(os.listdir())

# renaming files
print('\nRenaming Files')
try:
	os.rename('description.txt', 'demo.txt')
except Exception as err:
	print(err)
print(os.listdir())

# showing file info
print('\nDisplaying file info')
infos = os.stat('bear.jpg')
print(infos)
size = convert_size(infos.st_size)
print(f'image size: {size}')

modif_time = infos.st_mtime
print(modif_time)
modified_time = datetime.fromtimestamp(modif_time)
print(f'image was last modified on: {modified_time}')

# os.walk(): walk() generates the file names in a directory 
# tree by walking the tree either top-down or bottom-up.
def walk_method():
	starting_dir = 'D:\\Python\\[Python GUI]'
	for root, dirs, files in os.walk(starting_dir):
		print('Current Path:', root)
		print('Directories:', dirs)
		print('Files:', files)
		print()

# walk_method()

# envirnment variables
# print(os.environ)
# print(os.environ.get('HOME'))

# Joining paths correctly
# it removes or add / when needed automatically
path1 = 'D:/Python/'
path2 = '/[Python GUI]/Wanderson/PYTHON and QT QUICK'
path = os.path.join(path1, path2)
print('path is:', path)

# Check if a file or path exists
print(os.path.exists(path1))
print(os.path.exists('D:/Python/DD'))
print()
# Check if is a file or is a dir
print(f'{path1} --> is dir:', os.path.isdir(path1))
print(f'{path1} --> is file:', os.path.isfile(path1))
print()
#prase files, get extension
for file in os.listdir():
	print(os.path.splitext(file))

print()
 








