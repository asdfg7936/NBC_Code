#include <iostream>
#include <string>

using namespace std;

void print_total_avg(int* array, int count);
void Line_Up(int* array, int count);
void Line_Down(int* array, int count);


int main() {
	int* array;
	int count = 5;
	cout << "�� ���� �л��� �Է��մϱ�?: ";
	cin >> count;
	array = new int[count];
	for (int i = 0; i < count; i++) {
		cout << i + 1 << "��° �л��� ���� �Է�: ";
		cin >> array[i];
	}
	print_total_avg(array, count);
	Line_Up(array, count);
	Line_Down(array, count);

	delete[](array);
	return 0;
}

void print_total_avg(int* array, int count) { //�迭�� �޾Ƽ� �հ�� ��� ���
	int total = 0;
	float avg;
	for (int i = 0; i < count; i++) {
		total += array[i];
	}
	avg = total / count;
	cout << count << "���� �� ����: " << total << endl;
	cout << count << "���� ���: " << avg << endl;
}
void Line_Down(int* array, int count) {//�������� ����
	int temp;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - 1; j++) {
			if (array[i] > array[j]) {//�񱳴���� ���� �񱳴�󺸴� ũ��
				temp = array[i];//���Ľ�ų ����� �ӽ� ������ ����
				array[i] = array[j]; //�񱳴�󺸴� ���� ���� ���� ������ �̵�
				array[j] = temp; // �ӽ� ������ �񱳴���� �ڷ� �̵�
			}
		}
	}
	for (int i = 0; i < count; i++) {
		cout << array[i] << endl;
	}
}
void Line_Up(int* array, int count) { //�������� ����
	int temp;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - 1; j++) {
			if (array[i] < array[j]) {//�񱳴���� ���� �񱳴�󺸴� ������
				temp = array[i]; //���Ľ�ų ����� �ӽ� ������ ����
				array[i] = array[j]; //�񱳴�󺸴� ���� ū ���� ������ �̵�
				array[j] = temp; // �ӽ� ������ �񱳴���� �ڷ� �̵�
			}
		}
	}
	for (int i = 0; i < count; i++) {
		cout << array[i] << endl;
	}
}