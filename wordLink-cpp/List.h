#pragma once
#include <cstdlib>

class List
{
private:
	struct Node
	{
		char data;
		Node* next;
		Node() : data('0'), next(NULL)
		{}
	};

	typedef struct Node* nodePtr;
	nodePtr head;
	nodePtr curr;
	nodePtr temp;

public:
	List() : head(NULL), curr(NULL), temp(NULL)
	{}

	void AddNode(char addData);
	void DeleteNode();
	void VowelRemoval();
	void LetterReplacement(char r_letter, char n_letter);
	void LetterRemoval(char rem);
	void PrintList();
	void Answer(std::string check);
};
