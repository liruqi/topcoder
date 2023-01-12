class Solution:
    def __init__(self, api):
        self.api = api
        print("Press run code to see this in the console!")
        # You can initiate and calculate things here
        
    def sort_the_list(self):
        """
        Your solution should be entered here. Use the API to get information
        about the list and to manipulate the contents.
        
        """
        # Write your code here
        for r in range(self.api.size()-1):
            swap = 0
            for i in range(self.api.size()-1):
                if not self.api.is_ordered(i, i+1):
                    self.api.swap(i, i+1)
                    swap += 1
            if swap == 0:
                break
