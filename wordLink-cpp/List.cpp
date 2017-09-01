#pragma once
#include <iostream>
#include "List.h"

void List::AddNode(char addData)
{
	nodePtr _node = new Node;
	_node->next = NULL;
	_node->data = addData;

	if (head != NULL)
	{
		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = _node;
	}
	else
	{
		head = _node;
	}
}

void List::DeleteNode()
{
	nodePtr delPtr = NULL;
	if (head != NULL)
	{
		delPtr = head;
		head = head->next;
		delete delPtr;
	}
	else
	{
		std::cout << "Nothing to delete .... !!" << std::endl;
	}
}

void List::PrintList()
{
	curr = head;
	while (curr != NULL)
	{
		std::cout << curr->data;
		curr = curr->next;
	}
	std::cout << "" << std::endl;
}

void List::LetterReplacement(char r_letter, char n_letter)
{
	curr = head;
	while (curr != NULL)
	{
		if (curr->data == r_letter)
		{
			curr->data = n_letter;
		}

		curr = curr->next;
	}

}

void List::VowelRemoval()
{
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;

	while (curr != NULL)
	{
		if (head->data == 'a' || head->data == 'e' || head->data == 'i'
			|| head->data == 'o' || head->data == 'u' || head->data == 'A' || head->data == 'E' || head->data == 'I'
			|| head->data == 'O' || head->data == 'U')
		{
			delPtr = head;
			head = head->next;
			curr = head;
			temp = curr;
			curr = curr->next;
			delete delPtr;
		}

		//curr = curr->next;

		else if (curr->data == 'a' || curr->data == 'e' || curr->data == 'i'
			|| curr->data == 'o' || curr->data == 'u' || curr->data == 'A' || curr->data == 'E' || curr->data == 'I'
			|| curr->data == 'O' || curr->data == 'U')
		{
			delPtr = curr;
			curr = curr->next;
			temp->next = curr;
			delete delPtr;
		}

		else
		{
			temp = curr;
			curr = curr->next;
		}

	}
}

void List::LetterRemoval(char rem)
{
	curr = head;
	while (curr != NULL)
	{
		if (curr->data == rem)
		{
			curr->data = ' ';
		}

		curr = curr->next;
	}

}

void List::Answer(std::string check)
{
	int flag;
	int k{ 0 };
	curr = head;
	while (curr != NULL && check[k] != '\n')
	{
		if (check[k] == (curr->data))
		{
			flag = 0;
		}
		else
		{
			flag = 1;
			break;
		}

		curr = curr->next;
		++k;
	}

	if (flag == 0)
	{
		std::cout << "Sentences Match ..... Hurray !!" << std::endl;
	}

	else
	{
		std::cout << "Sentences Do Not Match .... Try Again !!" << std::endl;
	}
}