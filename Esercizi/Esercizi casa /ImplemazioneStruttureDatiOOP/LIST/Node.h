//
// Created by Luigi Domenico Castano on 19/04/24.
//

#ifndef NODE
#define NODE
#include "Data.h"

class Node {
public:
 Data data;
 Node *next;
 Node();
 Node(Data data, Node *next);
};


#endif
