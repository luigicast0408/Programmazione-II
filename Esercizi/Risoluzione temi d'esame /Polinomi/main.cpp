#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Node {
private:
    T value;
    Node<T> *next;
public:
    Node(T value, Node<T> *next) : value(value), next(next) {}

    T getValue() { return value; }

    Node<T> *getNext() { return next; }

    void setValue(T value) { this->value = value; }

    void setNext(Node<T> *next) { this->next = next; }
};

template<typename T>
class List {
public:
    Node<T> *head;

    List() : head(nullptr) {}

    void addNode(T data);

    bool deleteNode(T data);

    void printList();

    bool isEmpty() { return head == nullptr; }
};

template<typename T>
void List<T>::addNode(T data) {
    Node<T> *newNode = new Node<T>(data, nullptr);
    if (isEmpty()) {
        head = newNode;
    } else {
        Node<T> *prev = nullptr;
        Node<T> *current = head;
        while (current != nullptr && current->getValue() < newNode->getValue()) {
            prev = current;
            current = current->getNext();
        }
        if (prev == nullptr) {
            newNode->setNext(head);
            head = newNode;
        } else {
            prev->setNext(newNode);
            newNode->setNext(current);
        }
    }
}

template<typename T>
void List<T>::printList() {
    Node<T> *current = head;
    while (current != nullptr) {
        cout << current->getValue() << " ";
        current = current->getNext();
    }
    cout << endl;
}

class Monomial {
private:
    char sign;
    int index;
    char letter;
    int degree;
public:
    Monomial() : sign('+'), index(0), letter(' '), degree(0) {}

    Monomial(char sign, int index, char letter, int degree)
            : sign(sign), index(index), letter(letter), degree(degree) {}

    char getSign() const { return sign; }

    void setSign(char sign) { this->sign = sign; }

    int getIndex() const { return index; }

    void setIndex(int index) { this->index = index; }

    char getLetter() const { return letter; }

    void setLetter(char letter) { this->letter = letter; }

    int getDegree() const { return degree; }

    void setDegree(int degree) { this->degree = degree; }

    string printMonomial() const {
        if (degree == 0 && letter == ' ') {
            return string(1, sign) + to_string(index);
        }
        if (degree == 0) {
            return string(1, sign) + to_string(index) + letter;
        }
        return string(1, sign) + to_string(index) + letter + "^" + to_string(degree);
    }

    friend ostream &operator<<(ostream &out, const Monomial &m) {
        return out << m.printMonomial();
    }

    bool operator<(const Monomial &other) const {
        return degree > other.degree;
    }

    void combine(const Monomial &other) {
        if (this->degree != other.degree || this->letter != other.letter) {
            return; // Can only combine monomials with the same degree and letter
        }

        int combinedIndex = (this->sign == '+' ? this->index : -this->index) +
                            (other.sign == '+' ? other.index : -other.index);

        if (combinedIndex < 0) {
            this->sign = '-';
            this->index = -combinedIndex;
        } else {
            this->sign = '+';
            this->index = combinedIndex;
        }
    }
};

class Polynomial {
public:
    List<Monomial> *polynomialList;

    Polynomial() { polynomialList = new List<Monomial>(); }

    ~Polynomial() { delete polynomialList; }

    void addMonomial(const Monomial &m) { polynomialList->addNode(m); }

    void printPolynomial() { polynomialList->printList(); }

    Polynomial sumPolynomial(const Polynomial &p1, const Polynomial &p2);
};

Polynomial Polynomial::sumPolynomial(const Polynomial &p1, const Polynomial &p2) {
    Polynomial result;

    Node<Monomial> *currentP1 = p1.polynomialList->head;
    Node<Monomial> *currentP2 = p2.polynomialList->head;

    while (currentP1 != nullptr && currentP2 != nullptr) {
        if (currentP1->getValue().getDegree() == currentP2->getValue().getDegree()){
            Monomial combined = currentP1->getValue();
            combined.combine(currentP2->getValue());
            result.addMonomial(combined);

            currentP1 = currentP1->getNext();
            currentP2 = currentP2->getNext();
        } else if (currentP1->getValue() < currentP2->getValue()) {
            result.addMonomial(currentP1->getValue());
            currentP1 = currentP1->getNext();
        } else {
            result.addMonomial(currentP2->getValue());
            currentP2 = currentP2->getNext();
        }
    }

    while (currentP1 != nullptr) {
        result.addMonomial(currentP1->getValue());
        currentP1 = currentP1->getNext();
    }

    while (currentP2 != nullptr) {
        result.addMonomial(currentP2->getValue());
        currentP2 = currentP2->getNext();
    }

    return result;
}

int main() {
    Polynomial poly1;
    poly1.addMonomial(Monomial('+', 3, 'x', 2));
    poly1.addMonomial(Monomial('-', 1, 'x', 1));
    poly1.addMonomial(Monomial('-', 1, ' ', 0));

    Polynomial poly2;
    poly2.addMonomial(Monomial('+', 2, 'x', 2));
    poly2.addMonomial(Monomial('+', 1, 'x', 1));
    poly2.addMonomial(Monomial('+', 1, ' ', 0));

    Polynomial result = result.sumPolynomial(poly1, poly2);

    cout << "Polynomial 1: ";
    poly1.printPolynomial();

    cout << "Polynomial 2: ";
    poly2.printPolynomial();

    cout << "Sum: ";
    result.printPolynomial();

    return 0;
}
