/*
 * File: WordLadder.cpp
 * --------------------
 * Name: Prashanth Yerramilli
 * Section: Prashanth Yerramilli
 * This file is the starter project for the word ladder problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */

#include "genlib.h"
#include "lexicon.h"
#include "queue.h"
#include "simpio.h"
#include "vector.h"
#include <iostream>

string findNextWord(string word, Lexicon dictionary, Lexicon alreadyUsed);
void processMainGame(Lexicon dictionary, string startWord, string endWord);

//int main() {
//	// load the 
//	Lexicon dictionary("EnglishWords.dat");
//	string startWord, endWord;
//
//	while (true)
//	{
//		cout << "Please enter first word (RETURN TO QUIT) : ";
//		startWord = GetLine();
//		if (startWord == "") return 0;
//		cout << "Please enter end word (RETURN TO QUIT) : ";
//		endWord = GetLine();
//		if (endWord == "") return 0;
//
//		processMainGame(dictionary, startWord, endWord);
//	}
//	return 0;
//}

// this is where most of the work is done
void processMainGame(Lexicon dictionary, string startWord, string endWord)
{
	Queue<Vector<string> > theFIFO;
	Lexicon alreadyUsed;
	string nextStr;

	theFIFO.clear();
	Vector<string> addToQueue;
	addToQueue.add(startWord);
	// start the queue
	theFIFO.enqueue(addToQueue);

	while (true)
	{
		// build up a new list of items to search, or stop if empty
		if (theFIFO.size() ==0)
		{
			cout << "Nope nothing found! no ladder"<< endl;
			break;
		}
		Vector<string> newString = theFIFO.dequeue();
		while (true)
		{
			// find the next word to use
			nextStr = findNextWord(newString[newString.size()-1], dictionary, alreadyUsed);
			// the end of the search
			if (nextStr == endWord) 
			{
				cout << "FOUND ladder !!" << endl;
				foreach (string list in newString)
				{
					cout << list << " - ";
				}
				cout << endWord << endl << endl;
				return;
			} else if (nextStr != "")
			{
				// if there is another word to search with add to the end of the list
				Vector<string> addMore = newString;
				addMore.add(nextStr);
				theFIFO.enqueue(addMore);
			}
			// else if nothing left to search for stop!!
			else if (nextStr =="")
				break;
			alreadyUsed.add(nextStr);
		}
	}
}

string findNextWord(string word, Lexicon dictionary, Lexicon alreadyUsed)
{
	string newWord;
	for (int i =0; i < word.length(); i++)
	{
		newWord = word;
		for (char ch = 'a'; ch <= 'z'; ch++)
		{
			// create a new word
			newWord = newWord.replace(i,1,1, ch);
			// make sure it is a valid word and also not already used
			if (dictionary.containsWord(newWord))
				if (!alreadyUsed.containsWord(newWord))
					return newWord;
		}
	}
	return "";
}