#include <iostream>
#include <numeric>

using namespace std;

class Rational {
public:
    Rational() = default;

    Rational(int numerator)
            : numerator_(numerator), denominator_(1) {
    }

    Rational(int numerator, int denominator)
            : numerator_(numerator), denominator_(denominator) {
        if(denominator == 0){
            throw domain_error("Denominator is zero");
        }
        Normalize();
    }

    int Numerator() const {
        return numerator_;
    }

    int Denominator() const {
        return denominator_;
    }

    Rational &operator+=(const Rational &r) {
        numerator_ = numerator_ * r.Denominator() + r.Numerator() * denominator_;
        denominator_ *= r.Denominator();

        Normalize();
        return *this;
    }

    Rational &operator-=(const Rational &r) {
        numerator_ = numerator_ * r.Denominator() - r.Numerator() * denominator_;
        denominator_ *= r.Denominator();

        Normalize();
        return *this;
    }

    Rational &operator*=(const Rational &r) {
        numerator_ *= r.Numerator();
        denominator_ *= r.Denominator();

        Normalize();
        return *this;
    }

    Rational &operator/=(const Rational &r) {
        numerator_ *= r.Denominator();
        denominator_ *= r.Numerator();

        this->Normalize();
        return *this;
    }


private:
    void Normalize() {
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        const int divisor = gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }

    int numerator_ = 0;
    int denominator_ = 1;
};


ostream &operator<<(ostream &out, const Rational &r) {

    out << "("s << r.Numerator() << ", " << r.Denominator() << ")"s;
    return out;
}

istream &operator>>(istream &input, Rational &r) {

    int x, y;

    char comma;
    input >> x >> comma >> y;

    r = Rational(x, y);

    return input;
}

Rational operator+(Rational left, const Rational right) {
    return left += right;
}

Rational operator-(Rational left, const Rational &right) {

    return left -= right;
}

Rational operator*(Rational left, const Rational &right) {

    return left *= right;
}

Rational operator/(Rational left, const Rational &right) {

    return left /= right;
}

Rational operator+(const Rational &r) {
    return r;
}

Rational operator-(const Rational &r) {
    return {-r.Numerator(), r.Denominator()};
}

bool operator==(const Rational &left, const Rational &right) {
    return left.Numerator() == right.Numerator() &&
           left.Denominator() == right.Denominator();
}

bool operator!=(const Rational &left, const Rational &right) {
    return !(left == right);
}

bool operator<(const Rational &left, const Rational &right) {
    return (left.Numerator() * right.Denominator()) < (right.Numerator() * left.Denominator());
}

bool operator>(const Rational &left, const Rational &right) {
    return (left.Numerator() * right.Denominator()) > (right.Numerator() * left.Denominator());
}

bool operator<=(const Rational &left, const Rational &right) {
    return (left < right) || (left == right);
}

bool operator>=(const Rational &left, const Rational &right) {
    return !(left <= right);
}

int main() {
    Rational r1{1, 6};
    Rational r2{1, 3};

    Rational sum = (r1 + r2);//* r1;
    Rational sum2 = (r1 + Rational(2));//* r1;
    cout << sum << endl; // Выведет 1/12
    cout << sum2 << endl; // Выведет 1/12

    try {
        // При попытке сконструировать дробь с нулевым знаменателем
        // должно выброситься исключение domain_error
        const Rational invalid_value{1, 0};
        // Следующая строка не должна выполниться
        cout << invalid_value << endl;
    } catch (const domain_error& e) {
        cout << "My error: "s << e.what() << endl;
    }

    return 0;
}