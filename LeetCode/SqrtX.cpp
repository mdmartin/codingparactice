//
//  main.cpp
//  SqrtX
//
//  Created by 马 丁 on 10/10/13.
//  Copyright (c) 2013 马 丁. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        switch (x) {
            case 0:
                return 0;
                break;
            case 1:
                return 1;
                break;
            case 2:
                return 1;
                break;
            case 3:
                return 1;
                break;
            case 4:
                return 2;
                break;
            default:
                break;
        }
        return guess(x, 1, x - 1);
        
    }
    int guess(int x, int s, int e)
    {
        int m = e - int((e - s) / 2);
        if (x / m >= m && (x / (m + 1)) < (m + 1))
        {
            return m;
        }
        if (x / m > m)
        {
            return guess(x, m + 1, e);
        }
        else
        {
            return guess(x, s, m - 1);
        }
    }
};

int main(int argc, const char * argv[])
{

    Solution* sl = new Solution();
    int x = 2147395599;
    
    cout << sl->sqrt(x) << endl;
//    cout << INT_MAX << endl;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

