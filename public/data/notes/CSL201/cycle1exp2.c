#include<stdio.h>
#include<string.h>

void substring(char str[]){
    int len = strlen(str);
    char c[len];
    int checklist[256] = {0};
    int n =0,k = 0;
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            for(k=i;k<j;k++){
                if(checklist[str[k]]!=0){
                    break;           
                }   
                c[n++] = str[k];
                checklist[str[k]] = 1;       
            }
        }
    }
    c[n] = '\0';
    printf("Longest Substring: %s\n", c);
    printf("Length Longest substring: %d", strlen(c));

}

void main(){
    char str[] = "abcabcdefabcde";
    substring(str);
}
