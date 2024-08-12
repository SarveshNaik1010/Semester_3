# ------------------------ Operations related to array ----------------------- #

# 1. CRUD Operations
cars = ["Hyundai", "Kia", "Ford", "BMW", "TATA Motors", "Porche"];

print("Length = ", len(cars)) # Length of list

cars.append("Rolls Royce"); # Append operation (Push)
print("Push: ", cars);

cars.insert(3, "Mahindra"); # Inserted at index 3
print("Insert: ", cars);

cars.pop(); # Removed last element
print("Pop: ", cars);

cars.remove("Ford");
print("Removed 'Ford': ", cars);

cars.sort()
print("Sorted list (Alphabetically): ", cars);

indexOfKia = cars.index("Kia")
print("Index of Kia = ", indexOfKia);

# Iteration of array 
print("********************************************************************************************************")
print("Looped List 👇");
for car in cars: 
    print(car)