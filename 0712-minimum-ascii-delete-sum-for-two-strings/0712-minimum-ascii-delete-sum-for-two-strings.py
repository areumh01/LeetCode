class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        alls=[]
        sub=[]
        answer=0
        n1 = len(s1)
        n2 = len(s2)
        for i in range(n2+1):
            sub.append(0)
        alls.append(sub)
        for i in range(1,n1+1):
            alls.append([0]);
            for j in range(1,n2+1):
                if s1[i-1]==s2[j-1]:
                    alls[i].append(alls[i-1][j-1]+ord(s1[i-1]))
                else:
                    alls[i].append(max(alls[i-1][j], alls[i][j-1]))
        for i in range(n1):
            answer+=ord(s1[i])
        for i in range(n2):
            answer+=ord(s2[i])
        answer-=2*alls[n1][n2]
        return answer