#User function Template for python3


class Solution:
    def findMissing(self,a,b,n,m):
    # code here
    # Create a set to store elements of array b
        b_set = set(b)
        
        # Initialize a list to store missing elements
        missing_elements = []
        
        # Iterate through array a
        for num in a:
            # If the current element of a is not in the set of b
            if num not in b_set:
                # Add it to the list of missing elements
                missing_elements.append(num)
        
        return missing_elements


#{ 
 # Driver Code Starts
#Initial Template for Python 3



t=int(input())
for _ in range(0,t):
   # n=int(input())
    l = list(map(int, input().split()))
    n=l[0]
    m=l[1]
    a = list(map(int,input().split()))
    b = list(map(int, input().split()))
    ob=Solution()
    ans=ob.findMissing(a,b,n,m)
    for each in ans:
        print(each,end=' ')
    print()
# } Driver Code Ends