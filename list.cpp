#include <iostream>
#include "list.h"

namespace userList
{
    cList::cList(unsigned long n)
    {
        top = tail = now = nullptr;     //emptyList
        unsigned long i = 0UL;
        while(i < n && addItem())       //List N
        {
            ++i;
        }
    }
    //show list
    void cList::shwInfo()
    {
        int all = 0;
        for(now = top; now != nullptr; now = now->bnext)
        {
            shwItem(*now);
            ++all;
        }
        std::cout << "ITEM IN LIST: " << all << std::endl
                  << sizeof(*top) * all  << " bytes in memory" << std::endl;
    }
    //show item
    void cList::shwItem(Item & tmpItm) const
    {
        std::cout <<  "ADDR: " << &tmpItm << ": "
                  << tmpItm.vbox << std::endl;
    }
    //1 - good add, 0 - bad
    bool cList::addItem()
    {
        if(top == nullptr)              //add first
        {
            top = tail = now = new Item{0, nullptr};
        }
        else                            //add next
        {
            tail = tail->bnext = new Item{0, nullptr};
        }
        return tail != nullptr;
    }
    //empty?
    bool cList::isEmpty() const
    {
        return top == nullptr;
    }
    bool cList::isFull() const
    {
        return top != nullptr;
    }
    //user function
    void cList::visit(void (*pf)(Item &))
    {
        Item * last = nullptr;
        now = top;
        while(now != nullptr)
        {
            last = now;
            now = now->bnext;
            pf(*last);
        }
    }
    cList::~cList()
    {
        Item * last = nullptr;
        now = top;
        while(now != nullptr)
        {
            last = now;
            now = now->bnext;
            delete last;;
        }
    }
}

