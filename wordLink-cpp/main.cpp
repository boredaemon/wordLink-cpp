#include <cstdlib>
#include <iostream>
#include "List.h"
#include <string> 
#include <fstream>


void display()
{
	std::cout << "Q - Quit" << std::endl;
	std::cout << "I - Insert" << std::endl;
	std::cout << "D - Delete an Object" << std::endl;
	std::cout << "E - Edit" << std::endl;
	std::cout << "C - Contents of display" << std::endl;
	std::cout << "S - Save to file" << std::endl;
	std::cout << "L - Load from file" << std::endl;
	std::cout << "A - Answer" << std::endl;
	std::cout << "" << std::endl;
}

int main()
{
	List word_list[10];
	List edit_list[10];
	//List word_list;

	std::string word;
	int i;
	int num;
	int ctr{ -1 };
	char choice;
	int option;
	char r_letter;
	char n_letter;
	char rem;

	display();

	/* TEMPORARY SECTION

	std::ifstream infile;
	infile.open("Load.txt");
	// Check for Error

	if (infile.fail())
	{
	std::cerr << "Error opening the file" << std::endl;
	exit(1);
	}

	while (!infile.eof())
	{
	++ctr;
	infile >> word;

	for (i = 0; i < static_cast<int>(word.length()); i++)
	{
	word_list[ctr].AddNode(word[i]);
	edit_list[ctr].AddNode(word[i]);
	}

	}

	for (int val = 0; val <= ctr; val++)
	{
	std::cout << val << ".";
	word_list[val].PrintList();
	}

	return 0;
	}

	TEMPORARY SECTION */


	do
	{
		std::cin >> choice;

		if (choice == 'L')
		{
			std::cout << "Loading from the File..." << std::endl;

			std::ifstream infile;
			infile.open("Load.txt");
			// Check for Error

			if (infile.fail())
			{
				std::cerr << "Error opening the file" << std::endl;
				exit(1);
			}

			// End of file contents
			while (!infile.eof())
			{
				++ctr;
				infile >> word;

				for (i = 0; i < static_cast<int>(word.length()); i++)
				{
					word_list[ctr].AddNode(word[i]);
					edit_list[ctr].AddNode(word[i]);
				}

			}

		}

		if (choice == 'A')
		{
			int sent;
			int guess;
			std::string check;


			std::cout << "The Modified Words are  ..." << std::endl;
			for (sent = 0; sent <= ctr; sent++)
			{
				std::cout << sent << ". ";
				edit_list[sent].PrintList();
			}

			std::cout << "Word you want to guess ??" << std::endl;
			std::cin >> guess;
			std::cout << "Enter the Word" << std::endl;
			std::cin >> check;
			//std::getline(std::cin, check);
			word_list[guess].Answer(check);
		}

		if (choice == 'I')
		{
			++ctr;
			std::cout << "Insert Word:" << ctr << std::endl;
			//std::cin.ignore();
			//std::cin.clear();
			//std::getline(std::cin, word);
			std::cin >> word;

			for (i = 0; i < static_cast<int>(word.length()); i++)
			{
				word_list[ctr].AddNode(word[i]);
				edit_list[ctr].AddNode(word[i]);
			}
		}

		if (choice == 'D')
		{
			std::cout << "Enter the Word Number: " << std::endl;
			std::cin >> num;
			edit_list[num].DeleteNode();
		}

		if (choice == 'E')
		{
			if (ctr < 0)
			{
				std::cout << "Nothing to do ... No words exist to edit" << std::endl;
			}

			else
			{
				std::cout << "Word you want to edit ??" << std::endl;
				std::cin >> num;

				std::cout << "Select the edit option:" << std::endl;
				std::cout << "1. Letter Replacement" << std::endl;
				std::cout << "2. Vowel Removal" << std::endl;
				std::cout << "3. Letter Removal" << std::endl;
				std::cout << "" << std::endl;
				std::cin >> option;

				if (num > ctr)
				{
					std::cout << "The Word doesnt exist... !!" << std::endl;
				}

				else
				{
					switch (option)
					{
					case 1:
					{
						std::cout << "Letter to be replaced ...??" << std::endl;
						std::cin >> r_letter;
						std::cout << "Letter to be replaced by ...??" << std::endl;
						std::cin >> n_letter;
						edit_list[num].LetterReplacement(r_letter, n_letter);
					}
					break;

					case 2:
					{
						edit_list[num].VowelRemoval();
						std::cout << "All Vowels Removed ... " << std::endl;
					}
					break;

					case 3:
					{
						std::cout << "Letter to be removed ...??" << std::endl;
						std::cin >> rem;
						edit_list[num].LetterRemoval(rem);
					}
					break;

					default:
					{
						std::cout << "Unhandled Value !!" << std::endl;
					}
					break;

					} //switch
				} // selected string exist
			} // strings exist

		} // E selected

		if (choice == 'C')
		{
			int val;
			std::cout << "Original Unmodified words.... " << std::endl;
			for (val = 0; val <= ctr; val++)
			{
				std::cout << val << ".";
				word_list[val].PrintList();
			}
			std::cout << "Modified Words.... " << std::endl;
			for (val = 0; val <= ctr; val++)
			{
				std::cout << val << ".";
				edit_list[val].PrintList();
			}

		}

	} while (choice != 'Q');

	std::cout << "Exiting ......." << std::endl;
	return 0;
}

