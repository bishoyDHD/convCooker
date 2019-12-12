#!/bin/sh

echo "*****************************************************"
echo "***   This a program that converts ROOT files     ***"
echo "***        to  a Cooker friendly format           ***"
echo "*****************************************************"
echo "Please enter run number to be converted: "
read rnum;
echo "Begin conversion..."
nice ./tgtGap -o run${rnum}conv.root $path_tgtfiles/Run${rnum}MS_out.root
echo "conversion complete!"
echo "moving file to appropriate directory"
mv run${rnum}conv.root ${path_converted}
echo "moving complete!"
