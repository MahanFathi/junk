#ifndef KIR_H_
#define KIR_H_

#include <iostream>
#include <vector>
#include <string>

class Kir
{
public:
    Kir(std::string dickName, double pG, double pL);
    ~Kir();

    float getVolume();
    void setPenises(std::vector<float> ps);
    std::vector<float> getPenises();
    std::string getName();
protected:
    std::string name;
    std::vector<float> penises;
    float penisGirth;
    float penisLength;
};

#endif // KIR_H_
