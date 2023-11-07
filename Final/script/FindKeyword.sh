#!/bin/bash
#Name:      Jasmine Anastasha Chieng Kiu Ying
#Purpose:   Find keywords in directories and subdirectories 
#	    and output them into an output file
#reference: Levon. "Get A List Of Directory Names With Find". Unix & Linux. August 24, 2012. 
#		    https://unix.stackexchange.com/questions/46244/get-a-list-of-directory-names-with-find
if [ $# = 0 ]; then
    echo "No argument provided."
    #check if there is no argument given
elif [ "$#" -ne 1 ]; then
    echo "Please enter only 1 argument."
    #check if there is more than one argument
else 
    #initialise output file name
    OUTPUT="output.txt"

    #remove old output.txt
    rm -f $OUTPUT

    #find the directory name
    dir=$(find . -mindepth 1 -maxdepth 1 -type d | cut -c 3-)
    
    #searches through the file for the keyworda
    SEARCH=$(grep -h -r "$1" "$dir")
    
    #writes to the output file
    echo "$SEARCH" >> $OUTPUT

    #sorts the content of the output file 
    #because it is in reverse order initially
    SORTED=$(sort $OUTPUT)
    
    #removes unsorted file
    rm -f $OUTPUT

    #writes the sorted data into a new output.txt
    echo "$SORTED" >> $OUTPUT
fi  



