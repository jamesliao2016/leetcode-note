#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstring>

using namespace std;
/*
 *  最简单的算法莫过于暴力破解了
 *
 *
 */
class Solution {
    public:
            int strStr(string haystack, string needle) {
                int start = 0;;
                while(start <= (haystack.size()-1)) {
                    if(needle.size() > (haystack.size() - start))
                        return -1;
                    int tmp = start;
                    auto p_needle = needle.begin();
                    while(p_needle != needle.end()) {
                        if(*p_needle == haystack[tmp]) {
                            ++tmp;
                            ++p_needle;
                            continue;
                        }
                        break;
                    }

                    if(p_needle == needle.end())
                        return start;
                    ++start;
                }
                return -1;
            }
};

int main()
{
    string stack = "zhang yifei";
    string needle = "yi";
    Solution so;
    cout <<  so.strStr(stack,needle) << endl;
}
