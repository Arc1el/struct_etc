#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dup_check(char word[], int size, char ch){
    int i;
    for (i = 0; i < size; i++){
        if (word[i] == ch)
        return 1;
    }
    return 0;
}

char* key_input(){
    char buf[BUFSIZ];
    char *key;

    printf("키값을 입력하세요 : ");
    gets(buf);
    key = (char*)malloc(strlen(buf) + 1);
    strcpy(key, buf);

    return key;
}

int main(){
    char *key;
    key = key_input();
    char dup_key[strlen(key)];
    int i = 0, s = 0;
    
    for(i = 0; key[i] != '\0'; i++){
    	if(dup_check(dup_key, s, key[i]) == 0){
    		dup_key[s++] = key[i];
		}
	}
	printf("%s", dup_key);
}
