class Solution {
public:
    int minOperations(string s) {
        
        int count1 = 0;
        int count2 = 0;

        for(int i = 0;i<s.size();i++){
            
            if(s[i] != (i % 2 ? '1' : '0'))count1++;
            if(s[i] != (i % 2 ? '0' : '1'))count2++;
        }

        return min(count1,count2);
    }
};