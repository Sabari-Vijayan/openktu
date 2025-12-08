#include<stdio.h>

int StringLenght (char *s){
    int i=0;
    while(*(s+i++)!='\0');
    return --i;
}

void StringCopy(char *s1, char *s2) {
    for(int i=0;*(s1+i)!='\0';i++){
        *(s2+i) = *(s1+i);
    }
}

int StringCompare (char *s1, char *s2){
    for(int i=0;*(s1+i)!='\0';i++){
        if(*(s2+i) == *(s1+i)){
            continue;
        }
        return (*(s1+i) - *(s2+i));
    }
}


void StringConcat(char *s, char *s2){
    int i=0,j=0;
    while(*(s+i++)!='\0');
    i--;
    while(*(s2+j)!='\0'){
        *(s+i) = *(s2+j);
        i++;
        j++;
    }
    *(s+i)='\0';
 }
int main(){
    char str[] = "Abc";
    char str2[10];
    char str3[] = "ABC";
    printf("Strlen: %d\n", StringLenght(str));

    StringCopy(str,str2);
    printf("Strcopy str2: %s\n", str2);
    printf("StrCompare: %d\n", StringCompare(str, str3));
    StringConcat(str, str3);
    printf("StrConcat: %s\n", str);
    
}
