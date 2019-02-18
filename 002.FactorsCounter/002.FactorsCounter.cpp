// 002.FactorsCounter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//题目描述
//输入n个整数, 依次输出每个数的约数的个数
//输入描述 :
//输入的第一行为N，即数组的个数(N <= 1000)
//接下来的1行包括N个整数，其中每个数的范围为(1 <= Num <= 1000000000)
//当N = 0时输入结束。
//输出描述 :
//可能有多组输入数据，对于每组输入数据，
//输出N行，其中每一行对应上面的一个数的约数的个数。

//Tips:本题关键在于循环退出条件

#include "pch.h"
#include <iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int a;
		int num = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			int j;
			for (j = 1; j*j < a; j++) {
				if (a % j == 0) {
					num += 2;
				}
			}
			if (j*j == a) {
				num++;
			}
			cout << num << endl;
			num = 0;
		}
	}
}
