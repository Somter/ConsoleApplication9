// ConsoleApplication9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>	
using namespace std;  

class Buyer 
{
public:
	virtual void Update() abstract;	
};

class Shop	
{
	vector<Buyer*> buyer;		
public:
	void Attach(Buyer* by)
	{
		buyer.push_back(by);	
	}
	void Detach(Buyer* by)
	{
		auto iter = find(buyer.begin(), buyer.end(), by);
		if (iter != buyer.end())
			buyer.erase(iter);
	}
	void Notify()
	{
		for (Buyer* o : buyer)	
		{
			o->Update();	
		}
	}
};

class Persn : public Shop	
{
	string name;
	int age;
public:
	string GetName()	
	{
		return name;
	}
	void SetName(string n)	
	{
		name = n;
	}
	int GetAge()
	{
		return age;	
	}
	void SetAge(int m)
	{
		age = m;	
	}		
};

class ConcreteBuyer : public Buyer
{
	Persn* person;	
public:
	ConcreteBuyer(Persn* p)
	{
		person = p;	
	}
	void Update() override 
	{
		char buffer[20];	
		cout << person->GetName() << " - " << person->GetAge() << endl;	
	}
	Persn* GetPrsn() 
	{
		return this->person;		
	}
	void SetClock(Persn* presn)
	{
		this->person = presn;	
	}
};



int main()
{
	Persn* pBuy = new Persn();		

	Buyer* o1 = new ConcreteBuyer(pBuy);	
	Buyer* o2 = new ConcreteBuyer(pBuy);	
	Buyer* o3 = new ConcreteBuyer(pBuy);	 	

	pBuy->Attach(o1);	
	pBuy->Attach(o2);	
	pBuy->Attach(o3);	

	pBuy->SetAge(25);	
	pBuy->SetName("Alex");	
	pBuy->Notify();

	pBuy->Detach(o2);	
	pBuy->Notify();

	pBuy->Detach(o1);	
	pBuy->Notify();	

	delete pBuy;
	delete o1;
	delete o2;
	delete o3;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
