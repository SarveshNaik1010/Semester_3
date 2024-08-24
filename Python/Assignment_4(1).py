# ------------------------------ Error Handling ------------------------------ #

# Pre-Defined Errors
def calculateAndStore(num1, num2, fileName):
    try:
        result = int(num1) + num2
        print(f"SUM OF {num1} & {num2} = {result}");
        file = open(fileName, 'r');
        print(file.read());
    except TypeError as e:
        print(f"TypeError: {e}")
    except ValueError as e:
        print(f"ValueError: {e}")
    except FileNotFoundError as e:
        print(f"FileNotFoundError: {e}")

print("PASSING 2 INTEGERS")
calculateAndStore(12, 34, "./Python/correct_file.txt");
print("-------------------------")

print("PASSING STRING INSTEAD OF INTEGER")
calculateAndStore("Sarvesh", 34, "./Python/correct_file.txt");
print("-------------------------")

print("PASSING STRING INSTEAD OF INTEGER")
calculateAndStore(12, "Naik", "./Python/correct_file.txt");
print("-------------------------")

print("PASSING INCORRECT FILE PATH")
calculateAndStore(12, 34, "./Python/incorrect-file");
print("-------------------------")
