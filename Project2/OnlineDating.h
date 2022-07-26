#ifndef ONLINEDATING_H
#define ONLINEDATING_H

#include <string>

typedef std::string OnlineType;

class OnlineDating
{
private:
    struct Node {
        std::string firstName;
        std::string lastName;
        OnlineType value;
        Node *next;
        Node *previous;
    };
    Node *head;
    
 public:
    OnlineDating(); // Create an empty OnlineDating list
    
    ~OnlineDating();    // Destroys all the dynamically allocated memory
                        // in the list.
    
    OnlineDating(const OnlineDating& reference); // Copy constructor
    
    OnlineDating& operator=(const OnlineDating& reference); // Assignment operator
    
    bool noMatches() const; // Return true if the OnlineDating list
                            // is empty, otherwise false.
    
    int howManyMatches() const; // Return the number of matches
                                // on the OnlineDating list.
    
    bool makeMatch(const std::string& firstName, const std::string& lastName, const OnlineType& value);
    // If the full name (both the first and last name) is not equal
    // to any full name currently in the list then add it and return
    // true. Elements should be added according to their last name.
    // Elements with the same last name should be added according to
    // their first names. Otherwise, make no change to the list and
    // return false (indicating that the name is already in the
    // list).
    
    bool transformMatch(const std::string& firstName, const std::string& lastName, const OnlineType & value);
    // If the full name is equal to a full name currently in the
    // list, then make that full name no longer map to the value it
    // currently maps to, but instead map to the value of the third
    // parameter; return true in this case. Otherwise, make no
    // change to the list and return false.
    
    bool makeOrTransform(const std::string& firstName, const std::string& lastName, const OnlineType& value);
    // If full name is equal to a name currently in the list, then
    // make that full name no longer map to the value it currently
    // maps to, but instead map to the value of the third parameter;
    // return true in this case. If the full name is not equal to
    // any full name currently in the list then add it and return
    // true. In fact, this function always returns true.
    
    bool blockPreviousMatch(const std::string& firstName, const std::string& lastName);
    // If the full name is equal to a full name currently in the
    // list, remove the full name and value from the list and return
    // true. Otherwise, make no change to the list and return
    // false.
    
    bool someoneAmongMatches(const std::string& firstName, const std::string& lastName) const;
    // Return true if the full name is equal to a full name
    // currently in the list, otherwise false.
    
    bool lookAtMatches(const std::string& firstName, const std::string& lastName, OnlineType& value) const;
    // If the full name is equal to a full name currently in the
    // list, set value to the value in the list that that full name
    // maps to, and return true. Otherwise, make no change to the
    // value parameter of this function and return false.
    
    bool confirmMatch(int i, std::string& firstName, std::string& lastName, OnlineType & value) const;
    // If 0 <= i < size(), copy into firstName, lastName and value
    // parameters the corresponding information of the element at
    // position i in the list and return true. Otherwise, leave the
    // parameters unchanged and return false. (See below for details
    // about this function.)

    void tradeMatches(OnlineDating& other);
    // Exchange the contents of this list with the other one.
};

bool mergeMatches(const OnlineDating & odOne, const OnlineDating & odTwo, OnlineDating & odJoined);
void authenticateMatches (const std::string& fsearch, const std::string& lsearch, const OnlineDating& odOne, OnlineDating& odResult);

#endif /* ONLINEDATING_H */
