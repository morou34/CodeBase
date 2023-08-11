import numpy as np

# Create an array and get its size
def numpy_1():
	# 1 dimensional array
	a = np.array([1, 2, 3])
	print(a)

	# 2 dimensional float array
	b = np.array([[2.5, 3.5, 4.5], [1.0, 2.0, 3.0]])
	c = np.array([[2, 2], [4, 4], [8, 8]])
	print(b)
	print(c)
	print('---------------')

	# Number of dimensions
	print(a.ndim)
	print(b.ndim)
	print(c.ndim)
	print('---------------')

	# Shape: Number of rows and columns
	print(a.shape)
	print(b.shape)
	print(c.shape)
	print('---------------')

	# Get data type and size
	print('type:', a.dtype)
	print('items size:', a.itemsize)
	print('size:', a.size)
	print('total size:', a.nbytes)
	print('---------------')

# Access, change specific elements, rows, columns, etc.
def numpy_2():
	
	a = np.array([[1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 
		          [11, 12, 13, 14, 15, 16, 17, 18, 19, 20]])
	print(a)
	print('------------------------')
	# Access a specific element of the matrix [row, column]
	print('item (0, 0):', a[0,0])
	print('item (1, 9):', a[1,9])
	print('------------------------')

	# Get a Specific row
	print('The first row:', a[0,:])
	print('------------------------')
	
	# Get a Specific column
	print('The last column:', a[:, 9])
	print('------------------------')

	# Get a Specific Part of the matrix: [start:end:step] 
	print('Matrix 1:\n', a[:, 0:2])
	print('------------------------')

	print('Matrix 2:\n', a[0, 1:6:2])
	print('------------------------')

	print('Matrix 3:\n', a[0, 1:-4:2])
	print('------------------------')
	
	# Change an element
	a[0,0] = 0
	print(a)
	print('------------------------')

	# Chane all elements of sub_matrix with the same value
	a[:, 0:9:2] = 99
	print(a)
	print('------------------------')

	a[:, -1] = [55, 55]
	print(a)

# Initializing different type of arrays
def numpy_3():

	# initialize with zeros
	a = np.zeros(5)
	b = np.zeros(5, dtype='int8')
	c = np.zeros((3,2))
	print(a)
	print('-----------------')
	print(b)
	print('-----------------')
	print(c)
	print('-----------------')

	# initialize with ones
	d = np.ones(5)
	e = np.ones(5, dtype='int8')
	f = np.ones((3,2))
	print(d)
	print('-----------------')
	print(e)
	print('-----------------')
	print(f)
	print('-----------------')

	# fill the matrix with any number
	g = np.full((3,4), 77)
	print(g)
	print('-----------------')

	# random decimal number matrix
	h = np.random.rand(2,3)
	print(h)
	print('-----------------')

	# random decimal number matrix
 

numpy_3()




