// comsc 210 | lab18 | Christian Molina

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct ReviewNode
{
    double rating;
    string comment;

    ReviewNode* next;
};

void addHead(ReviewNode*& head, double rating, const string& comment);
void addTail(ReviewNode*& head, double rating, const string& comment);
void displayReviews(ReviewNode* head);
double averageRating(ReviewNode* head);
void deleteList(ReviewNode*& head);

int main()
{   
    ReviewNode* head = nullptr;
    int mode;
    
    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes are added at the head of the linked list\n";
    cout << "    [2] New nodes are added at the tail of the linked list\n";
    cout << "    Choice: ";
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

        if (mode == 1)
        {
            addHead(head, rating, comment);
        }
        else
        {
            addTail(head, rating, comment);
        }
        reviewCount++;// increment the review count

        cout << "Add another review? (y/n): ";
        string respuesta;
        getline(cin, respuesta);

        moreR = (respuesta == "y" || respuesta == "Y");

    }

    cout << "\nOutputting all reviews:\n";
    displayReviews(head);

    double avg = averageRating(head);
    cout << fixed << setprecision(1);
    cout << "Average rating: " << avg << " out of 5.0 from " << reviewCount << " reviews.\n";

    deleteList(head);
    return 0;

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

double averageRating(ReviewNode* head)
{
    double sum = 0.0;
    int count = 0;
    ReviewNode* current = head;
    while (current)
    {
        sum += current->rating;
        count++;
        current = current->next;
    }
    return count > 0 ? sum / count : 0.0;
}

void displayReviews(ReviewNode* head)
{
    int count = 1;
    ReviewNode* current = head;
    while (current)
    {
        cout << "  > Review " << count++ << ": " << fixed << setprecision(1) << current->rating 
             << " - " << current->comment << endl;
        current = current->next;
        ++count;
    }
}

//delete all the nodes in the list
void deleteList(ReviewNode*& head)
{
    ReviewNode* current = head;
    while (current)
    {
        ReviewNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr; // set head to nullptr after deleting the list
}