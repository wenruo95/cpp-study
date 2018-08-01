#include<stdio.h>
#include<math.h>

static unsigned char init_char[64] = {
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	'0','1','2','3','4','5','6','7','8','9','+','/',
};

static unsigned int left_char[4] = {0,3,0,15};
static unsigned int right_char[4] = {0,240,0,192};

// 加密
void encrypt_base64(char org[], int len, char result[]);

// 解密
void decrypt_base64(char org[], int len, char result[]);

int main() {
	char org[] = "Man"; //MTM1ODEyNDY4NA==
	int len;
	for (len = 0; org[len] != '\0'; len++);
	int num = (ceil(len / 3.0)) * 4;
	char result[num + 1];
	encrypt_base64(org,len,result);
	printf("org:%s\tlen:%d\tencrypt:%s\n",org,num,result);
	return 0;
}

void encrypt_base64(char org[],int len,char result[]) {
	unsigned int chindex,left,right;
	unsigned int leave_num = 0, count = 0;
	for (int i = 0; i < len; i++) {
		if (leave_num == 0) {
			chindex = org[i] >> 2;
		} else {
			left = (org[i - 1] & left_char[leave_num - 1]) << (6 - leave_num);
			right = (org[i] & right_char[leave_num - 1]) >> (8 - (6 - leave_num));
			printf("left:%d\tright:%d\tleave_num:%d,sd=%d\n",left,right,leave_num,org[i] & 48);
			chindex = left | right;
		}
		result[count++] = init_char[chindex];
		if ((i + 1) % 3 == 0) {
			chindex = org[i] & 63;
			result[count++] = init_char[chindex];
		}
		leave_num = (8 * (i + 1)) % 6;
	}
	if (len % 3 != 0) {
		chindex = org[len - 1] << (8 - leave_num);
		result[count++] = init_char[(int)chindex];
		if (len % 3 == 1) {
			result[count++] = '=';
		}
		result[count++] = '=';
	}
	printf("count:%d\n",count);
	result[count++] = '\0';
}


void decrypt_base64(char org[], int len, char result[]) {

}
