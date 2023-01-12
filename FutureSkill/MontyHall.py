class Solution:
    def __init__(self, api):
        self.api = api
        print("Press run code to see this in the console!")
        # You can initiate and calculate things here
        self.seed = 0
        self.choice = -1
        
    def level_1_stay(self, revealed):
        """
        Implement the method ‘level 1 stay’ which will be called twice for
        each round:   The first time the variable ‘revealed’ will be –1 (no
        door revealed yet) and the method should return the chosen door; 0 for
        door A, 1 for door B and 2 for door C. The second time ‘revealed’ will
        be 0, 1 or 2, indicating which door has been opened to show a goat. To
        pass, you should return the same door as in the previous call, as this
        is the Stay strategy. Note that your code must remember the original
        choice of door as this is not passed as a parameter.
        
        :type revealed: int
        
        :rtype: int
        """
        # Write your code here
        if revealed < 0:
            self.choice = self.seed % 3
            self.seed = (1 + self.seed) 
            
            return self.choice
        return self.choice
        

    def level_2_switch(self, revealed):
        """
        Implement the method ‘level 2 swicth’ which will be called twice for
        each round:   The first time the variable ‘revealed’ will be –1 (no
        door revealed yet) and the method should return the chosen door; 0 for
        door A, 1 for door B and 2 for door C.   The second time ‘revealed’
        will be 0, 1 or 2, indicating which door has been opened to show a
        goat. To pass, you should return a different door from the previous
        call, as this is the Switch strategy. Note that your code must
        remember the original choice of door as this is not passed as a
        parameter.
        
        :type revealed: int
        
        :rtype: int
        """
        # Write your code here
        if revealed < 0:
            self.choice = self.seed % 3
            self.seed = (1 + self.seed)
            
            return self.choice
        ss = [0,1,2]
        ss.remove(revealed)
        ss.remove(self.choice)
        return ss[0]

    def level_3_monte_carlo(self, revealed):
        """
        For level 3 you will be able to use the previous methods, ‘level 1
        stay’ and ‘level 2 switch’. The method ‘level 3 monte carlo’ will be
        called for 2000 rounds (4000 times). The following conditions must be
        met to pass:   For the first 1000 rounds the Stay strategy should be
        used (exactly like the method ‘level 1 stay’)   For the remaining 1000
        rounds the Switch strategy should be used (exactly like the method
        ‘level 2 switch’)
        
        :type revealed: int
        
        :rtype: int
        """
        # Write your code here
        if self.seed < 1000:
            return self.level_1_stay(revealed)
        
        return self.level_2_switch(revealed)
