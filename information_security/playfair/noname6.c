#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char table[5][5] = {0,}; //전역변수로 테이블 선언 

int dup_check(char word[], int size, char ch){ //중복검사하는 함수 
    int i;
    for (i = 0; i < size; i++){
        if (word[i] == ch)
        return 1;
    }
    return 0;
}

char* key_input(){ //키를 입력받아 중복제거 한 후 값을 리턴해주는 함수  
    char buf[BUFSIZ];
    char *key;

    printf("키값을 입력하세요 : ");
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
	printf("사이퍼 테이블을 출력합니다. (단, q는 q/z)\n");
	for(i = 0; i<5; i++){
		for(j= 0; j<5; j++){
			printf("%c   ", table[i][j]);
		}
		printf("\n");
	}
}


char* get_point(char ch){
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

char* type_check(char ch1, char ch2){
	int ch1_point[2];
	int ch2_point[2];
	char* ret_val;
	
	//printf("\n%c 의 좌표를 출력합니다. ", ch1);
	
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
	//printf("(%d, %d)\n", ch1_point[0], ch1_point[1]);
	
	//printf("\n%c 의 좌표를 출력합니다. ", ch2);
	
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
	//printf("(%d, %d)\n", ch2_point[0], ch2_point[1]);
	
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
		case 1: //가로  같은줄 
			//printf("바로 오른쪽 문자로 암호");
			ret_val[0] = table[ch1_point[0]][ch1_point[1]+1];
			ret_val[1] = table[ch2_point[0]][ch2_point[1]+1];
			break;
		case 2: //세로 같은줄 
			//printf("바로 아랫문자로 암호");
			ret_val[0] = table[ch1_point[0]+1][ch1_point[1]];
			ret_val[1] = table[ch2_point[0]+1][ch2_point[1]];
			break;
		case 3: //대각선 
			//printf("사각형만들어 꼭지점 문자로 암호화\n");
			ret_val[0] = table[ch2_point[0]][ch1_point[1]];
			//ret_val[0] = table[ch1_point[1]][ch2_point[0]];
			ret_val[1] = table[ch1_point[0]][ch2_point[1]];
			break;
	}
	
	return ret_val;
}

void encrypt(){
	char buf[BUFSIZ];
    char *crypt_text;
    int i = 0;
    getchar();
	printf("평문을 입력하세요\n");
	
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
	printf("\n\n");
	
	
	if(tmp_index != 0){
		//printf("현재 index : %d\n", tmp_index);
		str_tmp[tmp_index][0] = text_table[tmp_index][0];
		str_tmp[tmp_index][1] = text_table[tmp_index][1];
		text_table[tmp_index][0] = tmp;
		text_table[tmp_index][1] = str_tmp[tmp_index][0];
		//text_table[0][1] = tmp;
		//printf("현재 저장된 값 : %c %c 인덱스 : %d\n", str_tmp[tmp_index][0], str_tmp[tmp_index][1], tmp_index); //[9][0] = n [9][1] = i
		//printf("현재 저장된 값 : [%d][0]%c [%d][1]%c 인덱스 : %d\n", tmp_index,str_tmp[tmp_index][0], tmp_index, str_tmp[tmp_index][1], i);
		tmp_index ++;
		/*
		for(i = 0; i<text_len/2+1; i++){
    		printf("%c%c | ", text_table[i][0],text_table[i][1]);
		}*/
		printf("\n");
		//[10][0] [10][1]
		/*
		for(i = tmp_index; i<strlen(crypt_text)-tmp_index; i++){
			printf("현재 index : %d\n", i);
			str_tmp[i][0] = text_table[i-1][0];
			printf("%c에 %c 저장\n", str_tmp[i][0], text_table[i-1][0]);
			str_tmp[i][1] = text_table[i-1][1];
			printf("%c에 %c 저장\n", str_tmp[i][1], text_table[i-1][1]);
			text_table[i][0] = str_tmp[i-1][1];
			printf("%c를 %c로 바꿈\n", text_table[i][0] , str_tmp[i-1][1]);
			text_table[i][1] = str_tmp[i+1][0];
			printf("%c를 %c로 바꿈\n", text_table[i][1] , str_tmp[i+1][0]);
		}*/
		for (i = tmp_index; i<15; i++){
			str_tmp[i][0] = text_table[i][0];
			str_tmp[i][1] = text_table[i][1];
			//printf("현재 저장된 값 : [%d][0]%c [%d][1]%c 인덱스 : %d\n", i,str_tmp[i][0], i, str_tmp[i][1], i);
			//[9][0] i [9][1] n [10][0] a [10][0] t
			text_table[i][0] = str_tmp[i-1][1];
			text_table[i][1] = str_tmp[i][0];
			
		//if(text_table[strlen(text_table)/2][1] == '\0')
		//	text_table[strlen(text_table)/2][1] == 'x';
		
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
	printf("\n 암호문 : ");
	for(i = 0; i<text_len/2+1; i++){ 
		txt = type_check(text_table[i][0], text_table[i][1]);
		printf("%c%c", txt[0], txt[1]);
	}
	/*
	char encrypted_table[text_len][2];
	for(i = 0; i<text_len/2+1; i++){ 
		txt = type_check(text_table[i][0], text_table[i][1]);
		encrypted_table[i][0] = txt[0];
		encrypted_table[i][1] = txt[1];
	}

	for(i = 0; i<text_len/2+1; i++){
    		printf("%c%c | ", encrypted_table[i][0],encrypted_table[i][1]);
		}*/
	/*
	char encrypted_table[text_len][2];
	
	for(i = 0; i<10; i++){
		txt = type_check(text_table[i][0], text_table[i][1]);
		printf("%c, %c | ", txt[0], txt[1]);
	}*/
	/*
	char *ch1;
	ch1 = get_point(text_table[0][0]);
	print("%d %d\n", ch1[0], ch1[1]);
    */
}
void decrypt(){
	
}

int main(){
    char* key;
    key = key_input();
    
    printf("중복 제거된 키값은 %s입니다.\n\n", key);
	printf("테이블을 생성합니다. \n");
    build_table(key);

    
    printf("\n암호문을 입력하세요\n");
    encrypt();

}
//becarefulforassassinator
