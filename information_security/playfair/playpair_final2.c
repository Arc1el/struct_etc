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

void build_table(char *key){	//���̺��� �����ϴ� �� 
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
	
	//ť�� Ȱ���Ͽ�, Ű���ǰ�� ť���� �������־���. 
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
		printf("\n\n");
	}
}


char* get_point(char ch){ //��ǥ�� ��� �Լ� 
	int point[2];
	int i, j, index_x = 0, index_y = 0;
	for(i = 0; i<5; i++){
		for(j= 0; j<5; j++){
			if(ch == table[i][j])
				break;
			index_y ++;
		}
		index_x ++;
	}
	point[0] = index_x;
	point[1] = index_y;
	return point;
}

char* type_check(char ch1, char ch2){ //Ÿ�� üũ�Ͽ� ���ڼ��������ִ� �� 
	int ch1_point[2];
	int ch2_point[2];
	char* ret_val;
	
	int i, j, index_x = 0, index_y = 0;
	
	for(i = 0; i<5; i++){
		for(j= 0; j<5; j++){
			if(ch1 == table[i][j]){
				index_x = i;
				index_y = j;
				break;
			}
		}
	}
	ch1_point[0] = index_x;
	ch1_point[1] = index_y;
	
	index_x = 0, index_y = 0;
	
	for(i = 0; i<5; i++){
		for(j= 0; j<5; j++){
			if(ch2 == table[i][j]){
				index_x = i;
				index_y = j;
				break;
			}
		}
	}
	ch2_point[0] = index_x;
	ch2_point[1] = index_y;
	
	int flag = 0;
	if(ch1_point[0] == ch2_point[0]){
		flag = 1;
	}
	else if(ch1_point[1] == ch2_point[1]){
		flag = 2;
	}
	else
		flag = 3;
		
	switch(flag){
		case 1: //����  ������ 
			//printf("�ٷ� ������ ���ڷ� ��ȣ");
			ret_val[0] = table[ch1_point[0]][ch1_point[1]+1];
			ret_val[1] = table[ch2_point[0]][ch2_point[1]+1];
			break;
		case 2: //���� ������ 
			//printf("�ٷ� �Ʒ����ڷ� ��ȣ");
			ret_val[0] = table[ch1_point[0]+1][ch1_point[1]];
			ret_val[1] = table[ch2_point[0]+1][ch2_point[1]];
			break;
		case 3: //�밢�� 
			//printf("�簢������� ������ ���ڷ� ��ȣȭ\n");
			ret_val[0] = table[ch2_point[0]][ch1_point[1]];
			//ret_val[0] = table[ch1_point[1]][ch2_point[0]];
			ret_val[1] = table[ch1_point[0]][ch2_point[1]];
			break;
	}
	
	return ret_val;
}

void encrypt(){ //��ȣȭ �Լ� 
	char buf[BUFSIZ];
    char *crypt_text;
    int i = 0;
	
    gets(buf);
    crypt_text = (char*)malloc(strlen(buf) + 1);
    strcpy(crypt_text, buf);
    int text_len = strlen(crypt_text);
    
	char text_table[text_len][2];
	char str_tmp[text_len][2];
	int text_index = 0;
	
	printf("\n");
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
	printf("\n===========================================================");
	printf("\n\n");
	
	
	if(tmp_index != 0){

		str_tmp[tmp_index][0] = text_table[tmp_index][0];
		str_tmp[tmp_index][1] = text_table[tmp_index][1];
		text_table[tmp_index][0] = tmp;
		text_table[tmp_index][1] = str_tmp[tmp_index][0];
		tmp_index ++;
		printf("\n");
	
		for (i = tmp_index; i<15; i++){
			str_tmp[i][0] = text_table[i][0];
			str_tmp[i][1] = text_table[i][1];
			text_table[i][0] = str_tmp[i-1][1];
			text_table[i][1] = str_tmp[i][0];
		}

		if(text_table[text_len/2][1] == '\0'){
			text_table[text_len/2][1] = 'x';
		}
		
		for(i = 0; i<text_len/2+1; i++){
    		printf("%c%c | ", text_table[i][0],text_table[i][1]);
		}

	}
	char *txt;
	printf("\n");
	for(i = 0; i<text_len/2+1; i++){ 
		txt = type_check(text_table[i][0], text_table[i][1]);
		printf("%c%c | ", txt[0], txt[1]);
	}
	printf("\n\n��ȣ�� : ");
	for(i = 0; i<text_len/2+1; i++){ 
		txt = type_check(text_table[i][0], text_table[i][1]);
		printf("%c%c", txt[0], txt[1]);
	}

}

int main(){ //���� �Լ� 
    char* key;
    key = key_input();
    
    printf("�ߺ� ���ŵ� Ű���� %s�Դϴ�.\n\n", key);
    build_table(key);
	printf("���� �Է��ϼ���\n");
    encrypt();

}
//becarefulforassassinator
