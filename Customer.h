#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Transaction.h"

#include <string>
#include <vector>


class Customer{
private:
    int Customer_id;
    std::string Name;
    double Account_Balance;
    std::vector<Transaction*> Transaction_History;
public:
    int getid() const;
    std::string getName() const;
    std::vector<Transaction*> getTransaction_History() const;

    void setid(const int& i);
};

#endif // CUSTOMER_H
