import numpy as np
import time

def matrixMultiplicationNumpy(A, B):
    return np.dot(A, B)

rows_A = int(input("Input number of Rows in A: "))
cols_A = int(input("Input number of Cols in A: "))
rows_B = int(input("Input number of Rows in B: "))
cols_B = int(input("Input number of Cols in B: "))

if cols_A != rows_B:
    print("Error: A's columns must equal B's rows for matrix multiplication, please run the program again")
    exit()

A = np.random.randint(0, 10, size=(rows_A, cols_A))
B = np.random.randint(0, 10, size=(rows_B, cols_B))

start = time.time()
multAB = matrixMultiplicationNumpy(A, B)
end = time.time()

print("\nMatrix A:\n", A)
print("Matrix B:\n", B)
print("A x B = \n", multAB)
print("Time: {:.8f} sec".format(end - start))

def testMatrixMultiplicationNumpy():
    testA = np.array([[1, 2, 3], [4, 5, 6]])
    testB = np.array([[7, 8], [9, 10], [11, 12]])
    expected = np.array([[58, 64], [139, 154]])
    assert np.array_equal(matrixMultiplicationNumpy(testA, testB), expected)
    print("Test passed")

testMatrixMultiplicationNumpy()
