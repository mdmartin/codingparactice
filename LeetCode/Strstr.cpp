#include <iostream>
#include <cstring>

using namespace std;


class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int hLen = strlen(haystack);
		int nLen = strlen(needle);
		if (nLen == 0)
		{
			return haystack;
		}
		if (nLen == 1)
		{
			for (int i = 0; i < hLen; i++)
			{
				if (haystack[i] == needle[0])
				{
					return haystack + i;
				}
			}
		}
        
		
		int* table = new int[nLen];
        
		// KMP Algorithm
		// compute table
        
		table[0] = -1;
		table[1] = 0;
        for (int i = 1; i < nLen; i++)
        {
            table[i] = 0;
        }
		for (int i = 2; i < nLen; i++)
		{
            int temp = table[i - 1];
            if (needle[i - 1] == needle[temp])
            {
                table[i] = table[i - 1] + 1;
            }
            else
            {
                table[i] = 0;
                while (temp != 0)
                {
                    temp = table[temp];
                    if (needle[i - 1] == needle[temp])
                    {
                        table[i] = table[temp] + 1;
                    }
                }
            }
		}
        int m = 0, i = 0;
        while (m + i < hLen)
        {
//            cout << m + i << endl;
            if (haystack[m + i] == needle[i])
            {
                if (i == nLen - 1)
                {
                    return haystack + m;
                }
                else
                {
                    i++;
                }
            }
            else
            {
                m = m + i - table[i];
                (table[i] == -1) ? (i = 0) : (i = table[i]);
            }
            
        }
//        cout << "hehe" << endl;
        return NULL;
    }
};

int main()
{
	Solution* sl = new Solution();
	char haystack[] = "46234512";
	char needle[] = "345";
	char * res = sl->strStr(haystack, needle);
	return 0;
}


