#include<iostream>
#include<string>

// 参考链接1:https://zh.wikipedia.org/wiki/Base64
// 链接2:http://tool.oschina.net/encrypt?type=3
// 3个字节编译成4个字符 [0,25](A-Z) [26,51](a-z) [52,61](0,9) [62,63](+,/)
// 加密
std::string encrypt_base64(const std::string str);
// 解密
std::string decrypt_base64(const std::string str);

int main() {
	std::string str("1358124684"); //MTM1ODEyNDY4NA==
}

std::string encrypt_base64(const std::string str) {
	
}


std::string decrypt_base64(const std::string str) {

}
