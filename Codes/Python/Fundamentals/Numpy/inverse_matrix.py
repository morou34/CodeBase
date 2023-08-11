import numpy as np 

A = np.array([[4,9,0], [1.2,3,1], [2,5,0]])
B = np.linalg.inv(A)
C = np.array([[2, 1,0], [0.5, 0, -1], [-0.5, -1, 1]])
det = np.linalg.det(A)

# print(A, '\n')
print(B, '\n')
# print(C, '\n')

# print(np.matmul(A, B), '\n')
# print(np.matmul(A, C))