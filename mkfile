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
#include <vector>

using namespace std;

int main()
{

}
EOF

pyfilename="$filename.py"
if [ -e $pyfilename ];then
     echo "error $pyfilename exists"
fi

cat << EOF > $pyfilename
#!/usr/bin/env python
# encoding: utf-8


if __name__ == "__main__":

EOF
vim +8 $ccfilename

