#include<iostream>
#include<vector>
using namespace std;
class Solution {
	vector<string> result;
public:
	vector<string> Permutation(string str) {
		if (str.empty())
			return result;
		Helper(str, 0);
		sort(result.begin(), result.end());
		return result;
	}
	void Helper(string str, int begin)//beginָ��ǰ�����е��ַ����ĵ�һ��
	{
		//�ݹ�����
		if (begin == str.size())//˵����ĳ���ַ�Ϊ��Ԫ�ص�һ������������
		{
			result.push_back(str);
		}
		else{
			for (int i = begin; str[i] != '\0'; ++i)//�������д�begin�����һ��Ԫ�ص�����
			{
				//��������Ԫ����ͬ����������ô���ֱ���´�ѭ��
				if (i != begin && str[i] == str[begin])
					continue;
				//��һ����
				swap(str[i], str[begin]);
				Helper(str, begin + 1);
				swap(str[i], str[begin]);//�����Ľ��н�����Ϊ��Ԫ��
			}
		}
	}
};
int main(){
	return 0;
}