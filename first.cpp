#include "./library.h"
using namespace std;



/**
 * 
Given a string s, find the length of the longest 
substring
without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

*/


int longest_substring(string str) {
    int start = 0, end = 0, length = 0;
    int startPos = 0, endPos = 0;
    set<char> st;

    for(start = 0; start<str.size(); start++) {
        if(st.count(str[start])) {
            while (end < start and str[end] != str[start])
            {
                st.erase(str[end]);
                end++;
            }
            st.erase(str[end]);
            end++;
        }
        st.insert(str[start]);
        if(start - end +1 >= length) {
            startPos = end;
            endPos = start;
            length = start - end +1;
        }
    }
    string temp = str.substr(startPos, endPos-startPos+1);
    cout<<temp<<endl;
    return length;
}



int main() {
    string str = "aacbb";
    int length = longest_substring(str);
    cout<<length;
}