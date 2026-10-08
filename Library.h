#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>

#include "Book.h"
#include "Customer.h"
#include "Transaction.h"

class Library{
private:
    std::vector<Book*> List_Book;
    int Total_Book;
    std::vector<Customer*> List_Customer;
    int Total_Customer;
    std::vector<Transaction*> List_Transaction;
    int Total_Transaction;

public:
    Library();

    ~Library();

    void serialize();
    void deserialize();

    void Clear_Storage();

    std::vector<Book*> getList_Book() const;
    void addBook(Book* b);

    std::vector<Customer*> getList_Customer() const;
    void addCustomer(Customer* c);

    std::vector<Transaction*> getList_Transaction() const;
    void addTransaction(Transaction* t);

    std::vector<Book*> getbyName(const std::string& Name) const;
    std::vector<Book*> getbyAuthor(const std::string& Author) const;
    std::vector<Book*> getbyGenre(const Genre& Genre) const;
    std::vector<Book*> getbyRelease(const int& Year) const;
    Book* getbyId(const int& Id) const;

    void display(const std::vector<Book*>& List) const;
};

#endif // LIBRARY_H
