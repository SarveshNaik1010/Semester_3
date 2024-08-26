# ------- Write a Python Program to Demonstrate Concept of Constructor ------- #

class Student:
    # Parameterized constructor with default arguments
    def __init__(self, name, rollNo="N/A"):
        self.name = name;
        self.rollNo = rollNo;

    def display(self):
        print(f"Name: {self.name}\nRollNo: {"Not Yet Assigned" if self.rollNo == "N/A" else self.rollNo}");


sarvesh = Student("Sarvesh Naik", 114);
sarvesh.display();
anshul = Student("Anshul Dhule");
anshul.display();