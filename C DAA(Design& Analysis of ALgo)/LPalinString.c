#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int max(int a,int b){
    if(a>b ) return a;
    else return b;
}
int longestCommonSubsequence(char s1[],char s2[]){

    int m=strlen(s1);
    int n=strlen(s2);

    int mat[m+1][n+1];//declaring a matrix

for(int i=0;i<=m;i++){//first row=0
    mat[i][0]=0;
}
for(int i=0;i<=n;i++){//first coloumn=0
    mat[0][i]=0;
}
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){//if same element are added 
                mat[i][j]=1+mat[i-1][j-1];
            }
            else{// if diff element are added,check maximum in daigonal
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
   int i=m,j=n;
    int lcs[m+1];
    int k=0;

   while(i>0 &&j>0){
    if(s1[i-1]==s2[j-1]){

        lcs[k++]=s1[i-1];
        i--;
        j--;
   }
   else if(mat[i-1][j]>mat[i][j-1]){
    i--;
   }
   else{
    j--;
   }
   }
   printf("Longest Common Subsequence String is :" );
   for(int i=0;i<=m;i++){
    printf("%c",lcs[i]);
   }
lcs[k]='\0';
   
    return mat[m][n];
}

int main() {
    char str[40];
    printf("Enter the string: ");
    scanf(" %[^\n]s", str);

    char revStr[40];
    int m = strlen(str);

    int k = 0;
    for (int i = 0; i <m; i++) {
        revStr[i] = str[m-i-1];
    }
    revStr[m] = '\0'; // Null-terminate the reversed string

    printf("\nReversed String: %s\n", revStr);

    int n = longestCommonSubsequence(str, revStr);
    printf("\nLongest Palindromic Subsequence Length: %d\n", n);

    return 0;
}
