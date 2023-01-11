/*
����Ⱥ�����������Ϣ��������ͷ��ࡣ

����
��һ��������t,����һ��t������. t < 20
��ÿ�����ݣ�
��һ��������n,��ʾ����һ����n�С� 0 < n < 100
�����ÿ�д���һ���ˡ�ÿ����һ����ĸ��ͷ������������������Ȼ�����һ���������������䡣��ĸֻ���� 'A����B' ��������Χ0��100�����ݱ�֤���䶼����ͬ��
���
��ÿ���������ݣ�����Щ�˰������С���������ÿ��������������������䡣ÿ�����ݵ�ĩβ��һ�� "****"
��������
2
4
A 3
B 4
A 5
B 6
3
A 4
A 3
A 2
�������
A 3
B 4
A 5
B 6
****
A 2
A 3
A 4
****

*/
#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
//your code starts here
struct A {
	int age;
	A(int a):age(a) { }
	virtual void Print() {
		cout << "A " << age << endl;
	}
};
struct B:public A
{
	B(int a):A(a) { }
	virtual void Print() {
		cout << "B " << age << endl;
	}
	
}; 
void Print( A * p)
{
	p->Print();
}
typedef A * APTR; 
struct Comp
{
	bool operator ()( const APTR  & p1, const APTR  & p2 ) {
		return p1->age < p2->age;
	}
};
//your code ends here

int main()
{

	int t;
	cin >> t;
	set<A*,Comp> ct;
	while( t -- ) {
		int n;
		cin >> n;
		ct.clear();
		for( int i = 0;i < n; ++i)	{
			char c; int k;
			cin >> c >> k;
			
			if( c == 'A')
				ct.insert(new A(k));
			else
				ct.insert(new B(k));
		}	
		for_each(ct.begin(),ct.end(),Print);
		cout << "****" << endl;
	}
}
