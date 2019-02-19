// 003.ProxySwichTimes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string.h>

using namespace std;
int solve(unsigned int* proxies, int nP, unsigned int* servers, int nS) {
	int max = 0, tmp = 0;
	for (int i = 0; i < nP; i++) {
		for (int j = 0; j < nS; j++) {
			if (proxies[i] != servers[j]) {
				tmp++;
			} else {
				break;
			}
		}
		max = tmp > max ? tmp : max;
		tmp = 0;
		if (max == nS) {
			return 0;
		}
	}
	if (max == 0) {//all proxies are tried.
		return -1;
	}
	return 1 + solve(proxies, nP, servers + max, nS - max);
}
int main() {
	std::ios::sync_with_stdio(false);
	int nProxies, nServers;
	while (cin >> nProxies) {
		unsigned int* proxyIPs = new unsigned int[nProxies];
		int a, b, c, d;
		char magic;
		for (int i = 0; i < nProxies; i++) {
			cin >> a >> magic >> b >> magic >> c >> magic >> d;
			proxyIPs[i] = (a << 24) + (b << 16) + (c << 8) + d;
		}
		cin >> nServers;
		unsigned int* serverIPs = new unsigned int[nServers];
		for (int i = 0; i < nServers; i++) {
			cin >> a >> magic >> b >> magic >> c >> magic >> d;
			serverIPs[i] = (a << 24) + (b << 16) + (c << 8) + d;
		}
		cout << solve(proxyIPs, nProxies, serverIPs, nServers) << endl;
		delete[] proxyIPs, serverIPs;
	}
	return 0;
}