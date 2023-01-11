/*
������գ�ʹ������ĳ���,�����

(Tom,80),(Tom,70),(Jone,90),(Jack,70),(Alice,100),

(Tom,78),(Tom,78),(Jone,90),(Jack,70),(Alice,100),

(70,Jack),(70,Tom),(80,Tom),(90,Jone),(100,Alice),

(70,Error),(70,Error),(80,Tom),(90,Jone),(100,Alice),

******

Ȼ���ٸ����������ݰ�Ҫ������������

����
�������ݵ�ÿһ�У���ʽΪ����֮һ��

A name score
Q name score

name�Ǹ��������ո���ַ���������С�� 20
score�Ǹ�����������int��ʾ

A name score ��ʾ�����ݿ�������һ������Ϊname��ѧ���������Ϊscore����ʼʱ���ݿ���һ��ѧ��Ҳû�С�
Q name ��ʾ�����ݿ��в�ѯ����Ϊname��ѧ���ķ���


���ݱ�֤ѧ����������
������������200,000�С�
���
����ÿ����ѯ�����ѧ���ķ���������鲻��������� "Not Found"
��������
A Tom1 30
A Tom2 40
Q Tom3 
A Tom4 89
Q Tom1
Q Tom2
�������
(Tom,80),(Tom,70),(Jone,90),(Jack,70),(Alice,100),
(Tom,78),(Tom,78),(Jone,90),(Jack,70),(Alice,100),
(70,Jack),(70,Tom),(80,Tom),(90,Jone),(100,Alice),
(70,Error),(70,Error),(80,Tom),(90,Jone),(100,Alice),
******
Not Found
30
40
��ʾ
1) ��дģ���ʱ������������ ��>�����Ҫ�ÿո�ֿ������ⱻ������������ ">>"�������VS�����޴����⣬����Dev C++�ͷ������ϵı��뻷������������⡣
���� vector<vector<int>> �п��ܳ�����Ҫ�ĳ� vector<vector<int> >

2) ��ģ����д������ʱ�������ǰ����� typename�ؼ��֣�������ܻ�������VS�����޴����⣬����Dev C++�ͷ������ϵı��뻷������������⡣

*/
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
//your code starts here
template<class Key,class T,class Pred = greater<Key> >
struct MyMultimap:public multimap<Key,T,Pred>
{
	void Set(Key k,T v) {
		typename multimap<Key,T,Pred>::iterator s = multimap<Key,T,Pred>::lower_bound(k);
		typename multimap<Key,T,Pred>::iterator e = multimap<Key,T,Pred>::upper_bound(k);
		for(; s != e; ++s)
			s->second = v;
	}
};

template <class Key,class T>
ostream & operator <<(ostream & o,const pair<Key,T> & p)
{
	cout << "(" << p.first << "," << p.second << ")";
	return o;
}
//your code ends here
struct Student 
{
	string name;
	int score;
};
template <class T>
void Print(T first,T last) {
	for(;first!= last; ++ first)
		cout << * first << ",";
	cout << endl;
}


int main()
{
	
	Student s[] = { {"Tom",80},{"Jack",70},
					{"Jone",90},{"Tom",70},{"Alice",100} };
	
	MyMultimap<string,int> mp;
	for(int i = 0; i<5; ++ i)
		mp.insert(make_pair(s[i].name,s[i].score));
	Print(mp.begin(),mp.end()); //�������Ӵ�С���

	mp.Set("Tom",78); //��������Ϊ"Tom"��ѧ���ĳɼ�������Ϊ78
	Print(mp.begin(),mp.end());
	
	
	
	MyMultimap<int,string,less<int> > mp2;
	for(int i = 0; i<5; ++ i) 
		mp2.insert(make_pair(s[i].score,s[i].name));
	
	Print(mp2.begin(),mp2.end()); //���ɼ���С�������
	mp2.Set(70,"Error");          //�����гɼ�Ϊ70��ѧ�������ֶ���Ϊ"Error"
	Print(mp2.begin(),mp2.end());
	cout << "******" << endl;
	
	mp.clear();
	
	string name;
	string cmd;
	int score;		
	while(cin >> cmd ) {
		if( cmd == "A") {
			cin >> name >> score;
			if(mp.find(name) != mp.end() ) {
				cout << "erroe" << endl;
			}
			mp.insert(make_pair(name,score));
		}
		else if(cmd == "Q") {
			cin >> name;
			MyMultimap<string,int>::iterator p = mp.find(name);
			if( p!= mp.end()) {
				cout << p->second << endl;
			}
			else {
				cout << "Not Found" << endl; 
			}		
		}
	}
	return 0;
}