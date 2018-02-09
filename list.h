#ifndef EX8_H_INCLUDED
#define EX8_H_INCLUDED

namespace userList
{
    typedef struct Box
    {
        double vbox;
        Box * bnext;
    }Item;

    class cList
    {
        private:
            Item iList;
            Item * top;     
            Item * now;     
            Item * tail;    
            void shwItem(Item & tmpItm) const;
        public:
            cList(unsigned long n = 0UL);
            void shwInfo();
            bool addItem();
            bool isEmpty() const;
            bool isFull() const;
            void visit(void (*pf)(Item &));
            ~cList();
    };
}

#endif // EX8_H_INCLUDED

