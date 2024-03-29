// 9."Грошова сума".
// Дані класу: розмір суми, код валюти, курс щодо долара.
// Функції класу: порівняння двох сум, додавання двох сум, обчислення 
// значення суми у доларах.
#include <iostream>
#include <string>

using namespace std;

class Money {
private:
    int sum;             // Розмір суми
    string code;         // Код валюти
    double exchangeRateToDollar;  // Курс щодо долара

public:
    Money();
    Money(int, string, double);
    int GetSum() const;
    string GetCode() const;
    double GetExchangeRateToDollar() const;
    void SetSum(int);
    void SetCode(string);
    void SetExchangeRateToDollar(double);
    bool Equal(const Money&) const;
    void Print() const;
    void Compare(const Money&) const;
    void Input();
    void Add(const Money&);
    void ConvertToDollars() const;
};

Money::Money() {
    sum = 0;
    code = "";
    exchangeRateToDollar = 0.0;
}

Money::Money(int s, string c, double e) {
    sum = s;
    code = c;
    exchangeRateToDollar = e;
}

int Money::GetSum() const {
    return sum;
}

string Money::GetCode() const {
    return code;
}

double Money::GetExchangeRateToDollar() const {
    return exchangeRateToDollar;
}

void Money::SetSum(int s) {
    sum = s;
}

void Money::SetCode(string c) {
    code = c;
}

void Money::SetExchangeRateToDollar(double e) {
    exchangeRateToDollar = e;
}

bool Money::Equal(const Money& other) const {
    return (sum == other.sum) && (code == other.code) && (exchangeRateToDollar == other.exchangeRateToDollar);
}

void Money::Print() const {
    cout << "Sum: " << sum << endl;
    cout << "Currency code: " << code << endl;
    cout << "Exchange rate to dollar: " << exchangeRateToDollar << endl;
}

void Money::Compare(const Money& other) const {
    if (sum > other.sum) {
        cout << "The first money object has a larger sum." << endl;
    } else if (sum < other.sum) {
        cout << "The second money object has a larger sum." << endl;
    } else {
        cout << "The two money objects have equal sums." << endl;
    }
}

void Money::Add(const Money& other) {
    sum += other.sum;
}

void Money::ConvertToDollars() const {
    cout << "Sum in dollars: " << sum * exchangeRateToDollar << endl;
}

void Money::Input() {
    cout << "Enter the sum: ";
    cin >> sum;
    cout << "Enter the currency code: ";
    cin >> code;
    cout << "Enter the exchange rate to dollar: ";
    cin >> exchangeRateToDollar;
}

int main() {
    Money money1, money2;

    cout << "Enter details for the first money object: " << endl;
    money1.Input();

    cout << endl << "Enter details for the second money object: " << endl;
    money2.Input();

    cout << endl << "Details of the first money object:" << endl;
    money1.Print();

    cout << endl << "Details of the second money object:" << endl;
    money2.Print();

    money1.Compare(money2);

    cout << endl << "Sum of the two money objects:" << endl;
    Money sum = money1;
    sum.Add(money2);
    sum.Print();

    cout << endl << "Sum of the two money objects in dollars:" << endl;
    sum.ConvertToDollars();

    return 0;
}
