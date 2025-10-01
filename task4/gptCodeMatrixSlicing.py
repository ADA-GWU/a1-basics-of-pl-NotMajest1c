import numpy as np
import matplotlib.pyplot as plt

def generate_random_matrix(num_rows, num_cols, min_val=0, max_val=10):
    """Generates a 2D matrix filled with random integers between min_val and max_val inclusive."""
    return np.random.randint(min_val, max_val + 1, size=(num_rows, num_cols))

def get_valid_slice_indices(max_row, max_col):
    """Prompts the user to input start and end indices for slicing and swaps if end < start."""
    print("Enter the slice ranges for rows and columns (start inclusive, end exclusive):")
    
    row_start = int(input(f"Start row (0 to {max_row - 1}): "))
    row_end = int(input(f"End row (1 to {max_row}): "))
    col_start = int(input(f"Start column (0 to {max_col - 1}): "))
    col_end = int(input(f"End column (1 to {max_col}): "))

    # Ensure valid slicing by swapping if needed
    if row_end < row_start:
        row_start, row_end = row_end, row_start
    if col_end < col_start:
        col_start, col_end = col_end, col_start
    
    return row_start, row_end, col_start, col_end

def plot_matrices(original, sliced):
    """Displays the original and sliced matrices side by side using heatmaps."""
    plt.figure(figsize=(12, 5))

    plt.subplot(1, 2, 1)
    plt.title("Original Matrix")
    plt.imshow(original, cmap="viridis", interpolation="nearest")
    plt.colorbar()

    plt.subplot(1, 2, 2)
    plt.title("Sliced Submatrix")
    plt.imshow(sliced, cmap="viridis", interpolation="nearest")
    plt.colorbar()

    plt.show()

# -------------------------
# Main Program
# -------------------------
print("Matrix Slicing Visualization Program")
rows = int(input("Input number of rows in the matrix: "))
cols = int(input("Input number of columns in the matrix: "))

# Generate and display the original matrix
matrix = generate_random_matrix(rows, cols)
print("\nGenerated Matrix:\n", matrix)

# Get slicing indices and extract submatrix
row_start, row_end, col_start, col_end = get_valid_slice_indices(rows, cols)
sliced_matrix = matrix[row_start:row_end, col_start:col_end]
print("\nSliced Submatrix:\n", sliced_matrix)

# Plot the results
plot_matrices(matrix, sliced_matrix)
