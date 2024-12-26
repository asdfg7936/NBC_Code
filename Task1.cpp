#include <iostream>
#include <string>

using namespace std;

void print_total_avg(int* array, int count);
void Line_Up(int* array, int count);
void Line_Down(int* array, int count);


int main() {
	int* array;
	int count = 5;
	cout << "몇 명의 학생을 입력합니까?: ";
	cin >> count;
	array = new int[count];
	for (int i = 0; i < count; i++) {
		cout << i + 1 << "번째 학생의 점수 입력: ";
		cin >> array[i];
	}
	print_total_avg(array, count);
	Line_Up(array, count);
	Line_Down(array, count);

	delete[](array);
	return 0;
}

void print_total_avg(int* array, int count) { //배열을 받아서 합계와 평균 출력
	int total = 0;
	float avg;
	for (int i = 0; i < count; i++) {
		total += array[i];
	}
	avg = total / count;
	cout << count << "명의 총 점수: " << total << endl;
	cout << count << "명의 평균: " << avg << endl;
}
void Line_Down(int* array, int count) {//내림차순 정렬
	int temp;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - 1; j++) {
			if (array[i] > array[j]) {//비교대상이 다음 비교대상보다 크면
				temp = array[i];//정렬시킬 대상을 임시 변수에 저장
				array[i] = array[j]; //비교대상보다 값이 작은 값을 앞으로 이동
				array[j] = temp; // 임시 저장한 비교대상을 뒤로 이동
			}
		}
	}
	for (int i = 0; i < count; i++) {
		cout << array[i] << endl;
	}
}
void Line_Up(int* array, int count) { //오름차순 정렬
	int temp;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - 1; j++) {
			if (array[i] < array[j]) {//비교대상이 다음 비교대상보다 작으면
				temp = array[i]; //정렬시킬 대상을 임시 변수에 저장
				array[i] = array[j]; //비교대상보다 값이 큰 값을 앞으로 이동
				array[j] = temp; // 임시 저장한 비교대상을 뒤로 이동
			}
		}
	}
	for (int i = 0; i < count; i++) {
		cout << array[i] << endl;
	}
}