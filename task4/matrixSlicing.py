import numpy as np
import matplotlib.pyplot as plt

rows = int(input("Input number of rows in the matrix: "))
cols = int(input("Input number of columns in the matrix: "))

matrix = np.random.randint(0, 11, size=(rows, cols))
print("\nGenerated Matrix:\n", matrix)

print("Enter the slice ranges for rows and columns (start inclusive, end exclusive):")
row_start = int(input(f"Start row (0 to {rows-1}): "))
row_end = int(input(f"End row (1 to {rows}): "))
col_start = int(input(f"Start column (0 to {cols-1}): "))
col_end = int(input(f"End column (1 to {cols}): "))

# Swap if end < start
if row_end < row_start:
    row_start, row_end = row_end, row_start
if col_end < col_start:
    col_start, col_end = col_end, col_start

sliced_matrix = matrix[row_start:row_end, col_start:col_end]
print("\nSliced Submatrix:\n", sliced_matrix)

#original matrix
plt.figure(figsize=(10, 4))
plt.subplot(1, 2, 1)
plt.title("Original Matrix")
plt.imshow(matrix, cmap="viridis", interpolation="nearest")
plt.colorbar()

#sliced matrix
plt.subplot(1, 2, 2)
plt.title("Sliced Submatrix")
plt.imshow(sliced_matrix, cmap="viridis", interpolation="nearest")
plt.colorbar()

plt.show()