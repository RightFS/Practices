// ScoreSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//考稳定排序和升降序

#include "pch.h"
#include <iostream>
using namespace std;
typedef struct _student {
	char name[10];
	unsigned int score;
	bool operator>(const _student s) {
		return this->score > s.score;
	}
	bool operator<(const _student s) {
		return this->score < s.score;
	}
}Student;
template<typename T>
void bubbleSort(T arr[], int len, int sortby) {
	int i, j;  T temp;
	if (sortby != 0) {
		for (i = 0; i < len - 1; i++)
			for (j = 0; j < len - 1 - i; j++) {
				if (arr[j] > arr[j + 1]) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
	} else {
		for (i = 0; i < len - 1; i++)
			for (j = 0; j < len - 1 - i; j++) {
				if (arr[j] < arr[j + 1]) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
	}

}
int main(int c, char** v) {
	int count;
	int sortby;
	while (cin >> count >> sortby) {
		Student* students = new Student[count];
		for (int i = 0; i < count; i++) {
			cin >> students[i].name >> students[i].score;
		}
		bubbleSort(students, count, sortby);
		for (int i = 0; i < count; i++) {
			cout << students[i].name << " " << students[i].score << endl;
		}
		delete[] students;
	}
}