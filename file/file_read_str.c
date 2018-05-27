#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    char str[20];
    FILE *fp;
    int i;
    if((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Not open\n");
        exit(0);
    }

    /* the maxsize of line is 20 */
    while(fgets(str, 20, fp)!=NULL)
        printf("%s", str);

    fclose(fp);
}


