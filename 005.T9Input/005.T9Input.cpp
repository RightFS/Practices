// 005.T9Input.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//按照手机键盘输入字母的方式，计算所花费的时间 如：a,b,c都在“1”键上，输入a只需要按一次，输入c需要连续按三次。 
//如果连续两个字符不在同一个按键上，则可直接按，如：ad需要按两下，kz需要按6下 如果连续两字符在同一个按键上，
//则两个按键之间需要等一段时间，如ac，在按了a之后，需要等一会儿才能按c。 现在假设每按一次需要花费一个时间段，
//等待时间需要花费两个时间段。 现在给出一串字符，需要计算出它所需要花费的时间。


#include "pch.h"
#include<iostream>
using namespace std;
//1   abc def
//ghi jkl mno
//pqrs tuv wxyz
int main() {
	std::ios::sync_with_stdio(false);
	unsigned char alphabet[] = { 1,2,3,   1,2,3,
							  1,2,3,   1,2,3, 1,2,3,
							  1,2,3,4, 1,2,3, 1,2,3,4 };
	unsigned char key[] = { 2,2,2, 3,3,3,
						4,4,4, 5,5,5 ,6,6,6,
						7,7,7,7 ,8,8,8 ,9,9,9,9 };
	char str[101] = { 0 };
	while (cin >> str) {
		int time = 0;
		time += alphabet[str[0] - 'a'];
		for (int i = 1; i < 101 && str[i] != 0; i++) {
			time += alphabet[str[i] - 'a'];
			if (key[str[i] - 'a'] == key[str[i - 1] - 'a']) {
				time += 2;
			}
		}
		cout << time << endl;
	}
}