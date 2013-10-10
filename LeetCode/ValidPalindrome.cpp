//
//  main.cpp
//  ValidPalindrome
//
//  Created by 马 丁 on 10/10/13.
//  Copyright (c) 2013 马 丁. All rights reserved.
//

#include <iostream>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int len = s.length();
        
        for (int i = 0; i < len; i++)
        {
            (int(s[i]) >= 65 && int(s[i]) <= 90) ? (s[i] += 32) : s[i] = s[i];
            ( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') ) ? s[i] = s[i] : s[i] = ' ';
        }
            
        if (len == 1 || len == 0)
        {
            return true;
        }
        int l = 0, r = len - 1;
        while (l <= r)
        {
            if (s[l] == ' ')
            {
                l++;
                continue;
            }
            if (s[r] == ' ')
            {
                r--;
                continue;
            }
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
            
        }
        
        return true;
    }
};

int main(int argc, const char * argv[])
{
    
    Solution* sl = new Solution();
    
    string s = "a.";
    
    cout << sl->isPalindrome(s) << endl;

    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}

