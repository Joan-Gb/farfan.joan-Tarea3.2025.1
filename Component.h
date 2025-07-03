#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>

class Component {
public:
    virtual QString getName() const = 0;
    virtual ~Component() {}
};

#endif
