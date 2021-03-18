#include<iostream>
#include<set>
using namespace std;

void show_set(set<int> set1);
void show_set_size(set<int> set1);
set<int> SetUnion(set<int> set1, set<int> set2);
set<int> SetIntersection(set<int> set1, set<int> set2);
set<int> SetSub(set<int> set1, set<int> set2);
set<int> SetInverse(set<int> set2);

int main(){
	set<int> setA;
	for (int i = 1; i <= 10; i++) {
		setA.insert(i);
	}

	set<int> setB;
	for (int i = 2; i <= 10; i++)
		if (i % 2 == 0)
			setB.insert(i);

    set<int> setC;
	for (int i = 1; i <= 10; i++)
		if (i % 2 != 0)
			setC.insert(i);

	set<int> setD;
	setD.insert(1); setD.insert(2); setD.insert(3);
	setD.insert(5); setD.insert(7);
    
    cout << "The answer of Problem 1 is ";
    /* your codes for Problem 1 */
	show_set(SetIntersection(setA, setD));
    
    cout << "The answer of Problem 2 is ";
    /* your codes for Problem 2 */
	set<int> temp = SetUnion(setB, setC);
	temp = SetIntersection(temp, setA);
	show_set(temp);
    
    cout << "The answer of Problem 3 is ";
    /* your codes for Problem 3 */
	temp = SetInverse(setC);
	temp = SetUnion(temp, setC);
	temp = SetIntersection(temp, setA);
	show_set(temp);
    
    cout << "The answer of Problem 4 is ";
    /* your codes for Problem 4 */
	temp = SetSub(setA, setD);
	show_set(temp);
    
    cout << "The answer of Problem 5 is ";
    /* your codes for Problem 5 */
	set<int> temp2; 
	temp = SetInverse(setA);
	temp2 = SetUnion(setC, setD);
	show_set_size(SetUnion(temp, temp2));
	cout << endl;
    
    cout << "The answer of Problem 6 is ";
    /* your codes for Problem 6 */
	;
	show_set(SetIntersection(setD, setC));
    
    cout << "The answer of Problem 7 is ";
    /* your codes for Problem 7 */
	show_set_size(SetIntersection(setB, setC));
	cout << endl;
    
    cout << "The answer of Problem 8 is ";
    /* your codes for Problem 8 */
	show_set(setA);
    
	return 0;
}

void show_set(set<int> set1) {
    if (set1.empty())
    {
        cout << "This set is empty." << endl;
    } 
    else
    {
        cout << "This set contains: ";
		for (set<int>::iterator it = set1.begin(); it != set1.end(); it++)
		{
			cout << " " << *it;
		}
		cout << endl;
    }
}

void show_set_size(set<int> set1) {
	cout << set1.size();
}

set<int> SetUnion(set<int> set1, set<int> set2) {
    /* TO BE COMPLETED */
	set<int>::iterator it;
	for (it = set2.begin(); it != set2.end(); it++) 
	{
		set1.insert(*it);
	}
	return set1;
}

set<int> SetIntersection(set<int> set1, set<int> set2) {
    /* TO BE COMPLETED */
	set<int>::iterator it;
	set<int> set3;
	for (it = set1.begin(); it != set1.end(); it++) 
	{
		if (set2.find(*it) != set2.end()) 
		{
			set3.insert(*it);
		}
	}
	return set3;
}

set<int> SetSub(set<int> set1, set<int> set2) {
    /* TO BE COMPLETED */
	set<int>::iterator it;
	set<int> set3;
	for (it = set1.begin(); it != set1.end(); it++) 
	{
		if (set2.find(*it) == set2.end())
		{
			set3.insert(*it);
		}
	}
	return set3;
}

set<int> SetInverse(set<int> set2) {
    /* TO BE COMPLETED */
	set<int>::iterator it;
	set<int> setU;
	set<int> setNew;
	for (int i = 1; i < 11; i++)
	{
		setU.insert(i);
	}
	for (it = setU.begin(); it != setU.end(); it++)
	{
		if (set2.find(*it) == set2.end())
			setNew.insert(*it);
	}
	return setNew;
}
