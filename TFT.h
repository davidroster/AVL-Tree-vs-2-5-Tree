#ifndef __TFT_H_INCLUDED__
#define __TFT_H_INCLUDED__

#include "TFTNode.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <dirent.h>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <ctime>

using namespace std;

class TFT
{
    TFTNode *root; // Pointer to root node
    int MAXWORDS;  // Minimum degree

    public:
    
        // Constructor (Initializes tree as empty)
        TFT(int _t);
    
        void traverse();

        void lexSort(ofstream &outputFile);

        void insert(std::string word);

        void deleteOne(std::string word);

        std::vector<std::string> rangeSearch(std::string begin, std::string end);

        TFTNode* search(std::string word)
        {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            return (root == NULL)? NULL : root->search(word);
        }
};

#endif