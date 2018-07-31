#include<stdio.h>
#include<math.h>

static char init_char[64] = {
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	'0','1','2','3','4','5','6','7','8','9','+','/',
};

void encrypt_base64(char org[], int len, char result[]);

// 解密
void decrypt_base64(char org[], int len, char result[]);

int main() {
	char org[] = "1358124684"; //MTM1ODEyNDY4NA==
	int len;
	for (len = 0; org[len] != '\0'; len++);
	int num = (ceil(len / 3)) * 4;
	char result[num + 1];
	encrypt_base64(org,len,result);
	printf("org:%s\tencrypt:%s\n",org,result);
}

void encrypt_base64(char org[],int len,char result[]) {
	unsigned char ch;
	unsigned int leave_num = 0, count = 0;
	for (int i = 0; i < len; i++) {
		if (leave_num == 0) {
			ch = org[i] >> 2;
		} else {
			ch = (org[i - 1] << (8 - leave_num)) | (org[i] >> leave_num);
		}
		result[count++] = ch;
		leave_num = (8 * (i + 1)) % 6;
	}
	if (len % 3 != 0) {
		result[count++] = org[len - 1] << (8 - leave_num);
		if (len % 3 == 1) {
			result[count++] = '=';
		}
		result[count++] = '=';
	}
	result[count++] = '\0';
}


void decrypt_base64(char org[], int len, char result[]) {

}
