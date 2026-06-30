// abstraction_example.cpp
// Demonstrates Abstraction using an abstract class (interface-like) PaymentMethod

#include <iostream>
#include <string>
using namespace std;

// ---------------- Abstract Class ----------------
class PaymentMethod {
public:
    // Pure virtual function -> makes this class abstract.
    // Any derived class MUST implement this.
    virtual void pay(double amount) = 0;

    // Abstract classes can still have normal (non-pure) methods
    virtual void showMethodName() const {
        cout << "Generic Payment Method\n";
    }

    virtual ~PaymentMethod() {
        // virtual destructor for safe polymorphic cleanup
    }
};

// ---------------- Concrete Implementations ----------------

class CreditCardPayment : public PaymentMethod {
private:
    string cardNumber;

public:
    CreditCardPayment(string card) : cardNumber(card) {}

    // We MUST implement pay(), or this class would also become abstract
    void pay(double amount) override {
        cout << "Paid Rs." << amount << " using Credit Card ending in "
             << cardNumber.substr(cardNumber.size() - 4) << "\n";
        // Internally, this might involve complex steps: contacting the bank,
        // fraud checks, OTP verification, etc. The USER of this class doesn't
        // see any of that complexity - that's abstraction in action.
    }

    void showMethodName() const override {
        cout << "Payment Method: Credit Card\n";
    }
};

class UpiPayment : public PaymentMethod {
private:
    string upiId;

public:
    UpiPayment(string id) : upiId(id) {}

    void pay(double amount) override {
        cout << "Paid Rs." << amount << " using UPI ID: " << upiId << "\n";
        // Internally: QR generation, bank server communication, etc. - hidden.
    }

    void showMethodName() const override {
        cout << "Payment Method: UPI\n";
    }
};

// A function that works with ANY PaymentMethod - it doesn't care about the
// underlying implementation, only the abstract interface (pay()).
void processCheckout(PaymentMethod& method, double amount) {
    method.showMethodName();
    method.pay(amount);
    cout << "Checkout complete.\n\n";
}

int main() {
    // PaymentMethod method; // ERROR: cannot instantiate an abstract class

    CreditCardPayment cc("1234567890123456");
    UpiPayment upi("rahul@upi");

    cout << "----- Checkout #1 -----\n";
    processCheckout(cc, 2500.00);

    cout << "----- Checkout #2 -----\n";
    processCheckout(upi, 799.50);

    return 0;
}
