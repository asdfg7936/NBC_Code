#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template <typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;
public:
	void resize(int newCapacity) {
		this->currentCapacity = newCapacity;
		T* temp = new T [newCapacity];
		copy(data, data + min(10, 20), temp);
		delete[] data;
		data = temp;
		temp = NULL;
	}
	SimpleVector(const SimpleVector& other) {
		data = new T[other.currentSize];
		copy(other, other + other.currentSize, data);
	}
	SimpleVector(T Capacity) {
		this->currentCapacity = Capacity;
		this->currentSize = 0;
		data = new T[this->currentCapacity];
	}
	SimpleVector() {
		data = new T[10];
		this->currentSize = 0;
	}
	~SimpleVector() {
		delete[] data;
	}
	void push_back(const T &value) {
		if (this->currentSize < this->currentCapacity) {
			data[this->currentSize] = value;
			this->currentSize++;
		}
		else if(this->currentSize >= this->currentCapacity){
			/*cout << "배열이 가득 찼습니다!" << endl;*/
			this->currentCapacity += 5;
			T* temp = new T[this->currentCapacity+5];
			copy(data, data + min(10, 20), temp);
			delete[] data;
			data = temp;
			temp = NULL;
			data[this->currentSize] = value;
			this->currentSize++;
		}
	}
	void pop_back() {
		if (this->currentSize > 0) {
			this->currentSizee--;
		}
		else {
			cout << "배열에 원소가 없습니다!" << endl;
		}
	}
	void s_size() {
		cout << "현재 배열의 원소의 수: " << this->currentSize << endl;
	}
	void capacity() {
		cout << "현재 배열의 크기: " << this->currentCapacity<< endl;
	}
	void sort_data() {
		sort(this->data, this->data + this->currentSize);
	}

};


int main() {

	return 0;
}