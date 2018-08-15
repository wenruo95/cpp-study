#include<iostream>
#include<string>

static const unsigned int redis_port = 6379;
static const std::string redis_pwd = "redisdbpwd";
static const unsigned int port_min = 0;
static const unsigned int port_max = 65535;
static const unsigned int pwd_minlen = 1; // 0表示没有设置密码
static const unsigned int pwd_maxlen = 25;
static const unsigned char pwd_char[] = {
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	'0','1','2','3','4','5','6','7','8','9','+','-','_','=','!','@','#','$','%','^','&','|','>','<','*','/'
};

unsigned int exhaust_port();
unsigned int isright_port(unsigned int port);

std::string exhaust_pwd();
unsigned int _exhaust_pwd(unsigned int size, std::string pwd);
unsigned int isright_pwd(std::string pwd);

int main(void) {
	unsigned int port = exhaust_port();
	std::string pwd = exhaust_pwd();
	std::cout << "port:\t" << port << "\tpassword:\t" << pwd << std::endl;
}


unsigned int exhaust_port() {
	for (int port = port_min; port <= port_max; port++) {
		if (isright_port(port)) {
			return port;
		}
	}
	return port_min;
}

unsigned int isright_port(unsigned port) {
	if (port == redis_port) {
		return 1;
	}
	return 0;
}

std::string exhaust_pwd() {
	std::string pwd("");
	for (int size = pwd_minlen; size <= pwd_maxlen; size++) {
		if (_exhaust_pwd(size, pwd) && pwd.size() > 0) {
			break;
		}
	}
	return pwd;
}

unsigned int _exhaust_pwd(unsigned int size, std::string pwd) {
	int ch_num = sizeof(pwd_char) / sizeof(pwd_char[0]);
	for (int i = 0; i < ch_num; i++) {
		std::string password(pwd_char[i], ch_num);
		if (isright_pwd(password)) {
			pwd = password;
			return 1;
		}
	}
	return 0;
}

unsigned int isright_pwd(std::string pwd) {
	if (pwd.compare(redis_pwd) == 0) {
		return 1;
	}
	return 0;
}
