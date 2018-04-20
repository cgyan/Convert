#ifndef ABSTRACT_CONVERTER_H_
#define ABSTRACT_CONVERTER_H_

class AbstractConverter
{
public:
        virtual const double convert(const double value) const = 0;
};

#endif
