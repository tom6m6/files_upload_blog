/*
ͨ�����ʹ�ó�������Ľ�����������Ҫ��

����
����Ҫ���롣
���
ʹ�ó�����������ǣ�
2
3
B::destructor
A::destructor
3
4
B::destructor
A::destructor
3
B::destructor
A::destructor
A::destructor
A::destructor
��������
����Ҫ���롣
�������
2
3
B::destructor
A::destructor
3
4
B::destructor
A::destructor
3
B::destructor
A::destructor
A::destructor
A::destructor
��ʾ
int A::count = 0; ���������������¼һ���ж��ٸ���A����A��������Ķ���ġ�

*/
#include <iostream>
#include <map>
using namespace std;
//your code starts here
struct A {
	static int count;
	int v;
	A(int v_= 0):v(v_) { ++count;}
	virtual ~A() { -- count; cout << "A::destructor" << endl;}
	A(const A & a):v(a.v) {
		++count;
	}
};
struct B:public A
{
	
	//�������ȱʡ���ƹ��캯������û���ĸ��ƹ��캯��
	~B() { cout << "B::destructor" << endl;}
	B(int v):A(v) { }
		
};
//your code ends here
int A::count = 0;
void func(B b) {  }
int main()
{
	A a1(5),a2;
	cout << A::count << endl;
	B b1(4);
	cout << A::count << endl;
	func(b1);
	cout << A::count << endl;
	A * pa = new B(4);
	cout << A::count << endl;
	delete pa;
	cout << A::count << endl;
	return 0;
}
