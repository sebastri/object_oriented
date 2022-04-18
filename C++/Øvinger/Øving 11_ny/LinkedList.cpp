#include "LinkedList.h"
#include <cassert>


// The insert function takes a pointer to node (pos) and a string (value). It creates a new
// node which contains value. The new node is inserted into the LinkedList BEFORE the
// node pointed to by pos. Returns a pointer to the new Node

namespace LinkedList{

    Node* LinkedList::insert(Node *pos, const std::string& value){

        if(pos == begin()) //hvis pos er først node
        {
            head = std::make_unique<Node>(value, std::move(head), nullptr);
            pos->prev = begin();
        }

    else{

    //1 finner forrige node
    auto prevNode = pos->prev;
    //2 gjør at forrige node peker på den nye som vi oppretter og eier den
    prevNode->next = std::make_unique<Node>(value, std::move(prevNode->next), prevNode);
    //3
    pos->prev = prevNode->getNext();
    }
    //returnerer en peker til 
    return pos->prev; 
    }

    // The remove function takes a pointer to a node, and removes the node from the list. The
    // function returns a pointer to the element after the removed node.
    Node* LinkedList::remove(Node* pos){
        assert(pos);
        assert(pos!=end()); //kan ikke fjerne siste node

        if(pos == begin())//hvis pos er første node, flytter på head pekeren (som er en unique_ptr)
        {
            head = std::move(pos->next);
            head->prev = nullptr;
            return begin();
        } 
        else{

        auto retafter = pos->getNext();
        
        pos->next->prev = pos->prev;
        
        pos->prev->next = std::move(pos->next);

        //pos vil forsvinne når den går ut av skop

        return retafter;

        }

        
    }

    Node* LinkedList::find(const std::string& value){
        auto node = begin();

        while (node != end() && node->value != value)
        {
            node = node->getNext(); //går gjennom hele lista, går ut av løkke hvis den finner verdien, eller når den har nådd dummy node
        }
        return node;
        
    }

    void LinkedList::remove(const std::string& value){
        auto node = find(value);
        
        if (node != end()) {
        // remove the node
        remove(node);
        }
    }

    std::ostream & operator<<(std::ostream & os, const LinkedList& list){
        for(auto x = list.begin(); x != list.end(); x->getNext()){
            os << *x << " ";
        }
        return os;
    }
}

