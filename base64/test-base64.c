#include<stdio.h>

#include "base64.h"


int main() {
	int len;

	char org[] = "1358124684"; //MTM1ODEyNDY4NA==
	for (len = 0; org[len] != '\0'; len++);
	int num = (ceil(len / 3.0)) * 4;
	char result1[num + 1];
	encrypt_base64(org,len, result1);
	printf("org:%s\tlen:%d\tencrypt:%s\n",org, num, result1);

	char dec[] = "MTM1ODEyNDY4NA==";
	for (len = 0; dec[len] != '\0'; len++);
	num = len / 4;
	char result2[num + 1];
	decrypt_base64(dec, len, result2);
	printf("org:%s\tlen:%d\tdecrypt:%s\n",dec, len, result2);
	return 0;
}

