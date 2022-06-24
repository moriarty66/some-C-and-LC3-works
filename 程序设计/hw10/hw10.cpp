#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>



int *form(int *m,int n,int *n){
    int tmp;
    int a[n][n];
    int siz = n*n;
    int aa[siz];
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
        	a[j][k] = *(m+j*n+k);
            aa[n*j+k] = a[j][k];
        }
    }
    
    //bubble
    for(int i=0;i<siz-1;i++){
        for(int j=0;j<siz-i-1;j++){
            if(aa[j]>aa[j+1]){
                tmp = aa[j];
                aa[j] = aa[j+1];
                aa[j+1] = tmp;
            }
        }
    }
    
    int min[4] = {aa[0],aa[1],aa[2],aa[3]};
    int temp[4] = {a[0][0],a[0][n-1],a[n-1][0],a[n-1][n-1]};
    for(int i=0;i<4;i++){
    	if(min[i]==a[0][0] || min[i]==a[0][n-1] || min[i]==a[n-1][0] || min[i]==a[n-1][n-1]){
    		min[i] = 999;
		}
		if(min[0]==temp[i] || min[1]==temp[i] || min[2]==temp[i] || min[3]==temp[i]){
    		temp[i] = 999;
		}

	}
    
   
    // find location
    int loc[4][2];
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
            	if(min[i]==999){
            		loc[i][0] = 999;
            		loc[i][1] = 999;
				}
                else if(a[j][k] == min[i]){
                    loc[i][0] = j;
                    loc[i][1] = k;
                }
            }
        }
    }
    int l=0;
    for(int i=0;i<4;i++){
    	if(loc[i][0]!=999){
    		while(l<4){
    			if(temp[l]!=999){
    				a[loc[i][0]][loc[i][1]] = temp[l];
    				l++;
    				break;
				}
				else	l++;
			}
    		
		}
    	
	}
	
    a[0][0] = aa[0];
    a[0][n-1] = aa[1];
    a[n-1][0] = aa[2];
    a[n-1][n-1] = aa[3];
    
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            aa[n*j+k] = a[j][k];
        }
    }
    n = &aa[0];
    return n;
}
int main(){
    int n;
    scanf("%d",&n);
    int m[n][n];
    int a[n*n];
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		scanf("%d",&a[i*n+j]);  
    		m[i][j] = a[i*n+j];
    		printf("%d\t",m[i][j]);
		}   
		printf("\n");
    }
    printf("\n");
    int *b;
    b = form(a,n,b);
    for(int j=0;j<n;j++){
        for(int k = 0;k<n;k++){
            printf("%d\t",b[j*n+k]);
        }
        printf("\n");
    }
    return 0; 
}

/* 
int main(){
	int num;
    scanf("%d",&num);
    getchar();
    char data[num][50];
    for(int i=0;i<num;i++){
        gets(data[i]);
    }
    double sum=0,avg,var;
    double *nm = (double*)malloc(num*sizeof(double));
    for(int i=0;i<num;i++){
        nm[i] = (double)atof(data[i]);
        sum += nm[i];
    }
    avg = sum/num;
    for (int j = 0; j <= num;j++)
    {
        var += pow(nm[j]-avg,2)/num;//求方差
    }
    printf("方差是：%lf",var);
}




void reserve(char *p, char *q)
{
    while(p < q)
    {
        *p ^= *q;  //利用异或运算得到两字符交换
        *q ^= *p;
        *p ^= *q;
        p++;
        q--;
    }
}
void loopMove(char *str, int steps)
{
    char *p = str;
    int len = strlen(str);
    char *q = p + len - 1 - steps;
     
    reserve(p, q);     
    p = q + 1;
    q = str + len - 1;
    reserve(p, q);   
    p = str;
    reserve(p, q);   
     
}
 
int main()
{
    char string[50];
    gets(string);
    int steps = 0;
 
    printf("string: %s\n", string);
    printf("input step: ");
    scanf("%d", &steps);
    loopMove(string,steps);
    printf("after loopMove %d: %s\n", steps, string);
 
    return 0;
}
*/

