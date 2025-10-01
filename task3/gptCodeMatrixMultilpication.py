import numpy as np
import time

def matrix_multiplication_numpy(A, B):
    return np.dot(A, B)

# ---------------------------
# Step 1: Input matrix dimensions
# ---------------------------

print("Matrix Multiplication using NumPy")
print("Please enter the dimensions for the matrices.")

# Dimensions of matrix A
rows_A = int(input("Enter the number of rows in matrix A: "))
cols_A = int(input("Enter the number of columns in matrix A: "))

# Dimensions of matrix B
rows_B = int(input("Enter the number of rows in matrix B: "))
cols_B = int(input("Enter the number of columns in matrix B: "))

# Validate matrix dimensions
if cols_A != rows_B:
    print("Error: Number of columns in A must be equal to number of rows in B for multiplication.")
    exit()

# ---------------------------
# Step 2: Generate random matrices
# ---------------------------

# Using integers between 0 and 10 inclusive to fill the matrices.
# NumPy's randint generates numbers in the interval [low, high), so we use 11 as high.
A = np.random.randint(0, 11, size=(rows_A, cols_A))
B = np.random.randint(0, 11, size=(rows_B, cols_B))

# ---------------------------
# Step 3: Perform matrix multiplication and measure execution time
# ---------------------------

# Use time.perf_counter() for more accurate timing
start_time = time.perf_counter()
result = matrix_multiplication_numpy(A, B)
end_time = time.perf_counter()

# ---------------------------
# Step 4: Display matrices and result
# ---------------------------

print("\nMatrix A:\n", A)
print("Matrix B:\n", B)
print("Result of A x B:\n", result)
print("Execution time: {:.10f} seconds".format(end_time - start_time))
