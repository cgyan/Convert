#ifndef CELSIUS_TO_FAHRENHEIT_CONVERTER_H_
#define CELSIUS_TO_FAHRENHEIT_CONVERTER_H_

#include <gmock/gmock.h>
using namespace ::testing;
#include "AbstractConverter.h"

class CelsiusToFahrenheitConverter : public AbstractConverter
{
public:
        const double convert(const double celsius) const override
        {
                double ret = celsius * 1.8 + 32;
                return round(ret * 100) / 100; // round to 2 dec places;
        }
};

#endif
