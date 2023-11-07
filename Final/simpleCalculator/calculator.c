/*Name		:	Jasmine Anastasha Chieng Kiu Ying
  Date		: 	08/11/2021
  Reference	:	Dr.Ling Huo Chong. Seminar Demonstration, Septemer 23, 2021. https://youtu.be/4_jg8n-bydo ,
  	    		Chieng, Jasmine. Assignment 2. October 18, 2021.    
*/

#include<stdlib.h>
#include<stdio.h>
#include"calcInterface.h"

int main(int argc, char* argv[])
{	
    /*CHECKING FORMAT OF THE COMMAND LINE ARGUMENTS*/
    if(argc < 2)
    {
	printf("No argument provided.\nPlease follow the format: ./calculator <fileName>\n");
    }
    else if(argc > 2)
    {
	printf("More than 1 argument provided.\nPlease follow the format: ./calculator <fileName>\n");
    }
    else
    {
	interface(argv[1]);
    }

    return 0;
}


