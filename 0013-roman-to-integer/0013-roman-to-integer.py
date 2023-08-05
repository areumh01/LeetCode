class Solution:
    def romanToInt(self, s: str) -> int:
        n = len(s)
        numMap = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        answer=0
        for i in range(n-1):
            #print(i)
            if numMap[s[i]]>=numMap[s[i+1]]:
                answer+=numMap[s[i]]
            else:
                answer-=numMap[s[i]]
        answer+=numMap[s[n-1]]
        
        return answer