#include<stdio.h>
#include<string.h>
int main()
{
    char a[50];
    gets(a);
    for(int i=0;i<strlen(a);i++)
    {
        if((a[i]>='a'&&a[i]<'y')||(a[i]>='A'&&a[i]<'Y'))
      {
          a[i]=a[i]+1;
      }
       else if(a[i]=='z')
       {
            a[i] = 'a';
       }    
	   else if(a[i]=='Z'){
		   a[i] = 'A';
	   } 
       else
           a[i]=a[i];
     } 
    puts(a);
    return 0;
 }
