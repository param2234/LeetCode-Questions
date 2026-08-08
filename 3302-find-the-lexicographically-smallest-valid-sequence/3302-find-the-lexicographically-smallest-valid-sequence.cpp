class Solution {
public: 

    void backword(string word1, string word2,vector<int>&last){

        int i = word1.size()-1;
        int j = word2.size()-1;

        while(i>=0 && j>=0){
            if(word1[i] == word2[j]){
                last[j] = i;
                j--;
            }
            i--;
        }
    }
    vector<int> validSequence(string word1, string word2) {

        int n = word2.size();
        vector<int>last(n,-1);

        backword(word1,word2,last);

        vector<int>ans;
        bool change = false;
        int j = 0;

        for(int i = 0;i<word1.size() && j<n;i++){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;           
            }

            else if(!change && (j == n-1 || last[j + 1] > i)){
                change = true;
                ans.push_back(i);
                j++;
            }

        }

        if(j == n)return ans;

        return {};


    }
};