# --------------- WAP to demonstrate the concept of inheritance -------------- #

class Person:
    def __init__(self, name, age):
        print("Constructor of parent class");
        self.name = name
        self.age = age

    def introduce(self):
        print(f"Hello my name is {self.name} and I am {self.age} years old");

class Student(Person):
    def __init__(self, name, age, college, branch):
        super().__init__(name, age)
        print("Constructor of Child");
        self.college = college;
        self.branch = branch;

    def intro(self):
        print(f"I am {self.name} and I study in {self.college} ({self.branch})")

sarvesh = Student("Sarvesh Naik", 19, "Vishwakarma University", "CO")

sarvesh.introduce()
sarvesh.intro()