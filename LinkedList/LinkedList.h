#include <iostream>
#include "Node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename type>
class LinkedList {
    private:
        Node<type> *head;
        Node<type> *rear;
        int length;

        // helper function to reduce code in removals
        void oneItemLeft() {
            head->next = nullptr; // make sure the link to the next node is null
            delete head; // delete the only node
            head = nullptr; // set head to null.
            rear = nullptr; // set rear to null.
            length--; // decrement length.
            return;
        }

        // helper function to reduce code in inserts
        void firstInsert(type data) {
            head = new Node<type>; // create new node
            head->data = data; // set data for new node
            head->next = nullptr; // set next pointer for new node
            rear = head; // set rear
            length++; // increment length
        }
    public:
        LinkedList(): head(nullptr), rear(nullptr), length(0){};

        ~LinkedList() {
            Node<type> *temp;
            while (head != nullptr) {
                temp = head->next;
                delete head;
                head = temp;
            }
            head = nullptr;
            rear = nullptr;
            temp = nullptr;
            length = 0;
        }
        int getLength() { return length; }

        void insert(type data) {
            if (isEmpty()) 
                firstInsert(data);
            else {
                Node<type> *current = head;
                while (current->next != nullptr)
                    current = current->next; // will loop until the pointer to the next item is null (stops on last item);
                current->next = new Node<type>; // adds node after current
                current = current->next; // moves to new node
                current->data = data; // adds data to node
                current->next = nullptr; 
                rear = current; // makes the new node the new rear
                length++; // increments the length
            }
        }

        void remove() { // removes the last item
            // std::cout << "In remove" << std::endl; // debug print
            if (isEmpty()) 
                std::cout << "ERROR: Cannot remove, list is empty." << std::endl;
            else if (length == 1) 
                oneItemLeft();
            else {
                Node<type> *current = head;
                while (current->next != rear) // will continue until the next pointer is not the last in the list 
                    current = current->next;

                // std::cout << "Node before rear: " << current->data << std::endl; // debug method
                delete current->next; // delete the last node
                current->next = nullptr; // set the pointer to the next node as null
                rear = current; // set current as rear
                length--; // update length
                if (length == 1) head = rear; // since we're removing from rear, update head here not rear.
            }
        }

        void removeFront() { // deletes the front item.
            std::cout << "In removeFront" << std::endl; // debug print
            if (isEmpty()) 
                std::cout << "ERROR: Cannot remove, list is empty." << std::endl;
            else if (length == 1) // if only one item left
                oneItemLeft(); // helper function to repeat less code.
            else {
                std::cout << "To remove: " << head->data << std::endl;
                Node<type> *temp = head->next; // set to next node
                delete head; // delete head
                head = temp; // set head to next node
                std::cout << "New head: " << head->data << std::endl;
                length--; // decrement length
                if (length == 1) rear = head; // if only one node left, set rear to head.
            }
        }
        void print() {
            if (isEmpty()) {
                std::cout << "List is empty" << std::endl; 
                return;
            }

            Node<type> *current = head;
            while (current != nullptr) {
                std::cout << current->data << std::endl;
                current = current->next;
            }
        }

        bool isEmpty() { return length == 0; };
};

#endif