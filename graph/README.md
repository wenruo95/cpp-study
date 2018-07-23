
有向图表示：（无向图实质上是双向图，如A-B，节点B要增加对A方向的路径）

共7个顶点：ABCDEFG

共9条边：AB、BC、BE、BF、CE、DC、EB、ED、FG

表示如下(实质上就是用一个数组来表示有向图，每个数组元素中存储一个链表)：


0	A : 1 -> NULL

1	B : 2 -> 4 -> 5 -> NULL

2	C : 4 -> NULL

3	D : 2 -> NULL

4	E : 1 -> 3 -> NULL

5	F : 6 -> NULL

6	G : NULL


每个节点后是一个链表：

	typedef struct _Link {
		char ch; 	// 元素名，如这个链表存储节点A的信息
		int size; 	// 元素个数
		Node *head; // 指向第一个元素
		Node *tail; // 指向最后一个元素
	} Link,*pLink;

链表后的元素表示如下

	typedef struct _Node {
		int val;	// 数据，这里表示节点A的指向，A->B那么val=1指向C那么val=2
		_Node *next; // 指向下一个元素
		_Node *prev; // 这个可以不要 
	}Node;


那么整个有向图可以表示为

Link vexs[vex_num];// vex_num表示节点个数
也可以使用结构体表示更多数据如：

	typedef struct _Graph {
		int vex_num; // 节点数
		int edge_num; // 边数
		Link vexs[vex_num]; // 有向图数据
	} Graph


