/*
��д���룬ʹ������Ϊ

2

2

8

10

����
����Ҫ���롣
���
ʹ������Ϊ
2
2
8
10
��������
����Ҫ���롣
�������
2
2
8
10

*/
#include <iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n): num(n) {
    }
//your code starts here    
	int & value() { return num; }
	void operator + (const Number & n) {
		num += n.num;
	}
	
//your code ends here
};
int main() {
    Number a(2);
    Number b = a;
    cout << a.value() << endl;
    cout << b.value() << endl;
    a.value() = 8;
    cout << a.value() << endl;
    a+b;
    cout << a.value() << endl;
    return 0;
}
