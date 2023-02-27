/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, 
find if there is a celebrity in the party or not. A square NxN matrix M[][] is used to represent people at the party 
such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.


Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity
*/



// Using Stack [TC: O(N), AS: O(N)]
class Solution 
{
    public:
    //Function to find if person A knows person B.
    bool knows(vector<vector<int>>& M, int A, int B)
    {
        return M[A][B];
    }
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        
        // push all people in stack
        for(int i = 0; i < n; i++){st.push(i);}
        
        // finding potential celebrity candidate
        while(st.size() > 1)
        {
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if(knows(M,a,b))
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }
        
        // checking if the potential candidate is actually a celebrity 
        int celeb = st.top();
        
        for(int i = 0; i < n; i++)
        {
            // if celebrity knows a person OR there is person that celebrity knows => answer invalid
            if((i != celeb) && (knows(M,celeb, i) || !knows(M,i,celeb)))
            {
                return -1;
            }
        }
        
        return celeb;
    }
};