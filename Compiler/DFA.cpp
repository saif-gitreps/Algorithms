#include<bits/stdc++.h>

using namespace std;

void dfa_example1() {
    // example , a dfa where it accepts any strings which contains '1' or ends with '1'.
    // accepted example : 11, 01 , 0011100
    
    string s; 
    cin >> s;
    
    int state = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (state == 0 && s[i] == '0') 
            continue;
        
        if (state == 0 && s[i] == '1') {
            state = 1;
            continue;
        }
       
        if (state == 1 && (s[i] == '1' || s[i] == '0'))
            continue;
    } 
    
    if (state == 1) 
        cout << "accepted";
    else 
        cout << "not accepted";
        
}

void dfa_example2() {
    // dfa where it accepts strings which ends with '1' only.
    // example: 01, 1111, 01, 1, 10001101.
    
    string s; 
    cin >> s;
    
    int state = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (state == 0 && s[i] == '0') 
            continue;
        
        if ((state == 0 || state == 1) && s[i] == '1') {
            state = 1;
            continue;
        }
        
        if (state == 1 && s[i] == '0') {
            state = 0;
            continue;
        }
    } 
    
    if (state == 1) 
        cout << "accepted";
    else 
        cout << "not accepted";
    
}

void dfa_example3() {
     // dfa where it accepts strings which starts with '1' and ends with '0' .
    // example: 10, 11110, 100110, 1, 10001100.
    
    string s; 
    cin >> s;
    
    int state = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (state == 0 && s[i] == '0') {
            state = 3;
            continue;
        }
        
        if (state == 3) 
            continue;
        
        if ((state == 0 || state == 1) && s[i] == '1') {
            state = 1;
            continue;
        }
        
        if (state == 1 && s[i] == '0') {
            state = 2;
            continue;
        }
        
        if (state == 2 && s[i] == '0') 
            continue;
        
        if (state == 2 && s[i] == '1') {
            state = 1;
            continue;
        }
    } 
    
    if (state == 2) 
        cout << "accepted";
    else 
        cout << "not accepted";
}
  
int main () {
    
    // dfa_example1();
    // dfa_example2();
    dfa_example3();
    
}
