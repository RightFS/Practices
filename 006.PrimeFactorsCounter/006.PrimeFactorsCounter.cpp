// 006.PrimeFactorsCounter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//求正整数N(N>1)的质因数的个数。 相同的质因数需要重复计算。如120=2*2*2*3*5，共有5个质因数。

#include "pch.h"
#include<iostream>
#include<cmath>
#include<set>
using namespace std;
set<int> primes;
bool isPrime(int num) {
	if (primes.count(num) > 0) {
		return true;
	}
	if (num <= 3) {
		if (num > 1)
			primes.insert(num);
		return true;
	}
	// 不在6的倍数两侧的一定不是质数
	if (num % 6 != 1 && num % 6 != 5) {
		return false;
	}
	int squareRoot = static_cast<int>(sqrt(num));
	for (int i = 5; i <= squareRoot; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) {
			return false;
		}
	}
	primes.insert(num);
	return true;
}
int count(int n) {
	if (isPrime(n)) {
		return 1;
	}
	int squareRoot = static_cast<int>(sqrt(n));
	for (int i = 2; i <= squareRoot; i++) {
		if (n%i == 0) {
			return  1+ count(n / i);
			break;
		}
	}
	return 1;
}
int main() {
	std::ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		cout << count(n) << endl;
	}
}
int main1() {
	//这题的关键：
	//1、是sqrt,可以极大减少复杂度，若是到方根N仍大于1，则必还有且只还有1个质因数
	//2、每次瞬间整除都可帮助减少遍历范围
	long M = 100;
	while (cin >> M) {
		long count = 0;
		for (long j = 2; j <= sqrt(M); j++) {
			while (M%j == 0) {
				M = M / j;
				count++;
			}
		}
		if (M > 1)count++;
		cout << count << endl;
	}
	return 0;
}