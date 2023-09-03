class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
		//visited will contain if s[i] is present in current result Stack
        vector<int> visited(26,0),cnt(26,0);
        for(int i=0;i<s.size();i++) cnt[s[i]-'a']++;  //count the number of occurences of s[i]
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']--;  //decrement number of characters remaining in the string
            if(visited[s[i]-'a']) continue;  //if character is already present in stack, dont bother
			//if current character is smaller than last character in stack which occurs later in the string again
        //it can be removed and  added later e.g stack = bc remaining string abc then a can pop b and then c
            while(!st.empty() && s[i]<st.top() && cnt[st.top()-'a']!=0){
                visited[st.top()-'a']=0;
                st.pop();
            }
            st.push(s[i]); //add current character and mark it as visited
            visited[s[i]-'a']=1;
        }
        s.clear();
        while(!st.empty()){
            s=st.top()+s;
            st.pop();
        }
        return s;
    }
};
