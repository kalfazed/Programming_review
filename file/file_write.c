#include <stdio.h>

int main(int argc, char* argv[]){
    char ch;
    FILE *fp;
    if((fp = fopen(argv[1], "w")) == NULL){
        printf("No file\n");
        exit(0);
    }
    while((ch = getchar()) != '\n' )
        fputc(ch, fp);
    fclose(fp);
}
