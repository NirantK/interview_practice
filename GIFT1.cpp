/*
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
string people[10];
int NP;
int balance[10];
int getIndex(string person){
	for(int i = 0; i < NP; ++i){
		if(person == people[i]) return i;
	}
	return -1;
}
int main(){
	memset(balance, 0, 10 * sizeof(int));
	ofstream fout ("gift1.out");;
	ifstream fin ("gift1.in");
	fin >> NP;
	cout << NP << endl;
	for(int i=0; i<NP;++i){
		fin >> people[i];
	}
	for (int i = 0; i < NP; ++i)
	{
		string giver;
		fin >> giver;
		int amount, number_of_people;
		fin >> amount >> number_of_people;
		// cout << amount << number_of_people << "\n";
		if(number_of_people ==0) continue; //this is clever man, avoids division by zero, saves a lot of computation
		int realAmount = amount - (amount % number_of_people);
		int money_per_person = realAmount / number_of_people ; 
		balance[getIndex(giver)] += -realAmount;
		for (int j = 0; j < number_of_people; ++j)
		{
			string receiver;
			fin >> receiver;
			balance[getIndex(receiver)] += money_per_person;
		}

	}
	for (int i = 0; i < NP; ++i)
	{
		fout << people[i] << " " << balance[i] << "\n";

	}
	return 0;
}