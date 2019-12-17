#!/bin/sh

echo "*****************************************************"
echo "***   This a program that converts ROOT files     ***"
echo "***        to  a Cooker friendly format           ***"
echo "*****************************************************"
echo "Please enter run number to be converted: "
read rnum;
echo "Please enter detector conversion: 1. Target & 2. MWPC"
read ch;
echo "Begin conversion..."
nice ./tgtGap -o run${rnum}conv.root -r ${rnum} -t ${ch} $path_tgtfiles/basicDataType_${rnum}.root
echo "conversion complete!"
echo "moving file to appropriate directory"
mv run${rnum}conv.root ${path_converted}
echo "moving complete!"
