#include <stdio.h>
#include "header.h"

int main()
{
     printf("\n\tWhat to do you want to do\n Encode or Decode\n");
     printf("\n\tType 1 for encoding\n Type 2 for decoding\n");
     
     int choice;
     printf("\n\tEnter your choice\n");
     scanf("%d",&choice);
     if(choice==1)
	Encoding();
     else 
	Decoding();     
}
