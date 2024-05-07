#include "Node.h"
template <typename T>
Node<T>::Node(Data<T> data, Node<T>* next) : data(data), next(next) {}
