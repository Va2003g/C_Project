#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* binary(int temp) {
    char* bin = (char*)malloc(7 * sizeof(char));
    bin[6] = '\0';
    int i = 5;
    while (temp > 0) {
        int r = temp % 2;
        bin[i--] = r + '0';
        temp = temp / 2;
    }
    while (i >= 0) {
        bin[i--] = '0';
    }
    return bin;
}

int binToDec(char ch[]) {
    int ans = 0;
    int place = 1;
    for (int i = 7; i >= 0; i--) {
        if (ch[i] == '1') {
            ans += place;
        }
        place *= 2;
    }
    return ans;
}

char decode(char* ch) {
    char* ans = NULL;
    char* ans2 = NULL;
    for (int i = 0; i < 2; i++) {
        char temp = ch[i];
        int position = 0;

        if (temp >= 'A' && temp <= 'Z') {
            position = temp - 'A';
        } else if (temp >= 'a' && temp <= 'z') {
            position = temp - 'a' + 26;
        } else if (temp >= '0' && temp <= '9') {
            position = temp - '0' + 52;
        }else if(temp=='='){
		position = 0;
	}

        char* bin = binary(position);

        if (i == 0) {
            ans = bin;
        } else {
            ans2 = bin;
        }
    }

    char temp[9];
    for (int i = 0; i < strlen(ans); i++) {
        temp[i] = ans[i];
    }
    temp[6] = ans2[0];
    temp[7] = ans2[1];
    temp[8] = '\0';

    int numAscii = binToDec(temp);
    char finalAns = (char)numAscii;
    return finalAns;
}

int Decoding() {
    char inputFile[20], outputFile[20];

    printf("Enter the name of the file to be Decoded:\n");
    scanf("%s", inputFile);

    printf("Enter the name of the output file:\n");
    scanf("%s", outputFile);

    FILE* readFile, * outFile;

    readFile = fopen(inputFile, "r");

    if (readFile == NULL) {
        printf("File not found\n");
        return 1;
    }

    outFile = fopen(outputFile, "w");

    if (outFile == NULL) {
        printf("Failed to create output file\n");
        fclose(readFile);
        return 1;
    }

    char ch;
    char* temp = (char*)malloc(5 * sizeof(char));
    ch = fgetc(readFile);
    while (ch != EOF) {
        int i = 0;
        while (i < 4 && ch != EOF) {
            temp[i++] = ch;
            ch = fgetc(readFile);
        }
        temp[i] = '\0';
	//printf("temp: %s",temp);
        char characterDecoded = decode(temp);
        fprintf(outFile, "%c", characterDecoded);

    }

    fclose(outFile);
    fclose(readFile);

    printf("%s is decoded and saved to %s\n", inputFile, outputFile);

    free(temp);

    return 0;
}
