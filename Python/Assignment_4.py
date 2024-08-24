# ------------------------------ Error Handling ------------------------------ #

class CustomZeroResultError(Exception):
    def __init__(self, message="Result cannot be 0"):
        self.message = message
        super().__init__(self.message)


def calculateAndStore(num1, num2, fileName):
    try:
        result = int(num1) + num2
        if(result == 0):
            raise CustomZeroResultError(); # Throwing custom error
        print(f"SUM OF {num1} & {num2} = {result}");
        file = open(fileName, 'r');
        print(file.read());
        
    except TypeError as e:
        print(f"TypeError: {e}")
    except ValueError as e:
        print(f"ValueError: {e}")
    except FileNotFoundError as e:
        print(f"FileNotFoundError: {e}")
    except CustomZeroResultError as e:
        print(f"Custom Error: {e}");

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

print("PASSING 0 AS NUM1 AND NUM2")
calculateAndStore(0, 0, "./Python/correct_file.txt");
print("-------------------------")
