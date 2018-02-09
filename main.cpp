//linked list(studentProject)

#include <iostream>
#include "list.h"

const int ELEM = 4;

void incItem(userList::Item & tmp);
void decItem(userList::Item & tmp);

int main()
{
    {
        std::cout << "TEST LIST" << std::endl;
        userList::cList one(ELEM);
        one.shwInfo();
        std::cout << "AFTER INC" << std::endl;
        one.visit(incItem);
        one.shwInfo();
        std::cout << "AFTER ADD ITEM" << std::endl;
        one.addItem();
        one.shwInfo();
        std::cout << "AFTER DEC" << std::endl;
        one.visit(decItem);
        one.shwInfo();
    }
    std::cin.get();
    return 0;
}
void incItem(userList::Item & tmp)
{
    tmp.vbox += 1.0;
}
void decItem(userList::Item & tmp)
{
    tmp.vbox -= 1.0;
}

