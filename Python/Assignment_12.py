import numpy as np

# Create a random 1D NumPy array of 20 elements between 1 and 100
np.random.seed(0)  # Set seed for reproducibility
array = np.random.randint(1, 101, 20)
print("Original Array:\n", array)

# 1. Calculate mean
mean_value = np.mean(array)
print("\nMean:", mean_value)

# 2. Calculate median
median_value = np.median(array)
print("Median:", median_value)

# 3. Calculate standard deviation
std_dev = np.std(array)
print("Standard Deviation:", std_dev)

# 4. Calculate variance
variance = np.var(array)
print("Variance:", variance)

# 5. Calculate percentiles (25th, 50th, 75th)
percentile_25 = np.percentile(array, 25)
percentile_50 = np.percentile(array, 50)
percentile_75 = np.percentile(array, 75)
print("\n25th Percentile:", percentile_25)
print("50th Percentile (Median):", percentile_50)
print("75th Percentile:", percentile_75)

# 6. Correlation coefficient between this array and another random array
array2 = np.random.randint(1, 101, 20)
print("\nSecond Array:\n", array2)

# Correlation matrix between array and array2
correlation_matrix = np.corrcoef(array, array2)
print("\nCorrelation coefficient matrix between array and array2:\n", correlation_matrix)

# Extract correlation coefficient between the two arrays
correlation_coefficient = correlation_matrix[0, 1]
print("Correlation Coefficient between array and array2:", correlation_coefficient)
