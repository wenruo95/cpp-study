// 垃圾代码,毁我人生
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int GAME_NUM = 2; // 游戏场数 
const int SCORE[3] = {2,1,0}; // 以甲为基准,赢,输平
int game_num_record = 1; // 现在进行到第几场
int game_record[GAME_NUM]; // 0为甲胜利 1为乙胜利 2为平局
int num = 0; // 现在第几场游戏
int num_key = 3; // 本场游戏结果
int jia_score = 0; // 甲方执黑先手
int yi_score = 0; // 乙方执白后手
int coordinate_x = 0;
int coordinate_y = 0;
bool is_fighting = true;
int xiazi_side = 0;// 0为黑方，1为白方
// 棋盘使用十字链表（稀疏矩阵）显示效果更佳，但是时间不够
int coordinate[15][15]; // 0为初始状态 1为黑方 2为白方 3为黑房最后一个 4为白方最后一个
int step = 0;// 步数

void setscore(int key);
void print_end();
bool jiablack();
void first_print();
void data_send2coordinate();
void setcoordinate();
void begin();
bool game_isend();
int isfiveshortest();
void print_coordinate();
bool handle_input();
bool isvalidate();

int main(){
	// 选择先后
	while(++num <= 2) {
		step = 0;
		num_key = 3;
		first_print();	
		setcoordinate();
		while(is_fighting){
			print_coordinate();
			// 如果数据格式或者位置不合法，重复输入
			while(!handle_input()|| !isvalidate()){
				cout << "不符合格式要求,请重下" << endl;
			}
			// 将数据输入棋盘
			data_send2coordinate();
			// 判断游戏结果
			if (game_isend() == true) {
				setscore(num_key);
				break;
			}
			// 换人
			xiazi_side = (xiazi_side + 1) % 2; 
			step++;
		}
	}
	return 0;
}
// 对局提示打印
void first_print(){
	cout<<"\t*游戏规则*\t"<<endl;
	cout<<"游戏2局积分制:赢了加两分，平局加一分，输了加0分，积分高者获胜\n"<<endl;
	cout<<"第一把甲方执黑先手，下一把乙方执黑先手,一次轮换"<<endl;
	if (num == 1) {
		// 第一局开始时欢迎语
	} else if (num > 1){
		// 第num局之前的游戏结果
	}
}

// 打印棋盘
void print_coordinate(){
	for (int i = 14; i >= 0; i--){
		cout<<i+1<<"\t";
		for (int j = 0; j < 15;j++){
			cout<<coordinate[j][i]<<"\t";
		}
		cout<<endl;
	}
	cout<<"0\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\tK\tL\tM\tN\tO\t\n"<<endl;
	cout<<"现在棋盘共有"<<step<<"个子\n"<<endl;
}

// 设置比分
void setscore(int key) {
	jia_score += SCORE[key];
	game_record[game_num_record++] = key;
	if (key == 0) {
		yi_score += 0;
	} else if (key == 1){
		yi_score += 1;
	} else {
		yi_score += 2;
	}
	if (game_num_record <= GAME_NUM) {
		begin();
	} else {
		print_end();
	}
}

void begin(){

}

// 打印结果
void print_end(){
	cout<<"比分甲:乙"<<jia_score<<":"<<yi_score<<endl;
	int num = 0;
	while(num++ < GAME_NUM){
		if (game_record[num] == 2) {
		} else {
			string side = game_record[num] == 1 ? "甲":"乙";
			cout<<"第一局"<<side<<"方胜利"<<endl;
		}
	}
}

// 甲方执黑先手 单数把甲先手
bool jiablack(){
	if (num % 2 == 0){
		return true;
	}
	return false;
}

bool handle_input(){
	string side = (xiazi_side == 0) ? "黑方" : "白方";
	cout<<side<<"请下子(下子格式如:B12(字母一定要大写)):";
	char args1;
	int args2;
	cin>>args1>>args2;
	int args3 = int(args1) - (int)'A';
	args2 = args2 - 1;
	if ( args3 >= 15 || args3 < 0 || args2 >= 15 || args2 < 0) {
		cout << "不合要求:" << "\t" << args2 << "\t" << args3 << endl;
		return false;
	}
	coordinate_x = args3;
	coordinate_y = args2;
	cout << coordinate_x << "\t" << coordinate_y << "\t" << endl;
	return true;
}

void setcoordinate(){
	for (int i = 0; i < 15;i++){
		for (int j = 0; j < 15;j++){
			coordinate[i][j] = 0;
		}
	}
}
bool isvalidate(){
	if (coordinate[coordinate_x][coordinate_y] != 0){
		cout << "该子不合要求，已被占据" << endl;
		return false;
	}
	return true;
}

void data_send2coordinate(){
	int x = coordinate_x;
	int y = coordinate_y;
	if (x >= 0 && x < 15 && y >= 0 && y < 15){
		// 将之前下的棋子设置为1、2 
		int changestatus = 0;
		for (int i = 0; i < 15;i++){
			for (int j = 0; j < 15;j++){
				if (coordinate[i][j] == xiazi_side + 3){
					coordinate[i][j] = xiazi_side + 1;
					changestatus = 1;
					break;
				}
			}
			if (changestatus == 1){
				break;
			}
		}
		// 设置x、y
		coordinate[x][y] = xiazi_side + 3;
	}
}

bool game_isend(){
	if (step < 9) {
		return false;
	}
	// no 3-3 4-4 长连
	if (!isfiveshortest()){
		return false;
	}
	// 棋子填满 平局
	if (step = 15*15) {
		return false;
	}
	return true;
}

// 0为甲胜利 1为乙胜利 2为平局 3为暂无胜负 
int isfiveshortest(){
	int collect[step/2 + 1][2];
	int collect_x[15];
	int collect_y[15];
	int key = 0;
	for (int i = 0;i < 15; i++){
		for (int j = 0; j < 15; j++){
			if (coordinate[i][j] == xiazi_side + 1 || coordinate[i][j] == xiazi_side + 2){
				collect[key][0] = i;
				collect[key++][1] = j;
			}
		}
	}
	int min_x = collect[0][0];
	int max_x = collect[0][0];
	int min_y = collect[0][1];
	int max_y = collect[0][1];
	for (int i = 1; i < step/2 + 1;i++){
		if (min_x > collect[i][0]) {
			min_x = collect[i][0];
		}
		if (max_x < collect[i][0]) {
			max_x = collect[i][0];
		}
		if (min_y > collect[i][1]) {
			min_y = collect[i][1];
		}
		if (max_y < collect[i][1]) {
			max_y = collect[i][1];
		}
	}
	if (max_x - min_x < 5 and max_y - min_y < 5) {
		return false;
	}
	int lian = 0;
	int temp_x = 0;
	int temp_y = 0;
	// 横排成五子棋 遍历y
	for (int y = min_y; y <= max_y; y++){
		for (int x = min_x; x <= max_x; x++){
			for (int i = 0; i < step/2 + 1; i++){
				if(collect[i][1] == y){
					if (temp_x ==5){
						if (collect[i][0] == x){
							// 长连 输
							if(xiazi_side == 0 && num % 2 == 1){
								num_key = 1;
								return true;
							} else {
								num_key = 0;
								return true;
							}
						} else {
							if(xiazi_side == 0 && num % 2 == 1){
								num_key = 0;
								return true;
							} else {
								num_key = 1;
								return true;
							}
						}
					}
					if (collect[i][0] == x){
						temp_x++;
					} else {
						temp_x = 0;
					}
				}
			}
		}
	}
	// 竖排成五子棋 遍历x
	for (int x = min_x; x <= max_x; x++){
		for (int y = min_y; y <= max_y; y++){
			// 在collect中寻找所有 x,min_y坐标的 
			for (int i = 0 ; i < step/2 + 1; i++){
				if (collect[i][1] == x){
					collect_x[temp_y++] = y;
				}
			}
			if (temp_y < 5){
				return false;
			} else{
				int temp_y_num = 0;
				for (int i = 0;i< temp_y; i++){
					if (temp_y_num == 5){
						if (collect[i][1] == x){
							// 长连 输
							if(xiazi_side == 0 && num % 2 == 1){
								num_key = 1;
								return true;
							} else {
								num_key = 0;
								return true;
							}
						} else {
							if(xiazi_side == 0 && num % 2 == 1){
								num_key = 0;
								return true;
							} else {
								num_key = 1;
								return true;
							}
						}
					}
					if (collect[i][1] == y){
						temp_y_num++;
					} else {
						temp_y_num = 0;
					}
				}
			}
		}
	}
	// 斜成五子棋 遍历x
	for (int x = min_x; x <= max_x; x++){
		int find_y = 0;
		// 寻找x,y坐标
		for (int i = 0; i < step/2 + 1; i++){
			if (collect[i][0] == x){
				find_y = i;
				break;
			}
		}
		int temp_xy_num = 0;
		for (int i = x; i < step/2 + 1; i++){
			if (temp_xy_num == 5){
				if (collect[i][1] == x){
					// 长连 输
					if(xiazi_side == 0 && num % 2 == 1){
						num_key = 1;
						return true;
					} else {
						num_key = 0;
						return true;
					}
				} else {
					if(xiazi_side == 0 && num % 2 == 1){
						num_key = 0;
						return true;
					} else {
						num_key = 1;
						return true;
					}
				}
			}
			if (collect[i+1][find_y+1] % 2 == xiazi_side){
				temp_xy_num = temp_xy_num + 1;
			} else {
				temp_xy_num = 0;
			} 
		}
	}
}
