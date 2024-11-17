#include<iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Bill
{
    private:
    int billid;
    int patientid;
    double total_amount;
    vector<pair<string, double>> items;
    bool isPaid;

public:
     vector<pair<string, double>> items;
     void addItem(const string& itemName, double cost) {
        items.push_back({itemName, cost});
        total_amount += cost;

}

 int getBillId() const { return billid; }
    int getPatientId() const { return patientid; }
    double getTotalAmount() const { return total_amount; }
    bool getPaymentStatus() const { return isPaid; }

    void makePayment() { isPaid = true; }

};

class Payment {
private:
    int paymentId;
    int billId;
    double amountPaid;
    string paymentMethod;
    bool isSuccessful;

public:
    Payment(int id, int billId, double amount, const string& method)
        : paymentId(id), billId(billId), amountPaid(amount), paymentMethod(method), isSuccessful(false) {}

    bool processPayment() {
        isSuccessful = true;
        return isSuccessful;
    }

    int getPaymentId() const { return paymentId; }
    int getBillId() const { return billId; }
    bool getPaymentStatus() const { return isSuccessful; }
};

class InvoiceManager {
private:
    map<int, Bill> bills;
    vector<Payment> payments;

public:
    int generateBill(int patientId) {
        static int nextBillId = 1;
        bills[nextBillId] = Bill(nextBillId, patientId);
        return nextBillId++;
    }

    void addBillItem(int billId, const string& itemName, double cost) {
        if (bills.find(billId) != bills.end()) {
            bills[billId].addItem(itemName, cost);
        }
    }

    bool makePayment(int billId, double amount, const string& method) {
        static int nextPaymentId = 1;
        Payment payment(nextPaymentId++, billId, amount, method);
        if (payment.processPayment()) {
            payments.push_back(payment);
            bills[billId].makePayment();
            return true;
        }
        return false;
    }

    double getTotalAmount(int billId) const {
        auto it = bills.find(billId);
        return (it != bills.end()) ? it->second.getTotalAmount() : 0.0;
    }
};
