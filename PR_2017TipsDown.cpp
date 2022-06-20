
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int solution2(string s)
{
    int answer = -1;

    for(int i=s.size()-2; i>=0; i--) {
        if(i==s.size()-1) continue; //after remove if
        if(s[i]==s[i+1])
            s.erase(i,2);

    }

    if(s.size()==0) answer = 1;
    else answer = 0;

    return answer;
}

int solution(string s)
{
    int answer = -1;

    stack<int> st;
    for(int i=0; i<s.size(); i++) {
        if(st.size()==0) st.push(s[i]);
        else {
            if(st.top()==s[i]) st.pop();
            else st.push(s[i]);
        }
    }

    if(st.size()==0) answer = 1;
    else answer = 0;

    return answer;
}


int main() {
    string s;
    cin >>s;
    int answer = solution(s);
    cout << answer;
    return 0;
}
