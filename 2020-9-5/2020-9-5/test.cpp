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
	void Helper(string str, int begin)//begin指向当前做排列的字符串的第一个
	{
		//递归条件
		if (begin == str.size())//说明以某个字符为首元素的一个排列生成了
		{
			result.push_back(str);
		}
		else{
			for (int i = begin; str[i] != '\0'; ++i)//用来进行从begin到最后一个元素的排列
			{
				//连续两个元素相同的情况，不用处理，直接下次循环
				if (i != begin && str[i] == str[begin])
					continue;
				//第一步，
				swap(str[i], str[begin]);
				Helper(str, begin + 1);
				swap(str[i], str[begin]);//与后面的进行交换作为首元素
			}
		}
	}
};
int main(){
	return 0;
}