#ifndef ARINC429_H
#define ARINC429_H

class Arinc429 final
{
public:
    Arinc429() = default;
    virtual ~Arinc429() = default;

    Arinc429(const Arinc429& iOther) = delete;
    Arinc429& operator=(const Arinc429& iOther) = delete;

    Arinc429(Arinc429&& iOther) = delete;
    Arinc429& operator=(Arinc429&& iOther) = delete;

    void decode();
};

#endif // ARINC429_H
