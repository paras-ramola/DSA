#include<stdio.h>
#include<string.h>

void computeLPSArray(char pat[],int M,int lps[]){

int i=1;
int len=0;
while(i<M){
    if(pat[i]==pat[len]){
        len++;
        lps[i]=len;
        i++;
    }
    else{
        if(len!=0){
            len=lps[len-1];
        }
        else{
            lps[i]=0;
            i++;
        }
    }
}

}
void KMPsearch(char txt[],char pat[]){

int M=strlen(pat);
int N=strlen(txt);
printf("Pattern length: %d\n",M);
printf("Text length: %d\n",N);

int lps[M];//hold longest possible suffix value pattern

computeLPSArray(pat,M,lps);

int i=0;//for text
int j=0;//for pattern
while((N-i)>=(M-j)){
    if(pat[j]==txt[i]){
        i++;
        j++;
    }

    if(j==M){//j reached end of pattern
        printf("Found pattern at index %d",i-j);
        j=lps[j-1];//so that (M-j)>=(N-i) & loop breaks
    }

    else if(i<N && pat[j]!=txt[i]){
        if(j!=0){
            j=lps[j-1];
        }
        else{//j=0
            i=i+1;
        }
    }
}



}


int main(){
    char txt[]="ABABDABACDABABCABAB";
    char pat[]="ABABCABAB";
    KMPsearch(txt,pat);
    return 0;
}