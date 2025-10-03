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
void addTail(ReviewNode*& head, double rating, const string& comment);

int main()
{   
    ReviewNode* head = nullptr;
    int mode;
    
    cout << "which of the linked list method should we use? (1 for head, 2 for tail): ";
    cin >> mode;
    cin.ignore(); // to clear the newline character from the input buffer

    bool moreR = true;

    int reviewCount = 0;
    while (moreR)
    {
        double rating;
        string comment;

        cout << "Enter rating (0-5): ";
        cin >> rating;
        cin.ignore(); // to clear the newline character from the input buffer
        cout << "Enter comment: ";
        getline(cin, comment);

    }


}

void addHead(ReviewNode*& head, double rating, const string& comment)
{
    ReviewNode* newNode = new ReviewNode;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = head;
    head = newNode;
}

void addTail(ReviewNode*& head, double rating, const string& comment)
{
    ReviewNode* newNode = new ReviewNode;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = nullptr;

    if (!head) // if the list were to be empty
    {
        head = newNode;
        return;
    }

    ReviewNode* current = head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = newNode;
}