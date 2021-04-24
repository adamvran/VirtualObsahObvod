#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
using namespace std;

class GeometrickyObjekt
{
public:
    virtual double obsah() = 0;
    virtual double obvod() = 0;
    virtual void print(ostream & os) const = 0;
};

class Ctverec : public GeometrickyObjekt
{
public:
    explicit Ctverec(double a) : m_a(a){}
    double obsah() override { return m_a*m_a; }
    double obvod() override { return 4*m_a; }
    void print(ostream & os) const override{ os << "Ctverec"; }
private:
    double m_a;
};

class Obdelnik : public GeometrickyObjekt
{
public:
    Obdelnik(double a, double b) : m_a(a), m_b(b){}
    double obsah() override { return m_a*m_b; }
    double obvod() override { return 2*(m_a+m_b); }
    void print(ostream & os) const override{ os << "Obdelnik"; }
private:
    double m_a;
    double m_b;
};

class Kruh : public GeometrickyObjekt
{
public:
    explicit Kruh(double r) : m_r(r){}
    double obsah() override { return M_PI*m_r*m_r; }
    double obvod() override { return 2*M_PI*m_r; }
    void print(ostream & os) const override{ os << "Kruh"; }
private:
    double m_r;
};

ostream & operator<<(ostream & os, const GeometrickyObjekt & objekt)
{
    objekt.print(os);
    return os;
}

int main()
{
    vector < unique_ptr<GeometrickyObjekt> > objekty;

    objekty.push_back(make_unique<Ctverec>(1));
    objekty.push_back(make_unique<Obdelnik>(2, 4));
    objekty.push_back(make_unique<Kruh>(3));

    for (const auto &objekt : objekty)
    {
        cout << *objekt << endl;
        cout << "Obsah je: ";
        cout << objekt->obsah() <<endl;
        cout << "Obvod je: ";
        cout << objekt->obvod() <<endl;
        cout << "-----------------------" << endl;
    }

    return 0;
}