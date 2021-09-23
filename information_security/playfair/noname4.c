#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char table[5][5] = {0,}; //���������� ���̺� ���� 

int dup_check(char word[], int size, char ch){ //�ߺ��˻��ϴ� �Լ� 
    int i;
    for (i = 0; i < size; i++){
        if (word[i] == ch)
        return 1;
    }
    return 0;
}

char* key_input(){ //Ű�� �Է¹޾� �ߺ����� �� �� ���� �������ִ� �Լ�  
    char buf[BUFSIZ];
    char *key;

    printf("Ű���� �Է��ϼ��� : ");
    gets(buf);
    key = (char*)malloc(strlen(buf) + 1);
    strcpy(key, buf);
    
    char dup_key[strlen(key)];
    int i = 0, s = 0;
    
    for(i = 0; key[i] != '\0'; i++){
    	if(dup_check(dup_key, s, key[i]) == 0){
    		dup_key[s++] = key[i];
		}
	}

    return dup_key;
}

void build_table(char *key){
	printf("���̺��� �����մϴ�. \n");
	
	int key_len = strlen(key);
	int i = 0, j = 0;
	
	if(key_len >= 5){
		for(i = 0; i<key_len; i++)
			table[0][i] = key[i];
	}
	else if(key_len > 5 && key_len <= 10){
		for(i = 0; i<key_len; i++)
			table[0][i] = key[i];
		for(i = 0; i<key_len; i++)
			table[1][i] = key[i+5];
	}
	else if(key_len > 10 && key_len <= 15){
		for(i = 0; i<key_len; i++)
			table[0][i] = key[i];
		for(i = 0; i<key_len; i++)
			table[1][i] = key[i+5];
		for(i = 0; i<key_len; i++)
			table[2][i] = key[i+10];
	}
	else if(key_len > 15 && key_len <= 20){
		for(i = 0; i<key_len; i++)
			table[0][i] = key[i];
		for(i = 0; i<key_len; i++)
			table[1][i] = key[i+5];
		for(i = 0; i<key_len; i++)
			table[2][i] = key[i+10];
	}
	else{
		for(i = 0; i<key_len; i++)
			table[0][i] = key[i];
		for(i = 0; i<key_len; i++)
			table[1][i] = key[i+5];
		for(i = 0; i<key_len; i++)
			table[2][i] = key[i+10];
		for(i = 0; i<key_len; i++)
			table[2][i] = key[i+15];
	}
	for(i = 0; i<5; i++){
		for(j= 0; j<5; j++){
			printf("%c   ", table[i][j]);
		}
		printf("\n");
	}
	
	// key = ban
	char stack[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u', 'v', 'w', 'x', 'y', 'z'};
	
	int stack_len = 26;
	
	int k = 0;
	int delete_count = 0;
	
	for(i = 0; i<key_len; i++){
		for(j =0; j<26; j++){
			if(key[i] == stack[j]){
				for(k = j ; k<stack_len ; k++){
					stack[k] = stack[k+1];
				}
			delete_count ++;
			}
		}
	}
	/*
	stack_len = 26 - delete_count;
	printf("\n%d\n",stack_len);
	
	for(i=0; i<stack_len; i++){
		printf("%c ", stack[i]);
	}
	*/
	
	int stack_index = 0;
	
	for(i = 0; i<5; i++){
		for(j = 0; j<5; j++){
			if(table[i][j] == '\0')
			{
				table[i][j] = stack[stack_index];
				stack_index ++;
			}
		}
	}
	printf("������ ���̺��� ����մϴ�. (��, q�� q/z)\n");
	for(i = 0; i<5; i++){
		for(j= 0; j<5; j++){
			printf("%c   ", table[i][j]);
		}
		printf("\n");
	}
}

int main(){
    char* key;
    key = key_input();
    int i, j; 
    printf("�ߺ� ���ŵ� Ű���� %s�Դϴ�.\n", key);
    build_table(key);

}
