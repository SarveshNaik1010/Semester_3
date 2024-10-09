# ------------- NumPy arrays and operations based on NumPy array ------------- #
import numpy as np

# initialization
array_1 = np.array([4, 9, 16, 25])
array_2 = np.array([2, 3, 4, 5])

# el wise operations
addition = np.add(array_1, array_2)
subtraction = np.subtract(array_1, array_2)
multiplication = np.multiply(array_1, array_2)
division = np.divide(array_1, array_2)

# ufcs
sqrt_array_1 = np.sqrt(array_1)
log_array_1 = np.log(array_1)
exp_array_1 = np.exp(array_1)


print("Array 1:", array_1)
print("Array 2:", array_2)

print("\nElement-wise addition:", addition)
print("Element-wise subtraction:", subtraction)
print("Element-wise multiplication:", multiplication)
print("Element-wise division:", division)

print("\nSquare root of Array 1:", sqrt_array_1)
print("Logarithm (ln) of Array 1:", log_array_1)
print("Exponential of Array 1:", exp_array_1)