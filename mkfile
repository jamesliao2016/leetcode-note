#!/bin/bash
#
#Create a .cc file based on the incoming information，
#and then add some native code
#####################################################

filename=`date +"%F"`

for i in $@;do
    filename="${filename}_$i"
done

filename="${filename}.cc"
if [ -e $filename ];then
    echo "error $filename exists"
fi

cat << EOF  > $filename
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
}
EOF

vim +8 $filename

