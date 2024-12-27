// 과제 2
//
// Animal이라는 기본 클래스를 정의
// Animal 클래스에는 makesound()라는 순수 가상 함수를 포함
// Animal 클래스를 상속받은 다양한 동물 클래스 ex) Dog, Cat, cow 등등 생성
// 각 동물 클래스에서 makesound() 함수를 재정의하여 해당 동물의 소리를 출력
// = 메인 함수에서 Animal 타입의 포인터 배열을 선언하고 Dog, Cat, Cow를 각각 배열의 원소로 선언하고
// Animal 배열을 반복문으로 순회하면서 각 동물의 울음소리를 내게 함
// 위 코드를 구현했다면 주어진 코드 스니펫을 보고 Zoo 클래스를 정의하라
// 또한 주어진 코드 스니펫을 보고 랜덤으로 동물 객체를 반환하는 createrandomanimal() 함수를 구현하라
//

// 코드?

#include <iostream>
#include <string>
using namespace std;

class Animal { // 클래스 정의
public: // public의 사용 이유? Animal 클래스를 사용하는 모든 곳에서 Dog/Cat/Cow 클래스를 사용할 수 있어야 함
	virtual void makesound() = 0; //가상 함수 makesound()
	virtual ~Animal() {} // 가상 소멸자를 정의 -> 이 클래스를 상속받은 객체가 삭제될 때 올바른 소멸자가 호출될 수 있도록 함 = 사라질 때 올바르게 행동할 수 있도록 보장하는 특별한 규칙 같은 것?
};

class Dog : public Animal {
public:
	void makesound() override {
		cout << "멍" << endl;
	}
};

class Cat : public Animal {
public:
	void makesound() override {
		cout << "야옹" << endl;
	}
};

class Cow : public Animal {
public:
	void makesound() override {
		cout << "음머" << endl;
	}
};
// 'zoo' 클래스를 정의하기?
//	zoo 클래스는 최대 10개의 animal 객체를 저장하기 위한 포인터 배열을 포함해야 한다.
//	동물 객체 추가 / 모든 동물의 행동 수행 기능을 가지고 있어야 한다
//	zoo 객체가 소멸되면 할당된 동물 객체의 메모리를 해제하는 소멸자를 가져야 한다 (delete animals~~)


class Zoo {
private:
	Animal* animals[10];
	int count;

public:
	Zoo() : count(0) {
		for (int i = 0; i < 10; i++) {
			animals[i] = nullptr; // 생성자에서 배열을 초기화했더니 경고가 뜨지 않는다
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
	void quack() { // 소리내기
		for (int i = 0; i < count; i++) {
			animals[i]->makesound();
		}
	}
	~Zoo() { // 소멸자
		for (int i = 0;i < count; i++) {
			delete animals[i];
		}
	}
};

int main() {
	Animal* animals[] = { new Dog(), new Cat(), new Cow() };
	for (Animal* animal : animals) { // 모든 Animal에게~
		animal->makesound(); // " -> "연산자는 화살표만 그리는 기호가 아니고 객체의 멤버에 접근할 때 사용하는 연산자 기호

	}
	for (Animal* animal : animals) {
		delete animal; // 이 과정이 없으면 animal이 남아 있어서 메모리를 차지하게 된다?
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
			continue; // 동물 추가 작업을 건너뛰어줘야 한다?
		}
		else {
			cout << "INVAILD INPUT" << endl;
			continue; // 잘못 눌렀을때 프로그램이 꺼지지 않고 continue 되게 한다
		}
		MakeZoo.addAnimal(newAnimal);
	}

	cout << "Animal Sounds" << endl;
	MakeZoo.quack();

	return 0;
}



