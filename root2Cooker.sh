#!/bin/sh

echo "*****************************************************"
echo "***   This a program that converts ROOT files     ***"
echo "***        to  a Cooker friendly format           ***"
echo "*****************************************************"
# define some global variables here and assign them later
# I am hoping this works like python
file1="";
echo "Please enter run number to be converted: "
read rnum;
echo "Please enter detector conversion: 1. Target & 2. MWPC"
read ch;
echo "Begin conversion..."
if [ $ch == 1 ]; then
    nice ./tgtGap -o run${rnum}tgtConv.root -r ${rnum} -t ${ch} -f $path_tgtfiles/Run${rnum}MS_out.root
    file1=run${rnum}tgtConv.root
else
    if [ $ch == 2 ]; then
        nice ./tgtGap -o run${rnum}mwpcConv.root -r ${rnum} -t ${ch} -f $path_mwpcfiles/basicDataType_${rnum}.root
        file1=run${rnum}mwpcConv.root
    fi
fi
echo "conversion complete!"
echo "moving file to appropriate directory"
#mv run${rnum}conv.root ${path_converted}
mv $file1 ${path_converted}
echo "moving complete!"
