#include <iostream>
#include <string>
#include <queue>
#include <cstdio>


using namespace std;

int count = 0;

struct Animal
{
	string name;
	char type;
	int timeStamp;
};

Animal *newAnimal(string name, char type)
{
	Animal *tmp = new Animal();
	tmp->name = name;
	tmp->type = type;
	tmp->timeStamp = count++;
	return tmp;
}

class Adoption
{
public:
	Adoption();
	void enqueue(string, char);
	void display(queue<Animal *>);
	void displayAnimalData(Animal *anml);
	Animal *dequeueAny();
	Animal *dequeueDog();
	Animal *dequeueCat();
	queue<Animal *> cats;
	queue<Animal *> dogs;
};

Adoption::Adoption()
{
	printf("Adoption DS Created.\n");
}

void Adoption::enqueue(string name, char type)
{
	Animal *tmp = newAnimal(name, type);
	if(type == 'd' || type == 'D')
		dogs.push(tmp);
	else
		cats.push(tmp);
}

void Adoption::displayAnimalData(Animal *anml)
{
	printf("Name :\t%s\nType :\t%c\nTime :\t%d\n",anml->name.c_str(), anml->type, anml->timeStamp);
	printf("\n");
}

void Adoption::display(queue<Animal *> anmlQue)
{
	while(!anmlQue.empty())
	{
		displayAnimalData(anmlQue.front());
		anmlQue.pop();
	}
}

Animal* Adoption::dequeueAny()
{
	Animal *cat = cats.front();
	Animal *dog = dogs.front();
	Animal *result;
	if(dog->timeStamp < cat->timeStamp)
	{
		result = dog;
		dogs.pop();
	}
	else
	{
		result = cat;
		cats.pop();
	}
	displayAnimalData(result);
	return result;
}

Animal* Adoption::dequeueDog()
{
	Animal *dog = dogs.front();
	dogs.pop();
	displayAnimalData(dog);
	return dog;
}

Animal* Adoption::dequeueCat()
{
	Animal *cat = cats.front();
	cats.pop();
	displayAnimalData(cat);
	return cat;
}




int main()
{
	Adoption ad;
	ad.enqueue("D3", 'd');
	ad.enqueue("C1", 'c');
	ad.enqueue("C2", 'c');
	ad.enqueue("C3", 'c');
	ad.enqueue("C4", 'c');
	ad.enqueue("C5", 'c');
	ad.enqueue("C6", 'c');
	ad.enqueue("D1", 'd');
	ad.enqueue("D2", 'd');
	ad.enqueue("D3", 'd');
	ad.enqueue("D4", 'd');
	ad.enqueue("D5", 'd');
	ad.enqueue("D6", 'd');
	ad.enqueue("D7", 'd');
	ad.display(ad.cats);
	ad.display(ad.dogs);

	printf("\nDequeued :\n");
	ad.dequeueAny();

	return 0;
}
