#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	virtual void MakeSound() {};
	~Animal() {
		cout << "Animal�� ����" << endl;
	}
};

class Zoo {
private:
	Animal* animals;
	int size;
	int count;
public:
	int Get_Count() {
		return count;
	}
	void Set_Count(int count) {
		this->count = count;
	}
	Zoo(int size) {
		this->size = size;
		this->animals = new Animal[size];
		this->count = 0;
	}
	void addanimal(Animal* animal) {
		if (count < size) {
			animals[count] = *animal;
			count++;
		}
	};
	void perforActions() {
		for (int i = 0; i < count; i++) {
			animals[i].MakeSound();
		}
	};
	~Zoo() {
		delete[] (this->animals);
	}
};

class Dog : public Animal {
public:
	void MakeSound() {
		cout << "���� �۸��ϰ� �����." << endl;
	}
};
class Cat : public Animal {
public:
	void MakeSound() {
		cout << "����̴� �߿��ϰ� �����." << endl;
	}
};
class Cow : public Animal {
public:
	void MakeSound() {
		cout << "�Ҵ� �����ϰ� �����." << endl;
	}
};
int main() {
	Dog dog;
	Cat cat;
	Cow cow;
	Zoo zoo(10);
	dog.MakeSound();
	cat.MakeSound();
	cow.MakeSound();
	zoo.addanimal(&dog);
	zoo.perforActions();

}