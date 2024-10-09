import numpy as np

# Create a 5x5 NumPy array for demonstration
array = np.arange(1, 26).reshape(5, 5)
print("Original 5x5 array:\n", array)

# 1. Accessing specific elements
print("\nAccessing specific element at (2,3):", array[2, 3])  # element at row 2, column 3

# 2. Accessing entire rows and columns
print("\nAccessing entire row 1:", array[1, :])  # second row (row index starts at 0)
print("\nAccessing entire column 2:", array[:, 2])  # third column

# 3. Slicing to extract subarrays
print("\nExtracting a 2x2 subarray from the top-left corner:\n", array[0:2, 0:2])
print("\nExtracting a 3x2 subarray from rows 1 to 3 and columns 2 to 3:\n", array[1:4, 2:4])

# 4. Boolean indexing (e.g., selecting elements greater than 10)
print("\nElements greater than 10:\n", array[array > 10])

# 5. Fancy indexing (accessing multiple rows and columns at once)
print("\nAccessing specific rows and columns with fancy indexing:")
print("Rows [0, 2, 4], Columns [1, 3]:\n", array[[0, 2, 4], [1, 3, 4]])

# 6. Fancy indexing to reorder rows
print("\nReordering rows [4, 2, 0]:\n", array[[4, 2, 0]])

# 7. Combining boolean and fancy indexing (e.g., select elements where the value is greater than 20)
print("\nElements greater than 20, using boolean indexing:\n", array[array > 20])

# 8. Modifying array values using indexing
array[1:3, 1:3] = 99  # Set a 2x2 subarray to 99
print("\nModified array after setting a subarray to 99:\n", array)
