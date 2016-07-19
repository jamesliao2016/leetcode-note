#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/*
 *  元字符只有*号和.号,因此做线性扫描o(n)应该是可以解决问题的
 *  比如: aab,pattern:c*a*b
 *
 *  读取到a然后,去pattern中读取c不匹配,继续读取*,能匹配
 *
 *  isMatch("aa","a") → false
 *  isMatch("aa","aa") → true
 *  isMatch("aaa","aa") → false
 *  isMatch("aa", "a*") → true
 *  isMatch("aa", ".*") → true
 *  isMatch("ab", ".*") → true
 *  isMatch("aab", "c*a*b") → true
 *
 *
 */


class Solution {
    public:
        bool isMatch(string s, string p) {
            int flag = 0;
            bool is_true = true;
            int last_index = 0;
            for(auto ch : s) {

                if(last_index >= p.size())
                    return false;

                while(last_index < p.size()){
                    //第一种情况,字符匹配
                    if(!flag && p[last_index] == ch) {
                        ++last_index;
                        break;
                    }

                    //第二种情况,.号元字符匹配任意
                    if(!flag && p[last_index] == '.') {
                        ++last_index;
                        break;
                    }

                    //第三种情况,匹配到*号
                    if(!flag  && p[last_index] == '*' ) {

                        if(p[last_index-1] == '.') {

                            break;//但是last_index 不++

                        } else if(p[last_index-1] == ch) {

                            break;//但是last_index 不++

                        }else {
                            //以上都不是, 那么
                            //is_true = false;
                            ++last_index;
                            continue;
                        }

                    }

                    //第四种情况
                    if(!flag && p[last_index] != '*' && p[last_index] != '.') {
                        flag = 1;
                        ++last_index;
                        continue;
                    }

                    //第五种情况,前一次没匹配的情况
                    if(flag && p[last_index] == '*') {
                        ++last_index;
                        flag = 0;
                        continue;
                    }

                    is_true = false;
                    break;
                }

                if(!is_true)
                    return false;
            }

            if(p[last_index] == '*' && last_index < (p.size() - 1))
                return false;

            if(p[last_index] != '*' && last_index < p.size())
                return false;

            return true;
        }
};

int main()
{
    Solution so;
    cout << so.isMatch("aa","a") << endl;
    cout << so.isMatch("aa","aa") << endl;
    cout << so.isMatch("aaa","aa") << endl;
    cout << so.isMatch("aa", "a*") << endl;
    cout << so.isMatch("aa", ".*") << endl;
    cout << so.isMatch("ab", ".*") << endl;
    cout << so.isMatch("aab", "c*a*b") << endl;
    cout << so.isMatch("aa", ".*c") << endl;
    cout << so.isMatch("aa", "aaa") << endl;
}
