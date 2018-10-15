//
//  main.cpp
//  palindrome
//
//  Created by Dinaol Melak on 12/9/17.
//  Copyright © 2017 Dinaol Melak. All rights reserved.
//  arrays

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

class Node{
    
private:
    char data;
    Node* nextNodePtr;
    Node* prevNodePtr;
    
public:
    Node(){}
    
    void setData(char d){
        data = d;
    }
    
    char getData(){
        return data;
    }
    
    void setNextNodePtr(Node* nodePtr){
        nextNodePtr = nodePtr;
    }
    
    Node* getNextNodePtr(){
        return nextNodePtr;
    }
    
    void setPrevNodePtr(Node* nodePtr){
        prevNodePtr = nodePtr;
    }
    
    Node* getPrevNodePtr(){
        return prevNodePtr;
    }
    
};

class List{
    
private:
    Node *headPtr;
    Node *tailPtr;
public:
    List(){
        headPtr = new Node();
        headPtr->setNextNodePtr(0);
        tailPtr = new Node();
        tailPtr->setPrevNodePtr(0);
    }
    
    Node* getHeadPtr(){
        return headPtr;
    }
    Node* getTailPtr(){
        return tailPtr;
    }
    bool isEmpty(){
        
        if (headPtr->getNextNodePtr() == 0)
            return true;
        
        return false;
    }
    
    
    void insert(char data){
        
        Node* currentNodePtr = headPtr->getNextNodePtr();
        Node* prevNodePtr = headPtr;
        Node* lastNodePtr = tailPtr;
        
        while (currentNodePtr != 0){
            prevNodePtr = currentNodePtr;
            currentNodePtr = currentNodePtr->getNextNodePtr();
        }
        
        Node* newNodePtr = new Node();
        newNodePtr->setData(data);
        newNodePtr->setNextNodePtr(0);
        prevNodePtr->setNextNodePtr(newNodePtr);
        if(prevNodePtr!=headPtr)
            newNodePtr->setPrevNodePtr(prevNodePtr);
        lastNodePtr->setPrevNodePtr(newNodePtr);
    }
    
    void insertAtIndex(int insertIndex, char data){
        
        Node* currentNodePtr = headPtr->getNextNodePtr();
        Node* prevNodePtr = headPtr;
        
        int index = 0;
        
        while (currentNodePtr != 0){
            
            if (index == insertIndex)
                break;
            
            prevNodePtr = currentNodePtr;
            currentNodePtr = currentNodePtr->getNextNodePtr();
            index++;
        }
        
        Node* newNodePtr = new Node();
        newNodePtr->setData(data);
        newNodePtr->setNextNodePtr(currentNodePtr);
        prevNodePtr->setNextNodePtr(newNodePtr);
        
    }
    
    
    char read(int readIndex){
        
        Node* currentNodePtr = headPtr->getNextNodePtr();
        Node* prevNodePtr = headPtr;
        int index = 0;
        
        while (currentNodePtr != 0){
            
            if (index == readIndex)
                return currentNodePtr->getData();
            
            prevNodePtr = currentNodePtr;
            currentNodePtr = currentNodePtr->getNextNodePtr();
            
            index++;
            
        }
        
        return '$'; // an invalid value indicating
        // index is out of range
        
    }
    
    void modifyElement(int modifyIndex, char data){
        
        Node* currentNodePtr = headPtr->getNextNodePtr();
        Node* prevNodePtr = headPtr;
        int index = 0;
        
        while (currentNodePtr != 0){
            
            if (index == modifyIndex){
                currentNodePtr->setData(data);
                return;
            }
            
            prevNodePtr = currentNodePtr;
            currentNodePtr = currentNodePtr->getNextNodePtr();
            
            index++;
        }
        
        
    }
    
    
    void deleteElement(int deleteIndex){
        
        Node* currentNodePtr = headPtr->getNextNodePtr();
        Node* prevNodePtr = headPtr;
        Node* nextNodePtr = headPtr;
        int index = 0;
        
        while (currentNodePtr != 0){
            
            if (index == deleteIndex){
                nextNodePtr = currentNodePtr->getNextNodePtr();
                break;
            }
            
            prevNodePtr = currentNodePtr;
            currentNodePtr = currentNodePtr->getNextNodePtr();
            
            index++;
        }
        
        prevNodePtr->setNextNodePtr(nextNodePtr);
        
    }
    
    
    void IterativePrint(){
        
        Node* currentNodePtr = headPtr->getNextNodePtr();
        
        while (currentNodePtr != 0){
            cout << currentNodePtr->getData() << " ";
            currentNodePtr = currentNodePtr->getNextNodePtr();
        }
        
        cout << endl;
        
    }
    void ReversePrint(){
        
        Node* currentNodePtr = tailPtr->getPrevNodePtr();
        
        while (currentNodePtr != 0){
            
            cout << currentNodePtr->getData() << " ";
            currentNodePtr = currentNodePtr->getPrevNodePtr();
        }
        
        cout << endl;
    }
    bool palindromeTest(){
        Node* currentNodePtr=headPtr->getNextNodePtr();
        Node* lastNodePtr=tailPtr->getPrevNodePtr();
        while (currentNodePtr!=0)
        {
            if(currentNodePtr->getData()==lastNodePtr->getData())
            {
                currentNodePtr=currentNodePtr->getNextNodePtr();
                lastNodePtr=lastNodePtr->getPrevNodePtr();
            }
            else if(currentNodePtr->getData()!=lastNodePtr->getData())
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    /*
     Algorithm
     - my first task would be to get a word from the user
     -place each word in a node of a doubly linked list
     - my next task would be to check whether it is palindrome by comparing elements from the beginning and end
     */
    string inputText;
    List palindromeList;
    cout<<"Palindrome!!!\n";
    cout<<"Please Enter something to see whether it is a Palindrome or not!\n";
    getline(cin,inputText);
    for (int i=0;i<inputText.length();i++)
    {
        palindromeList.insert(inputText[i]);
    }
    if (palindromeList.palindromeTest()==1)
    {
        cout<<"It a Palindrome!"<<endl;
    }
    else
    {
        cout<<"I'm sorry, it's not a Palindrome!"<<endl;
    }
    return 0;
}

