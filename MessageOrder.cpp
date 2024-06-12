#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
public:
    Message() {}
    Message(std::string message, int number) {
        this->message = message;
        this->number = number;
    }
    const string& get_text() {
        return this->message;
    }
    bool operator< (Message& M1)
    {
        if (this->number < M1.number)
            return true;
        return false;
    }
private:
    std::string message;
    int number;
};

class MessageFactory {
public:
    MessageFactory() {
        numOfMessages = 0;
    }
    Message create_message(const string& text) {
        numOfMessages++;
        return Message(text, numOfMessages);
    }
private:
    int numOfMessages;
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        //simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};
