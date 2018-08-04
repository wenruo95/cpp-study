#ifndef _H_BASE64

#define _H_BASE64

#include<math.h>

static unsigned char init_char[64] = {
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	'0','1','2','3','4','5','6','7','8','9','+','/',
};

// 加密过程中剩余字节数只能为2或者4
static unsigned int encleft[4] = {0,3,0,15};
static unsigned int encright[4] = {0,240,0,192};

// 加密
void encrypt_base64(char org[], int len, char result[]);

// 解密
void decrypt_base64(char org[], int len, char result[]);



#endif
