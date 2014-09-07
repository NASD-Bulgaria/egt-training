#include "Type.h"

Type::Type(int typeNumber, string name, int count) {
    setTypeNumber(typeNumber);
    setName(name);
    setCounter(count);

}

int Type::getTypeNumber() const
{
    return typeNumber;
}

int Type::getCounter() const
{
    return counter;
}

string Type::getName() const
{
    return name;
}

void Type::setCounter(int counter)
{
    this->counter = counter;
}

void Type::setTypeNumber(int typeNumber)
{
    this->typeNumber = typeNumber;
}

void Type::setName(string name)
{
    const char *nameValue = name.data();
    int length = name.size();
    length = ( length < 10 ? length : 9 );
    strncpy( this->name, nameValue, length );
    this->name[ length ] = '\0';
}

Type::~Type() {
    // TODO Auto-generated destructor stub
}

