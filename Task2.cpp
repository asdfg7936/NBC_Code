#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	virtual void MakeSound() {};
	~Animal() {
		cout << "Animal을 종료" << endl;
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
		cout << "개는 멍멍하고 울었다." << endl;
	}
};
class Cat : public Animal {
public:
	void MakeSound() {
		cout << "고양이는 야옹하고 울었다." << endl;
	}
};
class Cow : public Animal {
public:
	void MakeSound() {
		cout << "소는 음머하고 울었다." << endl;
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