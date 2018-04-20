#include <gmock/gmock.h>
using namespace ::testing;
#include <limits>

class CelsiusToFahrenheitConverter
{
public:
        const double convert(const double celsius)
        {
                double ret = celsius * 1.8 + 32;
                return round(ret * 100) / 100; // round to 2 dec places;
        }
};

class CelToFahTests : public Test
{
public:
        CelsiusToFahrenheitConverter cut;
};

TEST_F(CelToFahTests, ShouldReturnFah50WhenCelsiusIs10)
{
        double celsius = 10.0;
        double expectedFahrenheit = 50.0;
        EXPECT_THAT(cut.convert(celsius), DoubleEq(expectedFahrenheit));
}

TEST_F(CelToFahTests, ShouldReturnFah32WhenCelsiusIs0)
{
        double celsius = 0.0;
        double expectedFahrenheit = 32.0;
        EXPECT_THAT(cut.convert(celsius), DoubleEq(expectedFahrenheit));
}

TEST_F(CelToFahTests, ShouldReturnFahrenheitToOneDecimalPlaceOfCelsius3)
{
        double celsius = 3.0;
        double expectedFahrenheit = 37.4;
        EXPECT_THAT(cut.convert(celsius), DoubleEq(expectedFahrenheit));
}

TEST_F(CelToFahTests, ShouldReturnFahrenheitToTwoDecimalPlacesWhenCelsiusHasTwoDecimalPlaces)
{
        double celsius = 5.67;
        double expectedFahrenheit = 42.21;
        EXPECT_THAT(cut.convert(celsius), DoubleEq(expectedFahrenheit));
}
