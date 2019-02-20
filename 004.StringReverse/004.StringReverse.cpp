// 004.StringReverse.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//输入任意4个字符(如：abcd)， 并按反序输出(如：dcba)
//注:应该是做为一个算法题来搞的,但是题目给了只有4个字符的限制,所以...

#include "pch.h"
#include <iostream>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	char a[4] = { 0 };
	while (cin >> a) {
		cout << a[3] << a[2] << a[1] << a[0] << endl;
	}
}