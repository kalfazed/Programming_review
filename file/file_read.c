#include <stdio.h>

int main(int argc, char* argv[]){
    char ch;
    FILE *fp;
    int i;
    if((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Not open\n");
        exit(0);
    }
    while ((ch=fgetc(fp)) != EOF){
        putchar(ch);
    }

    fclose(fp);
}


