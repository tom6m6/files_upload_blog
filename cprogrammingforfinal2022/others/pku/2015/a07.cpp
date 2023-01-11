/*
�밴��Ҫ���������ַ�����������

����
��һ����������T����ʾ�������ݵ�����
ÿ������������빲���У�
��һ����������N����ʾ�ַ�������
�ڶ�����N���ַ���, �ַ������ÿո����
���
����ÿ��������ݣ������һ�У�
Case: n
��Ե�һ�����ݾ����Case: 1
�ڶ��а����ַ������ȴ�С��������֮�����N���ַ������ַ���֮���Կո�������������ַ���������ͬ�������
�����а����ַ������ַ�ASCII�����С��������֮�����N���ַ������ַ���֮���Կո�������������ַ�������ĸ��ͬ�������
��������
2
4
a bnss ds tsdfasg
5
aaa bbbb ccccd sa q
�������
Case: 1
a ds bnss tsdfasg
a bnss ds tsdfasg 
Case: 2
q sa aaa bbbb ccccd
aaa bbbb ccccd q sa 


*/
#include <iostream>
#include <string>
#include <list>
using namespace std;

class A{
private:
	string name;
public:
	A(string n) :name(n){}
	friend bool operator < (const class A& a1, const class A &a2);
	friend bool operator == (const class A &a1, const class A &a2){
		if (a1.name.size() == a2.name.size())
			return true;
		else
			return false;
	}
	friend ostream & operator << (ostream &o, const A &a){
		o << a.name;
		return o;
	}
	string get_name() const{
		return name;
	}
	int get_size() const{
		return name.size();
	}
};
//your code starts here
template <class T>
struct MyLarge
{
	bool operator()( const T & a1,const T & a2) 
	{
		return a1.get_name().substr(0,1) < a2.get_name().substr(0,1);
	}
};
struct Print
{
	void operator()(const A & a) {
		cout << a.get_name() << " ";
	}
};
bool operator < (const class A& a1, const class A &a2)
{
	return a1.get_size() < a2.get_size();
}
template <class T,class Pred>
void Show(T s,T e,Pred op)
{
	for(;s!= e; ++s)
		op(*s);
}
 
//your code ends here

int main(int argc, char* argv[])
{
	list<A> lst;
	int ncase, n, i = 1;
	string s;
	cin >> ncase;
	while (ncase--){
		cout << "Case: "<<i++ << endl;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> s;
			lst.push_back(A(s));
		}
		lst.sort();
		Show(lst.begin(), lst.end(), Print());

		cout << endl;
		lst.sort(MyLarge<A>());
		Show(lst.begin(), lst.end(), Print());
		cout << endl;
		lst.clear();

	}
	return 0;
}
