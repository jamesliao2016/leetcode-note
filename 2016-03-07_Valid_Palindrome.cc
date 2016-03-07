#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <cctype>

using namespace std;

/*
 *  这题还是比较简单的,两个指针,分别从头和尾开始向中间遍历,判断是否相同,
 *  但是需要过滤掉非字符的一些字符即可
 *
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0;
        int end = s.size()-1;
        find_next(s,begin,end);

        while(begin <= end) {
            if(tolower(s[begin]) != tolower(s[end]))
                return false;
            ++begin;
            --end;
            find_next(s,begin,end);
        }
        return true;
    }

private:
    void find_next(string& s,int &begin,int &end)
    {
        while(!isalnum(s[begin]) && begin <= end) {
            ++begin;
        }

        while(!isalnum(s[end]) && end >= begin) {
            --end;
        }
    }
};

class Solution2 {
    public:
            bool isPalindrome(string s) {
                transform(s.begin(),s.end(),s.begin(),::tolower);
                auto left = s.begin(),right = prev(s.end());
                while(left < right) {
                    if(!::isalnum(*left)) ++ left;
                    else if(!isalnum(*right)) --right;
                    else if(*left != *right) return false;
                    else {left++,right--;}
                }
                return true;
            }
};
int main()
{
    Solution so;
    string text = "0p";
    cout << so.isPalindrome(text) << endl;
}
