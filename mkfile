#!/bin/bash
#
#Create a .cc file based on the incoming information，
#and then add some native code
#####################################################

filename=`date +"%F"`

for i in $@;do
    filename="${filename}_$i"
done

ccfilename="${filename}.cc"
if [ -e $ccfilename ];then
    echo "error $ccfilename exists"
fi

cat << EOF  > $ccfilename
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};
int main()
{

}
EOF

vim +8 $ccfilename

