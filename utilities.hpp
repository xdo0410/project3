#pragma once

#include <fstream>
#include <string>
#include "SearchTree.h"


SearchTree<Entry<string, string> >* buildBST_fromDatafile(const std::string& filename) {
	std::ifstream f(filename.c_str());
	if (!f)
		throw std::runtime_error("cannot open data file");

	std::string s;

	getline(f, s);
	std::string magic("CPSC131 Project3 raw data file");
	if (!f || !std::equal(magic.begin(), magic.end(), s.begin()))
		throw std::runtime_error("incorrect data file");
	getline(f, s);

	std::string firstName, movie;
	
	SearchTree<Entry<string, string>> *bst = new SearchTree<Entry<string, string>>;

	// TO DO: implement the creation of a binary search tree
	while (f) {
		getline(f,s);
        int mark = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ',') {
                mark = i;
            }
        }
        string key, value;
        for (int i = 0; i < mark; i++) {
            firstName += s[i];
        }
        for (int i = mark+1; i < s.length()-1; i++) {
            movie += s[i];
        }
        
        bst->insert(firstName, movie);
        firstName.clear();
        movie.clear();
        
    }
	f.close();

	return bst;
}

// TO DO: You need to implement a function to print a singly linked list in reverse order
void printInReverseOder(SNode<Entry<string,string> >* node)
{
	if (node == NULL) {
        return;
    }
    printInReverseOder(node->getnext());
    string nam,mov;
    Entry<string, string> current;
    current = node->getElem();
    nam = current.key();
    mov = current.value();
    cout << nam << "," << mov << endl;
}


