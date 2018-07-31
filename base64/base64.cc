#include<iostream>
#include<string>


static unsigned char init_char[64] = {
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	'0','1','2','3','4','5','6','7','8','9','+','/',
};

// 参考链接1:https://zh.wikipedia.org/wiki/Base64
// 链接2:http://tool.oschina.net/encrypt?type=3
// 3个字节编译成4个字符 [0,25](A-Z) [26,51](a-z) [52,61](0,9) [62,63](+,/)
// 加密
std::string encrypt_base64(const std::string str);
// 解密
std::string decrypt_base64(const std::string str);

int main() {
	std::string str("1358124684"); //MTM1ODEyNDY4NA==
	std::cout << "str:" << str << "\tencrypt:" << encrypt_base64(str) << std::endl;
}

std::string encrypt_base64(const std::string str) {
	int num = (str.size() / 3) * 4;
	std::string result;
	unsigned char ch;
	unsigned int leave_num = 0;
	for (int i = 0; i < str.size(); i++) {
		if (leave_num == 0) {
			ch = str[i] >> 2;
		} else {
			ch = (str[i - 1] << (8 - leave_num)) | (str[i] >> leave_num);
		}
		result[result.size()] = ch;
		leave_num = (8 * (i + 1)) % 6;
	}
	if (str.size() % 3 != 0) {
		result[result.size()] = str[str.size() - 1] << (8 - leave_num);
		if (str.size() % 3 == 1) {
			result[result.size()] = '=';
		}
		result[result.size()] = '=';
	}
	result[result.size()] = '\0';
	return result;
}


std::string decrypt_base64(const std::string str) {

}
