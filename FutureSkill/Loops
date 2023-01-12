class Solution:
    def __init__(self, api):
        self.api = api
        print("Press run code to see this in the console!")
        # You can initiate and calculate things here

    def level_1(self):
        """
        Tell the dog to eat bone number 0. No loop necessary.
        
        """
        # Write your code here
        self.api.eat_bone(0)

    def level_2(self):
        """
        Let the dog eat bones numbered 0, 1 and 2.
        
        """
        # Write your code here
        self.api.eat_bone(0)
        self.api.eat_bone(1)
        self.api.eat_bone(2)
        
    def level_3(self):
        """
        Use a loop to let the dog eat all bones. There 18 bones numbered from
        0 to 17.
        
        """
        for i in range(18):
            self.api.eat_bone(i)

    def level_4(self):
        """
        Let the dog eat only brown bones(8). There are 22 bones numbered from
        0 to 21.
        
        """
        # Write your code here
        for i in range(22):
            if self.api.is_brown_bone(i):
                self.api.eat_bone(i)

    def level_5(self):
        """
        Let the dog eat all bones except for bone numbers 2, 4 and 5. There
        are 10 bones numbered from 0 to 9. Use the continue keyword.
        
        """
        # Write your code here
        for i in range(10):
            if i in [2,4,5]:
                continue
            self.api.eat_bone(i)

    def level_6(self):
        """
        Let the dog eat available bones until it is time to go home. There are
        10 bones numbered from 0 to 9. Use the break keyword.
        
        """
        # Write your code here
        for i in range(10):
            if self.api.is_time_for_break():
                break
            self.api.eat_bone(i)

    def level_7(self):
        """
        Let all dogs, eat their corresponding bones. Use nested loops.
        
        """
        # Write your code here
        for d in range(6):
            for b in self.api.get_bones_for_dog(d):
                self.api.eat_bone_for_dog(d, b)
            
