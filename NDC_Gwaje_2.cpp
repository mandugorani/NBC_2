// ���� 2
//
// Animal�̶�� �⺻ Ŭ������ ����
// Animal Ŭ�������� makesound()��� ���� ���� �Լ��� ����
// Animal Ŭ������ ��ӹ��� �پ��� ���� Ŭ���� ex) Dog, Cat, cow ��� ����
// �� ���� Ŭ�������� makesound() �Լ��� �������Ͽ� �ش� ������ �Ҹ��� ���
// = ���� �Լ����� Animal Ÿ���� ������ �迭�� �����ϰ� Dog, Cat, Cow�� ���� �迭�� ���ҷ� �����ϰ�
// Animal �迭�� �ݺ������� ��ȸ�ϸ鼭 �� ������ �����Ҹ��� ���� ��
// �� �ڵ带 �����ߴٸ� �־��� �ڵ� �������� ���� Zoo Ŭ������ �����϶�
// ���� �־��� �ڵ� �������� ���� �������� ���� ��ü�� ��ȯ�ϴ� createrandomanimal() �Լ��� �����϶�
//

// �ڵ�?

#include <iostream>
#include <string>
using namespace std;

class Animal { // Ŭ���� ����
public: // public�� ��� ����? Animal Ŭ������ ����ϴ� ��� ������ Dog/Cat/Cow Ŭ������ ����� �� �־�� ��
	virtual void makesound() = 0; //���� �Լ� makesound()
	virtual ~Animal() {} // ���� �Ҹ��ڸ� ���� -> �� Ŭ������ ��ӹ��� ��ü�� ������ �� �ùٸ� �Ҹ��ڰ� ȣ��� �� �ֵ��� �� = ����� �� �ùٸ��� �ൿ�� �� �ֵ��� �����ϴ� Ư���� ��Ģ ���� ��?
};

class Dog : public Animal {
public:
	void makesound() override {
		cout << "��" << endl;
	}
};

class Cat : public Animal {
public:
	void makesound() override {
		cout << "�߿�" << endl;
	}
};

class Cow : public Animal {
public:
	void makesound() override {
		cout << "����" << endl;
	}
};
// 'zoo' Ŭ������ �����ϱ�?
//	zoo Ŭ������ �ִ� 10���� animal ��ü�� �����ϱ� ���� ������ �迭�� �����ؾ� �Ѵ�.
//	���� ��ü �߰� / ��� ������ �ൿ ���� ����� ������ �־�� �Ѵ�
//	zoo ��ü�� �Ҹ�Ǹ� �Ҵ�� ���� ��ü�� �޸𸮸� �����ϴ� �Ҹ��ڸ� ������ �Ѵ� (delete animals~~)


class Zoo {
private:
	Animal* animals[10];
	int count;

public:
	Zoo() : count(0) {
		for (int i = 0; i < 10; i++) {
			animals[i] = nullptr; // �����ڿ��� �迭�� �ʱ�ȭ�ߴ��� ��� ���� �ʴ´�
		}
	}

	void addAnimal(Animal* animal) {
		if (animal == nullptr) return;
		if (count < 10) {
			animals[count] = animal;
			count++;
		}
		else {
			cout << "Zoo_FULL" << endl;
		}
	}
	void quack() { // �Ҹ�����
		for (int i = 0; i < count; i++) {
			animals[i]->makesound();
		}
	}
	~Zoo() { // �Ҹ���
		for (int i = 0;i < count; i++) {
			delete animals[i];
		}
	}
};

int main() {
	Animal* animals[] = { new Dog(), new Cat(), new Cow() };
	for (Animal* animal : animals) { // ��� Animal����~
		animal->makesound(); // " -> "�����ڴ� ȭ��ǥ�� �׸��� ��ȣ�� �ƴϰ� ��ü�� ����� ������ �� ����ϴ� ������ ��ȣ

	}
	for (Animal* animal : animals) {
		delete animal; // �� ������ ������ animal�� ���� �־ �޸𸮸� �����ϰ� �ȴ�?
	}
	Zoo MakeZoo;
	string animalname;

	cout << "THIS IS ZOO" << endl;
	
	while(true){
		cout << "INPUT ANIMAL NAME (Dog / Cat / Cow) or press 1 to sound / press 0 to exit:";
		cin >> animalname;
		if (animalname == "0") {
			break;
		}
		Animal* newAnimal = nullptr;

		if (animalname == "Dog") {
			newAnimal = new Dog();
		}
		else if (animalname == "Cat") {
			newAnimal = new Cat();
		}
		else if (animalname == "Cow") {
			newAnimal = new Cow();
		}
		else if (animalname == "1") {
			MakeZoo.quack();
			continue; // ���� �߰� �۾��� �ǳʶپ���� �Ѵ�?
		}
		else {
			cout << "INVAILD INPUT" << endl;
			continue; // �߸� �������� ���α׷��� ������ �ʰ� continue �ǰ� �Ѵ�
		}
		MakeZoo.addAnimal(newAnimal);
	}

	cout << "Animal Sounds" << endl;
	MakeZoo.quack();

	return 0;
}



