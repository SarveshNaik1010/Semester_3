# ------------------ WAP to demonstrate concept of interface ----------------- #
from abc import ABC, abstractmethod, abstractproperty

class Animal(ABC):
    @abstractmethod
    def introduce(self):
        pass

    @abstractmethod
    def makeSound(self):
        pass


class Dog(Animal):
    def introduce(self):
        print("Hi I am a dog")

    def makeSound(self):
        print("Woff Woff")

class Cat(Animal):
    def introduce(self):
        print("Hi I am a cat")

    def makeSound(self):
        print("Meow Meow")

print("Interface in python");

entertainment = Dog()
entertainment.introduce()
entertainment.makeSound()

snowbell = Cat()
snowbell.introduce()
snowbell.makeSound()
