class Solution:
    def __init__(self, api):
        self.api = api
        print("Press run code to see this in the console!")
        # You can initiate and calculate things here

    def generate_pascal_triangle_binomial(self, n):
        """
        Generate Pascal's Triangle by calculating binomial coeffcients (n over
        k) = n!/(k!*(n-k)!) if n > 0, (0 over 0) = 1. Returns a list of
        strings where each string represents one row in the triangle as space-
        separated values, ie ['1', '1 1', '1 2 1']. Parameter n is the number
        of rows to generate. Allowed range for n is [1, 12], ie 1 <= n <= 12.
        For values outside this range, return an empty list.
        
        :type n: int
        
        :rtype: List[string]
        """
        # Write your code here
        row=[]
        pt=[]
        if n>12:
            return pt
        for i in range(n):
            nr = []
            for i in range(len(row)):
                v = row[i]
                if i>0:
                    v += row[i-1]
            nr.append(1)
            pt.append(" ".join([str(x) for x in nr]))
            row = nr
            
        return pt

    def generate_pascal_triangle_summation(self, n):
        """
        Generate Pascal's Triangle by calculating (n, k) = (n-1, k) + (n-1,
        k-1) (replace with 0 if out of range). Returns a list of strings where
        each string represents one row in the triangle as space-separated
        values, ie ['1', '1 1', '1 2 1']. Parameter n is the number of rows to
        generate. Allowed range for n is [1, 12], ie 1 <= n <= 12. For values
        outside this range, return an empty list.
        
        :type n: int
        
        :rtype: List[string]
        """
        # Write your code here
        row=[]
        pt=[]
        if n>12:
            return pt
        for i in range(n):
            nr = []
            for i in range(len(row)):
                v = row[i]
                if i>0:
                    v += row[i-1]
            nr.append(1)
            pt.append(" ".join([str(x) for x in nr]))
            row = nr
            
        return pt
