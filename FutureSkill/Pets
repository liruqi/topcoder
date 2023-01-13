

class Pet:
    def __init__(self, name):
        self.name = name
    def cry(self):
        return "Silent"
        
class Dog(Pet):
        
    def cry(self):
        return "Woof"

class Cat(Pet):
    def __init__(self, name):
        super().__init__(name)
        
    def cry(self):
        return "Meow"
    
class Solution:
    def __init__(self, api):
        self.api = api
        print("Press run code to see this in the console!")
        # You can initiate and calculate things here
        self.pets = []
        
    def speak(self, name):
        """
        Every pet can make a sound. Call the cry() function for the named Pet.
        
        :type name: string
        
        :rtype: string
        """
        # Write your code here
        for p in self.pets:
            if p.name == name:
                return p.cry()
        return ""
        
    def add_pet(self, name, species):
        """
        Add a named pet of specified species to a list of Pets. Name is a
        unique identifier.
        
        :type name: string
        :type species: string
        """
        # Write your code here
        p = None
        if species=="dog":
            p = Dog(name)
        elif species=="cat":
            p = Cat(name)
        else:
            p = Pet(name)
        self.pets.append(p)
        
