#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
	Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
	map<int, Node*> mp; //map the key to the node in the linked list
	int cp;  //capacity
	Node* tail; // double linked list tail pointer
	Node* head; // double linked list head pointer
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function

};
class LRUCache : public Cache
{
public:
	LRUCache(int capacity)
	{
		this->cp = capacity;
	}
	void set(int key, int value)
	{
		if (mp.find(key) != mp.end()) // existing
		{
			map<int, Node*>::iterator it = mp.begin();
			Node* currentHead = head;
			while (it != mp.end())
			{
				Node* currentNode = (*it).second;
				if (currentNode->value == value)
				{
					if (currentNode == currentHead) // already in head
						return;
					Node* prevNode = currentNode->prev;
					Node* nextNode = currentNode->next;
					prevNode->next = nextNode;
					currentHead->prev = currentNode;
					currentNode->prev = NULL;
					currentNode->next = head;
					head = currentNode;
					if (nextNode != NULL) // node isn't tail
						nextNode->prev = prevNode;
					else
						tail = prevNode;
					
					return;
				}
				it++;
			}
		}
		else // new entry
		{
			Node* prevHead = head;
			Node* newHead = new Node(NULL, prevHead, key, value);
			mp.insert(std::pair<int, Node*>{ key, newHead });
			if (prevHead == NULL)
			{
				head = newHead;
				tail = newHead;
				return;
			}
			prevHead->prev = newHead;
			head = newHead;
			if (mp.size() > cp)
			{
				mp.erase(tail->key);
				tail = tail->prev;
				tail->next = NULL;
			}
		}
	}
	int get(int key)
	{
		if (mp.find(key) != mp.end())
		{
			set(key, mp[key]->value);
			return mp[key]->value;
		}
		return -1;
	}
};

class LRUCacheMp : public Cache
{
private:
	int index;
	int deleteIndex;
	int findInCache(int key)
	{
		std::map<int, Node*>::iterator it = mp.begin();
		while(it != mp.end())
		{
			if ((*it).second->key == key)
				return (*it).first;
			it++;
		}
		return -1;
	}
public:
	LRUCacheMp(int capacity)
	{
		index = 0;
		deleteIndex = 0;
		this->cp = capacity;
	}
	void set(int key, int value)
	{
		int findedIndex = findInCache(key);
		if (findedIndex != -1) // existing
		{
			std::map<int, Node*>::iterator it = mp.end();
			it--;
			Node* newNode = new Node(key, value);
			for (int i = findedIndex; i < (*it).first; i++)
			{
				mp[i] = mp[i + 1];
			}
			mp[(*it).first] = newNode;
		}
		else // new entry
		{
			Node* newNode = new Node(key, value);
			mp[index++] = newNode;
			if (mp.size() > cp)
			{
				mp.erase(deleteIndex++);
			}
		}
	}
	int get(int key)
	{
		int findedIndex = findInCache(key);
		if (findedIndex != -1)
		{
			int retVal = mp[findedIndex]->value;
			set(key, mp[findedIndex]->value);
			return retVal;
		}
		return -1;
	}
};
