class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x==0:
            return True
        if x<0 or x%10==0:
            return False
        comp = 0
        while x>comp:
            comp *= 10
            comp += x%10
            x //= 10
        if x==comp or x==comp//10:
            return True
        else:
            return False