#include <stdio.h>
#include <string.h>
#define N 5

int main(int argc, char* argv[]){
    int i;
    int size = sizeof(int);
    int a[size], b[size];
    FILE *fp;

    /* binary, rb+ */
    if((fp = fopen(argv[1], "rb+")) == NULL){
        printf("fail to open\n");
        exit(0);
    }

    printf("Input the data\n");

    for(i=0; i<N; i++)
        scanf("%d", &a[i]);

    fwrite(a, size, N, fp);

    /* reset the fp to the head the file*/
    rewind(fp);

    fread(b, size, N, fp);
    for(i=0; i<N; i++)
        printf("%d", b[i]);
    
    fclose(fp);
}
