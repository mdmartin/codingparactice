#include <iostream>
#include <cstring>
#include <string>
#include <unordered_set>
#if defined __GNUC__ || defined __APPLE__
#include <ext/hash_set>
#else
#include <hash_set>
#endif

using namespace std;

class Node
{
public:
	string word;
	int level;
	Node* next;
	Node(string w, int l)
	{
		level = l;
		word = w;
		next = NULL;
	}
};

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		int wordLen = start.length();
        
		dict.erase(start);
		dict.erase(end);
        
        unordered_set <string> used;
		used.insert(start);
        
		Node* first = new Node(start, 1);
		Node* cur = first;
		Node* last = first;
        
		while (1)
		{
            if (cur == NULL)
            {
                break;
            }
			string curWord = cur->word;
			int curLevel = cur->level;
			int count = 0;
			for (int i = 0; i < wordLen; i++)
			{
				if (curWord[i] != end[i])
				{
					count++;
				}
			}
			if (count == 1)
			{
				return curLevel + 1;
			}
            
			for (int i = 0; i < wordLen; i++)
			{
				string tempWord = curWord;
				char curChar = curWord[i];
				for (int j = 0; j < 26; j++)
				{
					char sbChar = char('a' + j);
					if (sbChar == curChar)
					{
						continue;
					}
					else
					{
						tempWord[i] = sbChar;
//                        cout << tempWord << endl;
						if (used.find(tempWord) == used.end() && dict.find(tempWord) != dict.end()) // and this node with tempWord
						{
//                            cout << tempWord << endl;
							Node* tempNode = new Node(tempWord, curLevel + 1);
							last->next = tempNode;
							last = last->next;
							used.insert(tempWord);
						}
					}
				}
			}
            
			// if append: new; last->next = new; last = last->next;
			// next iteration: cur = cur->next;
			cur = cur->next;
		}
        return 0;
    }
};



int main()
{
	string start = "hit", end = "cog";
	std::unordered_set<std::string> dict = {"hot","dot","dog","lot","log"};
	Solution *s = new Solution();
	cout << s->ladderLength(start, end, dict) << endl;
	
//	string a = "abdw";
//	a[2] = '4';
//	unordered_set <int> b (3,5,2);
	// cout << b << endl;
    
	return 0;
}

