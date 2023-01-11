/*
����
�������� n ( 0 <=n<= 2^30) , �Լ�����i,j(0 <= i,j <31,i < j-1), �������k(��ʮ������������ )��k�ĵ�iλ��n��ͬ����jλ��n��ͬ��i,j֮���λ��1, ����λ����0�������ᵽ�����е�λ��ָ�Ķ��Ƕ�����λ�����ұ����0λ��

����
��һ�������� t����ʾ����������
ÿ������������һ�У��������� n,i��j��
���
��ÿ���������ݣ���ʮ��������������
��������
2
23 3 5 
7 0 2
�������
30
3
*/
#include <iostream>
#include <string>
#include <list>
using namespace std;

inline void SetBit(int & n,int i,int v)
{
	if( v )  
		n |= (1 << i);
	else
		n &= ~(1 << i); 
} 
inline int GetBit(int n, int i)
{
	return (n >> i) & 1;
}
int main()
{
	int n,i,j;
	int t;
	cin >> t;
	while( t --) {
		cin >> n >> i >> j;
		int tmp = (0xffffffff << i) & (0xffffffff >> (31-j));
		SetBit(tmp,i,GetBit(n,i));
		if( GetBit(n,j) ) 
			SetBit(tmp,j,0);
		else
			SetBit(tmp,j,1);
		cout << hex << tmp << endl;
	}
	return 0;
}
