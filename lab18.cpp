// comsc 210 | lab18 | Christian Molina

#include <iostream>
#include <string>
using namespace std;

struct ReviewNode
{
    double rating;
    string comment;

    ReviewNode* next;
};

void addHead(ReviewNode*& head, double rating, const string& comment);

int main()
{   
    ReviewNode* head = nullptr;
    int mode;
    
    cout << "which of the linked list method should we use? (1 for head, 2 for tail): ";
    cin >> mode;
    cin.ignore(); // to clear the newline character from the input buffer

    bool moreR = true;
    

}