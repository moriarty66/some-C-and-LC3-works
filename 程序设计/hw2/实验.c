/*
#include <stdio.h>
int main(){
    char a,b;
    scanf("%c",&a);
    b = 'A'-'a';
    a = a+b;
    printf("%c",a);
    return 0;
}
*/

#include <stdio.h>
int main(){
    float a,b;
    scanf("%f %f",&a,&b);
    if(a<=1 && a>=-1){
        if(b<=1 && b>=-1){
            printf("yes");
        }
        else{
            printf("no");
        }
    }
    else{
        printf("no");
    }
    return 0;
}