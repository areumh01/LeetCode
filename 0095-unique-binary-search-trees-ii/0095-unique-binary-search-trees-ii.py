# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    #def __init__(self):
    #    self.m = {}
    
    def solve(self, start, end):
        v=[]
        if start>end:
            v.append(None);
            return v
        if start==end:
            v.append(TreeNode(start,None,None))
            return v
        for i in range(start,end+1):
            l = self.solve(start,i-1)
            r = self.solve(i+1, end)
            for x in l:
                for y in r:
                    root = TreeNode(i)
                    root.left = x
                    root.right= y
                    v.append(root)
        return v
    
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        return self.solve(1,n)
        
        