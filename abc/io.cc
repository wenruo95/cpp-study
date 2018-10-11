#include<iostream>
#include<fstream>
#include<string>

int main(int argc, char **args) {
	if (argc < 2) {
		std::cout << "tips:./a.out test.txt" << std::endl;
		return 0;
	}
	unsigned int len;
	for (len = 0; args[1][len] != '\0'; len++);
	std::string filename(&args[1][0], &args[1][len]);
	std::cout << "output to " << filename << std::endl;

	/*
	 * ios:app 追加
	 * ios:ate 定位到文件末尾
	 * ios.in 读取
	 * ios.out 写入
	 * ios.trunc  清空写入
	 */
	// ofstream:write 2 file
	std::ofstream outfile;
	outfile.open(filename);

	char data[100];

	std::cout << "Enter your name:";
	std::cin.getline(data, 100);
	outfile << data << std::endl;

	std::cout << "Your age:";
	std::cin >> data;
	std::cin.ignore();
	outfile << data << std::endl;

	outfile.close();

	// ifstream:read from file
	std::ifstream infile;
	infile.open(filename);

	infile >> data;
	std::cout << "name:\t" << data << std::endl;
	infile >> data;
	std::cout << "age:\t" << data << std::endl;

	infile.seekg(0);
	while(infile) {
		infile.getline(data, 100);
		if (data[0] != '\0') {
			std::cout << data << std::endl;
		}
	}
	infile.close();

	// fstream write
	std::fstream file;
	file.open(filename, std::ios::out | std::ios::in);
	file << "hello fstream test" << std::endl;
	file.seekg(0);
	while (file) {
		file.getline(data, 100);
		if (data[0] != '\0') {
			std::cout << data << std::endl;
		}
	}
	file.close();
}
