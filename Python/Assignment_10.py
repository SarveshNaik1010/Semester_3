import numpy as np

arr = np.array([1, 2, 3, 4, 5, 6, 7, 8]);
print("Creating array");
print(arr)

# Reshaping array
reshapedArr = arr.reshape(2, 2, 2); # 3D Array
print("Reshaping array")
print(reshapedArr)
print("-------------------------------------")

# Transposing array
transposedArr = reshapedArr.transpose();
print("Transposing array")
print(transposedArr);
print("-------------------------------------")

# Swaping array
swapping01Arr = reshapedArr.swapaxes(1, 0);
swapping12Arr = reshapedArr.swapaxes(1, 2);
print("Swapping 0th and 1st axis")
print(swapping01Arr);
print("-----------------")
print("Swapping 1st and 2nd axis")
print(swapping12Arr);
print("-------------------------------------")


