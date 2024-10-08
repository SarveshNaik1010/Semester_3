# ------------- WAP to implement arrays using NumPy and use NumPy ------------ #
import numpy as np

# 1. Array operations 1 using NumPy
listOfStudents = ["Jhon Doe", "Korry Anderson", "Monica Nice", "Andrea Smith"]
arrayOfStudents = np.array(listOfStudents);
print("Array of Students");
print(arrayOfStudents);
newArrayOfStudents = np.append(arrayOfStudents, "Jerry Thompson");
print("Append a new element");
print(newArrayOfStudents);

# 2. Array Operations 2
zeros_array = np.zeros((2, 3))  # 2x3 array filled with zeros
range_array = np.arange(0, 10, 2)  # Array of numbers from 0 to 10 with step 2

# Display arrays
print("Array filled with zeros:")
print(zeros_array)

print("Array of numbers from 0 to 10 with step 2:")
print(range_array)

# Display attributes
print("Attributes of the zeros_array:")
print(f"Shape: {zeros_array.shape}")
print(f"Data type: {zeros_array.dtype}")
print(f"Size: {zeros_array.size}")

print("Attributes of the range_array:")
print(f"Shape: {range_array.shape}")
print(f"Data type: {range_array.dtype}")
print(f"Size: {range_array.size}")
