#include <stdio.h>
#include <string.h>

int main(){
    char *ptr_string = "helloworld";
    printf("ptr_string len:%d\n",strlen(ptr_string));



    printf("==============strcpy==================\n");
    char str_array2[20] = {'\0'};
    strcpy(str_array2,ptr_string);
    printf("str_array2:%s\n",str_array2);
    printf("---------------------------\n");

    char str_array3[10] = {"1234567890"};
    strncpy(str_array3,ptr_string,7);
    printf("str_array3:%s\n",str_array3);




    printf("===============strcmp===============\n");

    char *ptr_string_1 = "helloworld";
    char *ptr_string_2 = "helloworld";

    printf("value:%d\n",strcmp(ptr_string_1,ptr_string_2));
    char *ptr_string_3 = "Japan";
    printf("value:%d\n",strcmp(ptr_string_3,ptr_string_2));




    printf("=============strcat=================\n");
    char str_array4[100] = "hello";
    strcat(str_array4,str_array3);
    printf("str_array4:%s\n",str_array4);

    strncat(str_array4,str_array3, 5);
    printf("str_array4:%s\n",str_array4);




    printf("============strchr=================\n");
    char *ptr_string_4 = strchr(str_array4,'l');
    printf("ptr_string4:%s,%c\n",ptr_string_4,*ptr_string_4);

    char *ptr_string_5 = strrchr(str_array4,'l');
    printf("ptr_string4:%s,%c\n",ptr_string_5,*ptr_string_5);

    if(strchr(ptr_string_5,'o')!=NULL){
        printf("ptr_string_5 contains o!\n");
    }else{
        printf("ptr_string_5 not contains o!\n");
    }




    printf("==================strstr===========\n");
    char *str9 = "hello";
    char *str10 = "first helloworld";
    if(strstr(str10,str9) != NULL){
        printf("str10 contains str9\n");
    }else{
        printf("str10 not contains str9\n");
    }




    printf("=================strtok=============\n");

    char str[] ="hello: zzf-hello:tom";
    char *p = strtok(str,"-: ");

    while(p!=NULL){
        printf("%s",p);
        p = strtok(NULL,"-: ");
        printf("\n");
    }

    printf("================memset,memcpy==========\n");
    char src[] = "i love you";
    char des[] = "you love me";
    memset(des,0,sizeof(des));
    memcpy(des,src,sizeof(des)-1);
    return 0;
}
