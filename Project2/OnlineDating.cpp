#include "OnlineDating.h"
using namespace std;

OnlineDating::OnlineDating() // Create an empty OnlineDating list
{
    head = nullptr;
}

OnlineDating::~OnlineDating() { // Destructor 
    if (head != nullptr)
    {
        Node *move; // pointer to traverse throughout LinkedList
        move = head; // assigns the new pointer variable to point to the first node
        Node *saveNext;
        while (move != nullptr) // traversing through the list; stopping at last node
        {
            saveNext = move->next; // saves address of next node
            delete move; // deletes previous node
            move = saveNext; // re-assigning where move points to
        }
    }
}

// copy constructor
OnlineDating::OnlineDating(const OnlineDating& reference) {
    if (reference.head != nullptr)
    {
        Node *move; // pointer to traverse throughout reference
        move = reference.head; // assigns the pointer variable to point to the first node of the referennce list
        Node *copiedNode = new Node; // dynamically allocating a new node
        head = copiedNode; // setting the head pointer to the first node of the new list
        head->firstName = move->firstName; // copies reference's first name
        head->lastName = move->lastName; // copies reference's last name
        head->value = move->value; // copying the value of reference's first node
        head->previous = nullptr;
        move = move->next; // moves to next node of reference list
        Node *connect; // moving pointer for this list
        connect = head; // assigning the pointer to this list's first node's next
        Node *savePrevious = nullptr;
        while (move != nullptr) // traversing through the list; stopping at reference's last node
        {
            Node *copiedNode = new Node; // dynamically allocating a new node for each of reference's nodes
            connect->next = copiedNode; // linking past node's next with address of this node
            savePrevious = connect;
            connect = connect->next;
            connect->firstName = move->firstName;
            connect->lastName = move->lastName;
            connect->value = move->value; // copying the value of the reference node
            connect->previous = savePrevious;
            move = move->next;
        }
        connect->next = nullptr; // sets last node as last node
    }
    else
    {
        head = nullptr; // empty reference, making an empty list
    }
}

// assignment operator
OnlineDating& OnlineDating::operator=(const OnlineDating& reference) {
    if (&reference == this) // checking aliasing
    {
        return *this;
    }
    if (reference.head == nullptr)
    {
        Node *move; // pointer to traverse
        move = head; // assigns the new pointer variable to point to the first node of reference
        Node *saveNext;
        while (move != nullptr) // traversing through the list; stopping at last node
        {
            saveNext = move->next; // saves the next node's address
            delete move; // deletes current node
            move = saveNext; // re-assigning where move points to
        }
        head = nullptr;
        return *this;
    }
    if (head == nullptr)
    {
        // essentially, copy constructor since you have to make a new list from an empty one
        Node *move; // pointer to traverse throughout reference
        move = reference.head; // assigns the pointer variable to point to the first node of the referennce list
        Node *copiedNode = new Node; // dynamically allocating a new node
        head = copiedNode; // setting the head pointer to the first node of the new list
        head->firstName = move->firstName; // copies reference's first name
        head->lastName = move->lastName; // copies reference's last name
        head->value = move->value; // copying the value of reference's first node
        head->previous = nullptr;
        move = move->next; // moves to next node of reference list
        Node *connect; // moving pointer for this list
        connect = head; // assigning the pointer to this list's first node's next
        Node *savePrevious = nullptr;
        while (move != nullptr) // traversing through the list; stopping at reference's last node
        {
            Node *copiedNode = new Node; // dynamically allocating a new node for each of reference's nodes
            connect->next = copiedNode; // linking past node's next with address of this node
            savePrevious = connect;
            connect = connect->next;
            connect->firstName = move->firstName;
            connect->lastName = move->lastName;
            connect->value = move->value; // copying the value of the reference node
            connect->previous = savePrevious;
            move = move->next;
        }
        connect->next = nullptr; // sets last node as last node
    }
    Node *traverse; // pointer to traverse throughout reference
    traverse = head; // assigns the new pointer variable to point to the first node of reference
    Node *saveNext;
    while (traverse != nullptr) // traversing through the list; stopping at last node
    {
        saveNext = traverse->next; // saves the next node's address
        delete traverse; // deletes current node
        traverse = saveNext; // re-assigning where move points to
    }
    Node *move; // pointer to traverse throughout reference
    move = reference.head; // assigns the pointer variable to point to the first node of the referennce list
    Node *copiedNode = new Node; // dynamically allocating a new node
    head = copiedNode; // setting the head pointer to the first node of the new list
    head->firstName = move->firstName; // copies reference's first name
    head->lastName = move->lastName; // copies reference's last name
    head->value = move->value; // copying the value of reference's first node
    head->previous = nullptr;
    move = move->next; // moves to next node of reference list
    Node *connect; // moving pointer for this list
    connect = head; // assigning the pointer to this list's first node's next
    Node *savePrevious = nullptr;
    while (move != nullptr) // traversing through the list; stopping at reference's last node
    {
        Node *copiedNode = new Node; // dynamically allocating a new node for each of reference's nodes
        connect->next = copiedNode; // linking past node's next with address of this node
        savePrevious = connect;
        connect = connect->next;
        connect->firstName = move->firstName;
        connect->lastName = move->lastName;
        connect->value = move->value; // copying the value of the reference node
        connect->previous = savePrevious;
        move = move->next;
    }
    connect->next = nullptr; // sets last node as last node
    return *this;
}

bool OnlineDating::noMatches() const    // Return true if the OnlineDating list
                                        // is empty, otherwise false.
{
    if (head == nullptr)
    {
        return true;
    }
    return false;
}

int OnlineDating::howManyMatches() const
{
    int numMatches = 0;
    Node *move; // pointer to traverse throughout LinkedList
    move = head; // assigns the new pointer variable to point to the first node
    while (move != nullptr) // traversing through the list; stopping at last node
    {
        numMatches++; // keeping track of number of elements
        move = move->next; // re-assigning where move points to
    }
    return numMatches;
}

bool OnlineDating::makeMatch(const string& firstName, const string& lastName, const OnlineType& value)
{
    if (head == nullptr) // if empty list, we don't need to worry about ordering alphabetically
    {
        head = new Node; // dynamically allocate a new node and set head to it
        head->firstName = firstName; // set the first name of the new node to the firstName parameter
        head->lastName = lastName; // set the last name of the new node to the lastName parameter
        head->value = value; // set the value of the new node to the value parameter
        head->previous = nullptr; // set previous of current node to nullptr
        head->next = nullptr; // set next of current node to nullptr
        return true;
    }
    Node *move = head; // temp pointer variable set to head of list
    Node *savePrevious = head; // temp pointer variable meant to save the previous node's address
    while (move != nullptr) // potentially traversing through entire list
    {
        if (move->lastName > lastName) // if the current node's last name is later in the ASCII table (current node should be later in the list after insertion of new node),
        {
            Node *insert = new Node; // dynamically allocoate new node and set a pointer to it
            insert->firstName = firstName; // set the first name of the new node to the firstName argument
            insert->lastName = lastName; // set the last name of the new node to the lastName argument
            insert->value = value; // set the value of the new node to the value argument
            insert->previous = move->previous; // set the new node's previous to current node's previous (even if current node was first node, previous will successfully pass as nullptr)
            insert->next = move; // set the next of the new node to the address of current node
            if (move->previous == nullptr) // if this new node is being added to the front
            {
                move->previous = insert; // set the previous of the current node to the address of the new node
                head = insert; // set head to insert
                return true;
            }
            move->previous = insert; // set the previous of the current node to the address of the new node
            savePrevious->next = insert; // set the previous node's next to the new node's address
            return true;
        }
        else if (move->lastName == lastName) // if the current node's last name matches with the last name argument,
        {
            while (move != nullptr && move->lastName == lastName) // loop through the rest of the list and check if there are other names in the list with the same last name
            {
                if (move->firstName == firstName) // if full name exists in the list,
                {
                    return false; // leave and return false
                }
                if (move->firstName > firstName) // if the first name of the current list is farther along the ascii table (current node should be later along the list than new node)
                {
                    break; // leave while loop
                }
                savePrevious = move;
                move = move->next; // traverse to next node
            }
            Node *insert = new Node; // temp pointer variable to dynamically allocated node
            insert->firstName = firstName; // set the first name of the new node to the firstName argument
            insert->lastName = lastName; // set the last name of the new node to the lastName argument
            insert->value = value; // set the value of the new node to the value argument
            insert->previous = savePrevious; // set the new node's previous to current node's previous (even if current node was first node, previous will successfully pass as nullptr)
            insert->next = move; // set the new node's next as the current node's address
            if (move == nullptr) // if we have to insert the new node at the end of the list,
            {
                savePrevious->next = insert; // set the previous node's next to new node's address
                return true;
            }
            if (move->previous == nullptr) // if this new node is being added to the front
            {
                move->previous = insert; // set the current node's previous to new node's address
                head = insert; // set head as new node's address
                return true;
            }
            savePrevious->next = insert; // set the previous node's next to new node's address
            move->previous = insert; // set the current node's previous to new node's address
            return true;
        }
        savePrevious = move; // save the current node (which will become the previous node in the next iteration)
        move = move->next; // move to next node
    }
    //if all the nodes in the list are all earlier in the ascii table, then new node goes to the end
    Node *insert = new Node; // temp pointer to dynamically allocated node
    savePrevious->next = insert; // set the next of the previous node to the address of the new node
    insert->firstName = firstName; // set the first name of the new node to the firstName argument
    insert->lastName = lastName; // set the last name of the new node to the lastName argument
    insert->value = value; // set the value of the new node to the value argument
    insert->previous = savePrevious; // set the previous of the new node to the previous node
    insert->next = nullptr; // set the next of the new node to nullptr (new node is last node in list)
    return true;
}

bool OnlineDating::transformMatch(const string& firstName, const string& lastName, const OnlineType & value)
{
    Node *move = head; // temp pointer to head
    while (move != nullptr) // potentially traverse through the whole list
    {
        if (move->lastName == lastName && move->firstName == firstName) // if the current node's full name matches the full name arguments
        {
            move->value = value; // set the current node's value to have the value parameter
            return true;
        }
        move = move->next; // move on to the next node
    }
    return false;
}

bool OnlineDating::makeOrTransform(const string& firstName, const string& lastName, const OnlineType& value)
{
    if (transformMatch(firstName, lastName, value) == true) // if the full name exists in the list, change the value of the node to the value parameter
    {
        return true;
    }
    else // if the full name does not exist in the list
    {
        makeMatch(firstName, lastName, value); // add full name and value to list
        return true;
    }
}

bool OnlineDating::blockPreviousMatch(const string& firstName, const string& lastName)
{
    Node *move = head; // set temp pointer variable to head
    while (move != nullptr) // potentially traversing through whole list
    {
        if (move->lastName == lastName && move->firstName == firstName && move->previous == nullptr) // if current node's full name matches the full name in argument AND this is the first node,
        {
            if (move->next != nullptr) // if this node is not the last node,
            {
                move->next->previous = nullptr; // set the next node's previous to nullptr
            }
            head = move->next; // set the head to the next node
            delete move; // if this node is the last node (first and last), just delete node
            return true;
        }
        else if (move->lastName == lastName && move->firstName == firstName && move->next == nullptr) // if current node's full name matches the full name in argument AND current node is the last node,
        {
            if (move->previous != nullptr) // if current node is not also the first node,
            {
                move->previous->next = nullptr; // set current node's previous node's next to nullptr
                delete move; // delete current node
                return true;
            }
            delete move; // if current node is also the first node, just delete this node
            head = nullptr; // set head to nullptr (empty list)
            return true;
        }
        else if (move->lastName == lastName && move->firstName == firstName) // if full name matches and this is not a node at the front or end
        {
            move->previous->next = move->next; // set the previous node's next to the address of next node
            move->next->previous = move->previous; // set the next node's previous to the address of the previous node
            delete move; // delete move
            return true;
        }
        move = move->next; // move onto next node
    }
    return false; // no full name match, no change to list and return false
}

bool OnlineDating::someoneAmongMatches(const string& firstName, const string& lastName) const
{
    Node *move = head; // temp pointer variable starting at head
    while (move != nullptr) // potentially traversing to the end
    {
        if (move->lastName == lastName && move->firstName == firstName) // if the current node's full name matches the full name arguments
        {
            return true; // stop and return true
        }
        move = move->next; // move onto next node
    }
    return false; // no matches, return false
}

bool OnlineDating::lookAtMatches(const string& firstName, const string& lastName, OnlineType& value) const
{
    Node *move = head; // temp pointer variable starting at head
    while (move != nullptr) // potentially traversing until the last node
    {
        if (move->lastName == lastName && move->firstName == firstName) // if the current node's full name matches the full name arguments
        {
            value = move->value; // set the value parameter to the current node's value
            return true; // stop traversing
        }
        move = move->next; // move onto next node
    }
    return false; // no matches, no change to value and exit
}

bool OnlineDating::confirmMatch(int i, string& firstName, string& lastName, OnlineType & value) const
{
    if (i >= 0 && i < howManyMatches()) // checking if i is a valid element in the list
    {
        Node *move = head; // temp pointer variable starting at head
        int counter = 0; // counter to traverse through the list
        while (counter < i) // traverse until the i'th element in the list
        {
            move = move->next; // moves to next node
            counter++; // counter increments to move on
        }
        // at i'th node
        firstName = move->firstName; // sets firstName parameter to the firstName currently in that node
        lastName = move->lastName; // sets lastName parameter to the lastName currently in that node
        value = move->value; // sets value parameter to the value currently in that node
        return true;
    }
    return false; // i is invalid
}

void OnlineDating::tradeMatches(OnlineDating& other)
{
    OnlineDating holdList(other); // temp list holding other list
    other = *this; // setting the other list to point to this current list
    *this = holdList; // setting the current list to point to the other list
}

bool mergeMatches(const OnlineDating & odOne, const OnlineDating & odTwo, OnlineDating & odJoined)
{
    if (&odOne == &odTwo) // checks case when odOne and odTwo point to the same thing
    {
        odJoined = odOne; // odJoined is replaced by odOne since odOne and odTwo have the same matches
        return true;
    }
    OnlineDating holderList = odJoined; // temporary list holding the joined list in case odJoined points to same list as odOne or odTwo (aliasing)
    string firstn = ""; // sets first name holder to access later to delete that node
    string lastn = ""; // sets last name holder to access later to delete that node
    OnlineType v;
    int j = 0;
    while (odJoined.confirmMatch(j, firstn, lastn, v) == true) // gets the full name of that element node and loops until i is an inaccessible node
    {
        holderList.blockPreviousMatch(firstn, lastn); // deletes that element node based on the full name
        j++; // decrements size
    }
    bool hasSameVal = true; // sets up bool to determine if the code hits a situation that should return false
    int i = 0; // sets up traversing counter
    string firstN = ""; // sets first name holder to access later and compare with other list
    string lastN = ""; // sets last name holder to access later and compare with other list
    OnlineType val; // sets up val holder to access later and compare with other list
    OnlineType compareVal; // sets up val holder to access other list's val and compare
    while (i < odOne.howManyMatches()) // traversing throughout odOne
    {
        odOne.confirmMatch(i, firstN, lastN, val); // sets values to node i's values
        if (odTwo.lookAtMatches(firstN, lastN, compareVal) == true) // checks if the full name of odOne's i'th node matches any full name in odTwo and sets the val of odTwo's node with that full name
        {
            if (val != compareVal) // compares values again, but case when the values don't match up
            {
                hasSameVal = false; // set the return value to false to return false later after saving all other nodes
                i++; // increment i to move on to next node
                continue; // go to next part of while loop
            }
        }
        holderList.makeMatch(firstN, lastN, val); // if odTwo doesn't have odOne's full name, just add odOne's node in holderList
        i++; // move onto next node of odOne
    }
    int k = 0; // sets up traversing counter for odTwo
    while (k < odTwo.howManyMatches()) // loop through odTwo
    {
        odTwo.confirmMatch(k, firstN, lastN, val); // set the values of the k'th node in odTwo into these parameters
        if (odOne.lookAtMatches(firstN, lastN, compareVal) == true) // check if the full name from odTwo matches a node in odOne and set that node's val to compareVal
        {
            k++; // move on since you already accounted for this in the first traversal
            continue;
        }
        holderList.makeMatch(firstN, lastN, val); // adds all other names from odTwo to holderList
        k++;
    }
    odJoined = holderList;
    return hasSameVal;
}

void authenticateMatches (const string& fsearch, const string& lsearch, const OnlineDating& odOne, OnlineDating& odResult)
{
    OnlineDating holderList = odResult; // temporary list holding the odResult list in case odResult points to same list as odOne
    string firstn = ""; // sets first name holder to access later to delete that node
    string lastn = ""; // sets last name holder to access later to delete that node
    OnlineType v;
    int i = 0;
    while (odResult.confirmMatch(i, firstn, lastn, v) == true) // traversing through temporary list using the actual odResult list and gets the full name of the i'th element
    {
        holderList.blockPreviousMatch(firstn, lastn); // deletes that node
        i++;
    }
    if (odOne.noMatches() == true) // odOne is empty, then just stop
    {
        return;
    }
    if (fsearch == "*" && lsearch == "*") // if both arguments are wild, then all nodes from odOne are valid
    {
        odResult = odOne; // sets odResult to the same list as odOne
        return;
    }
    //
    for (int i = 0; i < odOne.howManyMatches(); i++) // traversing through odOne
    {
        string fn = ""; // sets first name holder to access later
        string ln = ""; // sets last name holder to access later
        OnlineType val;
        odOne.confirmMatch(i, fn, ln, val); // sets values of the i'th to the parameters
        if (fsearch == "*" && ln == lsearch) // if the fsearch is the wild card and the last name of the current node matches the last name argument,
        {
            holderList.makeMatch(fn, ln, val); // add this node's information to the holderList
        }
        else if (lsearch == "*" && fn == fsearch) // if the lsearch is the wild card and the first name of the current node matches the first name argument,
        {
            holderList.makeMatch(fn, ln, val); // add this node's information to the holderList
        }
        if (fsearch != "*" && lsearch != "*" && odOne.lookAtMatches(fsearch, lsearch, val) == true) // if both fsearch and lsearch are not wildcards and there is any match for the full name,
        {
            holderList.makeMatch(fsearch, lsearch, val); // add this node's information to the holderList
            odResult = holderList; // replace the odResult with temp list
            return;
        }
    }
    odResult = holderList; // replace the odResult with the temp list
    return;
}
