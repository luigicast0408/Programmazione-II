#include <iostream>
#include <string>

using namespace std;

class Fruit {
protected:
    string name;
    string color;
    string season;
public:
    Fruit() : name(""), color(""), season("") {}

    Fruit(string name, string color, string season) : name(name), color(color), season(season) {}

    string getName() {return name;}

    string getColor() {return color;}

    string getSeason() {return season;}

    virtual ~Fruit() {}

    virtual string getTaste() = 0; // pure virtual method
    void printFruit();
};

void Fruit::printFruit() {
    cout << "____FRUIT_____" << endl;
    cout << "NAME: " << name << endl;
    cout << "COLOR: " << color << endl;
    cout << "SEASON: " << season << endl;
    cout << "____FRUIT_____" << endl;
}

class Apple : public Fruit {
private:
    string taste;
public:
    Apple(string name, string color, string season, string taste) : Fruit(name, color, season), taste(taste) {}

    virtual ~Apple() {}
    string getTaste() {return taste;}
    void printApple();
};

void Apple::printApple() {
    Fruit::printFruit();
    cout << "TASTE: " << taste << endl;
}

class Orange : public Fruit {
private:
    string taste;
public:
    Orange(string name, string color, string season, string taste) : Fruit(name, color, season), taste(taste) {}

    virtual ~Orange() {}
    string getTaste() {return taste;}
    void printOrange();
};

void Orange::printOrange() {
    Fruit::printFruit();
    cout << "TASTE: " << taste << endl;
}

template<typename T>
class Node {
public:
    T data;
    Node *next;

    Node(T data, Node *next = nullptr) : data(data), next(next) {}

    T getData() const {return data;}
    Node *getNext() const {return next;}
};

template<typename T>
class Queue {
private:
    Node<T> *head;
    Node<T> *tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    ~Queue() {
        while (head != nullptr) {
            dequeue();
        }
    }

    void enqueue(const T &data) {
        Node<T> *newNode = new Node<T>(data);
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = tail;
        }
    }

    void dequeue() {
        if (head == nullptr) return;
        Node<T> *temp = head;
        head = head->getNext();
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
    }

    int removeFruits(string fruitType) {
        Node<T> *current = head;
        Node<T> *prev = nullptr;
        int count = 0;

        while (current != nullptr) {
            if (current->getData()->getName() == fruitType) {
                Node<T> *toDelete = current;
                if (prev == nullptr) {
                    // Removing head node
                    head = current->getNext();
                } else {
                    prev->next = current->getNext();
                }
                current = current->getNext();
                delete toDelete;
                count++;
            } else {
                prev = current;
                current = current->getNext();
            }
        }

        // Update tail pointer
        tail = prev;

        return count;
    }

    void printQueue() const {
        if (head != nullptr) {
            Node<T> *current = head;
            while (current != nullptr) {
                current->getData()->printFruit();
                current = current->getNext();
            }
        } else {
            cerr << "The queue is empty" << endl;
        }
    }
};

Orange *insertOrange() {
    string name, color, season, taste;
    cout << "____Insert orange_____" << endl;
    cout << "Insert name: ";
    cin >> name;
    cout << "Insert color: ";
    cin >> color;
    cout << "Insert season: ";
    cin >> season;
    cout << "Insert taste of orange: ";
    cin >> taste;
    cout << "____Insert orange_____" << endl;
    return new Orange(name, color, season, taste);
}

Apple *insertApple() {
    string name, color, season, taste;
    cout << "____Insert Apple_____" << endl;
    cout << "Insert name: ";
    cin >> name;
    cout << "Insert color: ";
    cin >> color;
    cout << "Insert season: ";
    cin >> season;
    cout << "Insert taste of apple: ";
    cin >> taste;
    cout << "____Insert apple_____" << endl;
    return new Apple(name, color, season, taste);
}

int main() {
    Queue<Fruit *> fruitQueue; // Queue of pointers to Fruit objects
    int choice;
    do {
        cout << "1) Insert an orange" << endl
             << "2) Insert an apple" << endl
             << "3) Delete fruit" << endl
             << "4) Print queue" << endl
             << "0) Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                Orange *orange = insertOrange();
                fruitQueue.enqueue(orange);
                break;
            }
            case 2: {
                Apple *apple = insertApple();
                fruitQueue.enqueue(apple);
                break;
            }
            case 3: {
                string fruitToDelete;
                cout << "Insert the type of fruit to delete: ";
                cin >> fruitToDelete;
                int removedCount = fruitQueue.removeFruits(fruitToDelete);
                cout << "Removed " << removedCount << " fruits from the queue." << endl;
                break;
            }
            case 4: {
                fruitQueue.printQueue();
                break;
            }
            case 0: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cerr << "Error!!! Invalid choice." << endl;
            }
        }
    } while (choice != 0);
    return 0;
}
