#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>


using std::vector;
using std::queue;
using std::stack;
using std::set;
using std::map;

void auto_create_graph();
void create_graph();
void add_edges(char begin,char end);
void print_all();
void deep_graph();
void visit_operate(char vch);

// 有向图表示
typedef struct _Graph {
	int vex_num;
	int edge_num;
	map<char,set<char>> vexs;
} Graph;


static Graph *graph = new Graph();

int main(void) {
	auto_create_graph();
	print_all();
	deep_graph();
}

// 手动输入数据
void create_graph() {
	
}

// 自动生成数据
void auto_create_graph() {
	char vexs[] = {'A','B','C','D','E','F','G'};
	char edges[][2] = {
		{'A','B'},
		{'B','C'},
		{'B','E'},
		{'B','F'},
		{'C','E'},
		{'D','C'},
		{'E','B'},
		{'E','D'},
		{'F','G'},
	};
	graph->vex_num = sizeof(vexs) / sizeof(vexs[0]);
	graph->edge_num = sizeof(edges) / sizeof(edges[0]);
	for (int i = 0; i < graph->edge_num; i++) {
		add_edges(edges[i][0],edges[i][1]);
	}
}


void add_edges(char begin,char end) {
	// set.insert
	set<char> m_set = graph->vexs[begin];
	m_set.insert(end);
	graph->vexs[begin] = m_set;
}

void deep_graph() {
	map<char,set<char>> m_set = graph->vexs;
	map<char,set<char>>::iterator first_vex = m_set.begin();
	queue<char> vex_q;
	set<char> visited;
	vex_q.push(first_vex->first);
	while (!vex_q.empty()) {
		char vch = vex_q.front();
		if (visited.find(vch) != visited.end()) {
			vex_q.pop();
			continue;
		}
		visited.insert(vch);
		visit_operate(vch);
		// insert in queue
		set<char> s = graph->vexs[vch];
		for (set<char>::const_iterator it = s.begin(); it != s.end(); it++) {
			vex_q.push(*it);
		}
		vex_q.pop();
	}
}

void visit_operate(char ch) {
	std::cout << "visited vex:\t" << ch << std::endl;
}


void print_all() {
	std::cout << "\n\nbefore print:" << std::endl;
	for (map<char,set<char>>::iterator it = graph->vexs.begin(); it != graph->vexs.end(); it++) {
		std::cout << it->first << std::endl;
		for (set<char>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++) {
			std::cout << "\t" << *it2 << std::endl;
		}
	}
	std::cout << "after print\n\n" << std::endl;
}


