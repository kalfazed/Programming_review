#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    char str[20];
    FILE *fp1, *fp2;
    int i;
    if((fp1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Not open\n");
        exit(0);
    }

    if((fp2 = fopen(argv[2], "w")) == NULL)
    {
        printf("Not open\n");
        exit(0);
    }

    /* the maxsize of line is 20 */
    /* over write */
    while(fgets(str, 20, fp1)!=NULL)
        fputs(str, fp2);

    fclose(fp1);
    fclose(fp2);
}


