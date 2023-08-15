#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

char* binaryEnc(int temp)

{

    char* bin = (char*) malloc(9*sizeof(char));

    bin[8] = '\0';

    int i = 7;

 

    while(temp>0)

    {

        int r = temp % 2;

        bin[i--] = r + '0';

        temp = temp / 2;

    }

 

    if(i>=0)

    {

        bin[i--] = '0';

    }

 

    return bin;

 

}

 

int binToDecEnc(char* ch)

{

    int ans = 0;

    int place = 1;

    for(int i = strlen(ch)-1;i>=0;i--)

    {

        if(ch[i]=='1')

        {

            ans += place;

        }

        place*=2;

    }

    return ans;

}

char* base64(char ch)

{

    char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int temp = ch;

    char* binStr = binaryEnc(temp);

    //printf("%s \n",binStr); 

    //breaking binStr in 6bits chunks

 

    char firstChunk[7];

 

    for(int i = 0;i<6;i++)

    {

        firstChunk[i] = binStr[i];

    }

 

    firstChunk[6] = '\0';

 

    char rightChunk[7];

    int k = 0;

    for(int i = 0;i<6;i++)

    {

        if(i>1)

        {

            rightChunk[k++] = '0';

        }

        else

        {

            rightChunk[k++] = binStr[6+i];

        }

    }

    rightChunk[6] = '\0';

 

   

    int firstInt = binToDecEnc(firstChunk);

    int secondInt = binToDecEnc(rightChunk);

 

    char* ans = (char*) malloc(5*sizeof(char));

    ans[0] = encoding_table[firstInt];

    ans[1] = encoding_table[secondInt];

    ans[2] = '=';

    ans[3] = '=';

    ans[4] = '\0';

 

    // puts(ans);

    return ans;

 

}

 

int Encoding() {

   
    char inputFile[20],outputFile[20];

    printf("Enter the name of the file to be encoded:\n");
    scanf("%s",inputFile);

    printf("Enter the name of the output file:\n");
    scanf("%s",outputFile);

    FILE *readFile,*outFile;

    readFile = fopen(inputFile,"r");

    if(readFile==NULL)
    {
	printf("File not found\n");
    }
    else
    {
	outFile = fopen(outputFile,"w");;
	char ch = fgetc(readFile);
	while(ch!=EOF)
	{
	   if(ch==' '|| ch=='\n'){
		ch = fgetc(readFile);
		continue;
	   }
	   char* temp = base64(ch);
	   fprintf(outFile,"%s",temp);
           ch  = fgetc(readFile);	   
	}
	fclose(outFile);

    }
    fclose(readFile);
   
    printf("\n %s is encoded with base64 scheme as %s\n",inputFile,outputFile);
   // printf("%s\n",binary(16));
    return 0;

}
