/*
ʹ���´���������Ϊ200.

����
����Ҫ���롣
���
������Ϊ200��
��������
����Ҫ���롣
�������
200

*/
#include<iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n=0): num(n) {}
//your code starts here    
    int operator * (const Number & n) {
    	return Number(num * n.num);
	}
	operator int() {
		return num;
	}
//your code ends here	
};

int main() {
    Number n1(10), n2(20);
    Number n3;
    n3 = n1*n2;
    cout << int(n3) << endl;
    return 0;
}
