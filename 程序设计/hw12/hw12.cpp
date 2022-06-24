#include<stdio.h>
#include <string.h>
#include <stdio.h>
#include<windows.h>

/*
int main(){
    FILE *fp,*fp1;
    fp = fopen("secret.txt","r");
    char tt[1000];
    fgets(tt,1000,(FILE*)fp);
    fclose(fp);
    printf("%s\n",tt);
    for (int i=0; tt[i];i++){
        if((tt[i]>='a' && tt[i]<'t')||(tt[i]>='A' && tt[i]<'T')){
            tt[i] = tt[i]+7;
        }
        else if((tt[i]>='t' && tt[i]<='z')||(tt[i]>='T' && tt[i]<='Z')){
            tt[i] = tt[i]+('a'-'t');
        }
        else    continue;
    }
    printf("%s\n",tt);
    fp1 = fopen("secret.txt","w");
    fputs(tt,(FILE*)fp1);
    fclose(fp1);
}
*/

// #define DWORD (unsigned int)
// BOOL Beep(
//     DWORD dwFreq,
//     DWORD dwDuration
// );

int main(){
    FILE *fp;
    fp = fopen("music.txt","r");
    int b[25][2];
    for(int i=0;i<25;i++){
        for(int j=0;j<2;j++){
            fscanf(fp,"%d",&b[i][j]);
        }
    }
    fclose(fp);
    printf("ÕýÔÚ²¥·ÅÒõÀÖ"); 
    for(int i=0;i<25;i++){
        Beep(b[i][0],b[i][1]);
    }

}


