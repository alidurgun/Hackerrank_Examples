#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Nodes
{
    string nodeName;
    vector<string> attributes;
    vector<Nodes*> nextNodes;
    Nodes* previousNode;
    bool completed = false;
};

void getValue(string input, vector<Nodes*> allNodes)
{
    bool validTag = false;
    bool set = false;
    bool nested = false;
    string nodeName;
    string mainNodeName;
    vector<Nodes*> nextNodes;
    if (input.find('.') != std::string::npos) // seperate by dots for the nested tags.
    {
        size_t dotIndex = input.find('.');
        mainNodeName = input.substr(0, dotIndex);
        input = input.substr(dotIndex + 1);
        vector<Nodes*>::iterator iter;
        for (iter = allNodes.begin(); iter != allNodes.end(); iter++)
        {
            if ((*iter)->nodeName.compare(mainNodeName) == 0)
            {
                if ((*iter)->completed && (*iter)->previousNode == nullptr) // if it's valid tag for the query.
                {
                    nextNodes = (*iter)->nextNodes; // go through it's sub tags.
                    break;
                }
            }
        }
        if (nextNodes.empty()) // main tag does not have the specified tagname in it's sub tags.
        {
            cout << "Not Found!" << endl;
            return;
        }

        while (input.find('.') != std::string::npos) // seperate by dots now in the loop
        {
            if (nextNodes.empty())
            {
                cout << "Not Found!" << endl;
                return;
            }
            size_t dotIndex = input.find('.');
            nodeName = input.substr(0, dotIndex);
            input = input.substr(dotIndex + 1);
            vector<Nodes*>::iterator subiter;
            for (subiter = nextNodes.begin(); subiter != nextNodes.end(); subiter++)
            {
                if ((*subiter)->nodeName.compare(nodeName) == 0)
                {
                    if ((*subiter)->completed)
                    {
                        nextNodes = (*subiter)->nextNodes; // will be go through next nodes of the current tag.
                        break;
                    }
                    else
                    {
                        cout << "Not Found!" << endl;
                        return;
                    }
                }
            }
        }
    }
    // subtag tag query
    if (!nextNodes.empty()) // it does not have anymore '.' so we can proceed.
    {
        size_t queryIndex = input.find('~');
        nodeName = input.substr(0, queryIndex);
        string attributeName = input.substr(queryIndex + 1);
        vector<Nodes*>::iterator iter;
        vector<string>::iterator attributeIter;
        for (iter = nextNodes.begin(); iter != nextNodes.end(); iter++)
        {
            if ((*iter)->nodeName.compare(nodeName) == 0)
            {
                if ((*iter)->completed)
                {
                    for (attributeIter = (*iter)->attributes.begin(); attributeIter != (*iter)->attributes.end(); attributeIter++)
                    {
                        if ((*attributeIter).compare(attributeName) == 0)
                        {
                            attributeIter++; // in the vector first value is attribute name
                            cout << *attributeIter << endl; // in the vector second value is attribute value
                            return;
                        }
                    }
                }
                break;
            }
        }

        cout << "Not Found!" << endl;
        return;
    }
    // main tag query
    size_t queryIndex = input.find('~');
    nodeName = input.substr(0, queryIndex);
    string attributeName = input.substr(queryIndex + 1);

    vector<Nodes*>::iterator iter;
    for (iter = allNodes.begin(); iter != allNodes.end(); iter++)
    {
        if ((*iter)->nodeName.compare(nodeName) == 0)
        {
            if ((*iter)->completed && (*iter)->previousNode == nullptr)
            {
                vector<string>::iterator attributeIter;
                for (attributeIter = (*iter)->attributes.begin(); attributeIter != (*iter)->attributes.end(); attributeIter++)
                {
                    if ((*attributeIter).compare(attributeName) == 0)
                    {
                        attributeIter++;
                        cout << *attributeIter << endl;
                        return;
                    }
                }
            }
            break;
        }
    }
    cout << "Not Found!" << endl;
}

int main(void)
{
    int n, q;
    std::cin >> n >> q;
    vector<Nodes*> allNodes;
    string input;
    string tagName;
    Nodes* previousNode = nullptr;
    Nodes* currentNode = new Nodes;
    do
    {
        getline(cin, input);
        if (input.compare("") == 0) // to ignore first empty input
            continue;
        if (input.find('/') == std::string::npos) // it's not ending tag.
        {
            size_t seperateIndex = input.find(' ');
            if (input.find('\"') == std::string::npos) // doesn't have attribute.
            {
                seperateIndex = input.find('>');
                tagName = input.substr(1, seperateIndex - 1);
                currentNode->nodeName = tagName;
            }
            else
            { // it has attribute or attributes.
                tagName = input.substr(1, seperateIndex - 1);
                currentNode->nodeName = tagName;
                input = input.substr(seperateIndex);

                while (input.find(' ') != std::string::npos)
                {
                    size_t spaceIndex = input.find(' ');
                    input.erase(spaceIndex, 1); // get rid of spaces.
                }
                while (input.find('\"') != std::string::npos) // get all atributes.
                {
                    seperateIndex = input.find('=');
                    string attributeName = input.substr(0, seperateIndex);
                    input = input.substr(seperateIndex + 2);
                    seperateIndex = input.find('\"');
                    string attributeValue = input.substr(0, seperateIndex);
                    input = input.substr(seperateIndex + 1);

                    currentNode->attributes.push_back(attributeName);
                    currentNode->attributes.push_back(attributeValue);
                }
            }
            currentNode->previousNode = previousNode; // this tag is subtag of previous tag. NULL for main tags.
            if (previousNode != nullptr)
            {
                if (!previousNode->completed)
                {
                    previousNode->nextNodes.push_back(currentNode); // previous tag has this tag in it's subset.
                }
            }
            allNodes.push_back(currentNode); // add this tag to our all tag vector pool.
            previousNode = currentNode; // this tag will be now previous tag for the incoming tag.
            currentNode = new Nodes;
        }
        else // ending tag.
        {
            tagName = input.substr(2, input.length() - 3);
            vector<Nodes*>::iterator iter;
            for (iter = allNodes.begin(); iter != allNodes.end(); iter++)
            {
                if ((*iter)->nodeName.compare(tagName) != 0)
                    continue;
                else
                {
                    (*iter)->completed = true; // if this tagname is inside of the vector.
                    previousNode = (*iter)->previousNode; // previous tag should be prev tag of the closing tag.
                    break;
                }
            }
        }
        n--;
    } while (n > 0);

    for (int i = 0; i < q; i++)
    {
        getline(cin, input);
        getValue(input, allNodes);
    }

    vector<Nodes*>::iterator iter;
    for (iter = allNodes.begin(); iter != allNodes.end(); iter++)
    {
        delete* iter; // free the allocated memory field.
    }

    delete currentNode; // free the allocated memory field.
    return 0;
}
