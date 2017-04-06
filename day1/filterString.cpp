/*
* @Author: zwyos
* @E-mail: so2os@mail.ustc.edu.cn
* @Date:   2017-04-05 18:19:59
* @Version: v1.0
* @Quesetion:  字符串筛选问题，把有重复的字符过滤掉
* @Summary:  g_flag[26]这个思想很好，用于检查重复元素，要搞清楚sizeof()和strlen()用法的区别，
* 这个http://blog.csdn.net/21aspnet/article/details/1539951写的很清楚。
* @Last Modified by:   zwyos
* @Last Modified time: 2017-04-06 16:58:14
*/

#include <iostream>
#include <cassert>
#include <string.h>


using namespace std;
bool g_flag[26];
void stringFilter(const char *pInputStr,long lInputLen,char *pOutputStr);

int main()
{
	
	char input[] = "abacacde";
	char *output = new char[strlen(input) +1];
	stringFilter(input,sizeof(input),output);
	cout << output << endl;
	delete output;
	return 0;
}

void stringFilter(const char *pInputStr,long lInputLen,char *pOutputStr)
{
	assert(pInputStr != NULL);
	int i = 0;
	if(pInputStr == NULL || lInputLen <= 1)
		return;
	const char *p = pInputStr;
	while(p != '\0') 
	{
		if(g_flag[*p - 'a'])
			p++;
		else
		{
			pOutputStr[i++] = *p;
			g_flag[*p - 'a'] = 1;
			p++;
		}
	    
	}
	pOutputStr[i] = '\0';

}