/*
����
����һ�����������ɵ�����a[0], a[1], a[2], ... , a[n-1], �������ǵĶ����Ƶ�3λ֮�͡�

����
����a,��0��ʾ���������
���
һ������ , �����������Ԫ�صĶ����Ƶ�3λ֮�͡�
��������
1 3 9 7 3 6 20 15 18 17 4 8 18 0 
�������
41

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// �ڴ˴�������Ĵ���
//your code starts here

class CMy_add
{
	public:
		int & init;
		CMy_add(int & v):init(v) { }
		int operator()( int n) {
			init += (n & 0x07);
		}
};

//your code ends here
int main(int argc, char* argv[]) {
	int  v, my_sum=0;
	vector<int> vec;		
	cin>>v;
	while ( v ) {
		vec.push_back(v);
		cin>>v;
	}
	for_each(vec.begin(), vec.end(), CMy_add(my_sum));
	cout<<my_sum<<endl;	
	return 0;
}
