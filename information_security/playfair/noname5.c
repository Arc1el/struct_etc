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
	char queue[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u', 'v', 'w', 'x', 'y', 'z'};
	
	int queue_len = 26;
	
	int k = 0;
	int delete_count = 0;
	
	for(i = 0; i<key_len; i++){
		for(j =0; j<26; j++){
			if(key[i] == queue[j]){
				for(k = j ; k<queue_len ; k++){
					queue[k] = queue[k+1];
				}
			delete_count ++;
			}
		}
	}
	/*
	queue_len = 26 - delete_count;
	printf("\n%d\n",queue_len);
	
	for(i=0; i<queue_len; i++){
		printf("%c ", queue[i]);
	}
	*/
	
	int queue_index = 0;
	
	for(i = 0; i<5; i++){
		for(j = 0; j<5; j++){
			if(table[i][j] == '\0')
			{
				table[i][j] = queue[queue_index];
				queue_index ++;
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

void encrypt(){
	char buf[BUFSIZ];
    char *crypt_text;
    int i = 0;
    getchar();
	printf("���� �Է��ϼ���\n");
	
    gets(buf);
    crypt_text = (char*)malloc(strlen(buf) + 1);
    strcpy(crypt_text, buf);
    int text_len = strlen(crypt_text);
    
	char text_table[text_len][2];
	char str_tmp[text_len][2];
	int text_index = 0;
	
	for(i = 0; i<strlen(crypt_text); i= i+1){
		text_table[i][0] = crypt_text[text_index];
		text_table[i][1] = crypt_text[text_index+1];
		text_index = text_index + 2;
	}
	
	char *tmp;
	char tmp_index = 0;
	
	for(i = 0; i<strlen(crypt_text)/2; i++){
		if(text_table[i][0] == text_table[i][1]){
			tmp = text_table[i][1];
			tmp_index = i+1;
			text_table[i][1] = 'x';
		}
	}
	
	for(i = 0; i<text_len/2; i++){
    	printf("%c%c | ", text_table[i][0],text_table[i][1]);
	}
	printf("\n");
	
	//printf("%c, %c\n", text_table[9][0],text_table[9][1]);
	
	if(tmp_index != 0){
		//printf("���� index : %d\n", tmp_index);
		str_tmp[tmp_index][0] = text_table[tmp_index][0];
		str_tmp[tmp_index][1] = text_table[tmp_index][1];
		text_table[tmp_index][0] = tmp;
		text_table[tmp_index][1] = str_tmp[tmp_index][0];
		//text_table[0][1] = tmp;
		//printf("���� ����� �� : %c %c �ε��� : %d\n", str_tmp[tmp_index][0], str_tmp[tmp_index][1], tmp_index); //[9][0] = n [9][1] = i
		printf("���� ����� �� : [%d][0]%c [%d][1]%c �ε��� : %d\n", tmp_index,str_tmp[tmp_index][0], tmp_index, str_tmp[tmp_index][1], i);
		tmp_index ++;
		
		for(i = 0; i<text_len/2+1; i++){
    		printf("%c%c | ", text_table[i][0],text_table[i][1]);
		}
		printf("\n");
		//[10][0] [10][1]
		/*
		for(i = tmp_index; i<strlen(crypt_text)-tmp_index; i++){
			printf("���� index : %d\n", i);
			str_tmp[i][0] = text_table[i-1][0];
			printf("%c�� %c ����\n", str_tmp[i][0], text_table[i-1][0]);
			str_tmp[i][1] = text_table[i-1][1];
			printf("%c�� %c ����\n", str_tmp[i][1], text_table[i-1][1]);
			text_table[i][0] = str_tmp[i-1][1];
			printf("%c�� %c�� �ٲ�\n", text_table[i][0] , str_tmp[i-1][1]);
			text_table[i][1] = str_tmp[i+1][0];
			printf("%c�� %c�� �ٲ�\n", text_table[i][1] , str_tmp[i+1][0]);
		}*/
		for (i = tmp_index; i<15; i++){
			str_tmp[i][0] = text_table[i][0];
			str_tmp[i][1] = text_table[i][1];
			printf("���� ����� �� : [%d][0]%c [%d][1]%c �ε��� : %d\n", i,str_tmp[i][0], i, str_tmp[i][1], i);
			//[9][0] i [9][1] n [10][0] a [10][0] t
			text_table[i][0] = str_tmp[i-1][1];
			text_table[i][1] = str_tmp[i][0];
			
		//if(text_table[strlen(text_table)/2][1] == '\0')
		//	text_table[strlen(text_table)/2][1] == 'x';
		
		}
		for(i = 0; i<text_len/2+1; i++){
    		printf("%c%c | ", text_table[i][0],text_table[i][1]);
		}
		//printf("\n\n%c", text_table[strlen(text_table)/2][1]);
	}
	
	
    

	
	/*
    for(i = 0; i<strlen(crypt_text); i=i+2){
    	printf("%c%c | ", crypt_text[i],crypt_text[i+1]);
	}
	*/
}
void decrypt(){
	
}

int main(){
    char* key;
    key = key_input();
    int opt; 
    
    printf("�ߺ� ���ŵ� Ű���� %s�Դϴ�.\n\n", key);
	printf("���̺��� �����մϴ�. \n");
    build_table(key);
    
    printf("�ɼ��� �����ϼ���. (1:��ȣȭ 2:��ȣȭ)");
    scanf("%d", &opt);
    
    switch(opt){
    	case 1 : //��ȣȭ  
    		
    		encrypt();
    		break;
    	case 2 : //��ȣȭ 
    		printf("��ȣ���� �Է��ϼ���\n");
    		decrypt();
    		break; 
	}

}
//becarefulforassassinator
