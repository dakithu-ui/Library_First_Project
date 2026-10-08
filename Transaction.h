#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Book.h"

class Transaction {
private:
    int Transaction_id;
    int Book_id;
    int Customer_id;
    Book* Borrow_Book;
    bool isReturned;
public:
    void setid(const int& i);
    int getTransaction_id() const;
    Book* getBook() const;
    int getBook_id() const;
};

#endif // TRANSACTION_H
