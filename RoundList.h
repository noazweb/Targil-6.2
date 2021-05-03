/*noa zwebner 324989714*/
#pragma once
#include "List.h"
#include<iostream>
#include<string>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;
class RoundList:public List
{
public:
	bool isEmpty() const;
	RoundList();     //default constractor
	RoundList(const RoundList&);     //copy-constractor
	~RoundList();
	void add(int value);     //add to the top 
	void removeFirst();     //remove first
	void clear();       //clear list
	void addToEnd(int val);    //add to the end
	int search(int n);      //search in the list
};

