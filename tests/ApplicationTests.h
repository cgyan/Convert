#include <gmock/gmock.h>
using namespace ::testing;
#include "Application.h"

TEST(ApplicationTests, ShouldThrowWhenUserProvidesLessThanFourArgs)
{
        EXPECT_THROW(
                Application(0, (const char * []) { }),
                CommandLineArgsException
        );
        EXPECT_THROW(
                Application(1, (const char * []) { "" }),
                CommandLineArgsException
        );
        EXPECT_THROW(
                Application(2, (const char * []) { "", "" }),
                CommandLineArgsException
        );
        EXPECT_THROW(
                Application(3, (const char * []) { "", "", "" }),
                CommandLineArgsException
        );
        EXPECT_THROW(
                Application(4, (const char * []) { "", "", "", "" }),
                CommandLineArgsException
        );
}

TEST(ApplicationTests, ShouldThrowWhenThirdUserArgIsNotKeywordTo)
{
        const char * argv[] = { "", "", "", "not_to", "" };
        const int argc = 5;
        EXPECT_THROW(Application cut(argc, argv), CommandLineArgsException);
}

TEST(ApplicationTests, ShouldReturnZeroWhenValueArgCannotBeConvertedToDouble)
{
        const char * argv[] = { "", "invalid_value", "", "to", "" };
        const int argc = 5;
        Application cut(argc, argv);
        EXPECT_THAT(cut.value(), Eq(0.0));
}

TEST(ApplicationTests, ShouldReturnDoubleEquivalentOfValueArg)
{
        const char * argv[] = { "", "123", "", "to", "" };
        const int argc = 5;
        Application cut(argc, argv);
        EXPECT_THAT(cut.value(), Eq(123));
}

TEST(ApplicationTests, ShouldReturnDoubleEquivalentOfValueArgThatContainsDecimal)
{
        const char * argv[] = { "", "3.14", "", "to", "" };
        const int argc = 5;
        Application cut(argc, argv);
        EXPECT_THAT(cut.value(), Eq(3.14));
}

TEST(ApplicationTests, ShouldReturnZeroWhenValueArgIsZero)
{
        const char * argv[] = { "", "0.0", "", "to", "" };
        const int argc = 5;
        Application cut(argc, argv);
        EXPECT_THAT(cut.value(), Eq(0.0));
}

TEST(ApplicationTests, ShouldReturnNullPointerWhenFirstTypeIsNotRecognized)
{
        const char * argv[] = { "", "", "invalid_type", "to", "" };
        const int argc = 5;
        Application cut(argc, argv);
        EXPECT_THAT(cut.converter(), Eq(nullptr));
}

TEST(ApplicationTests, ShouldReturnNullPointerWhenSecondTypeIsNotRecognized)
{
        const char * argv[] = { "", "", "", "to", "invalid_type" };
        const int argc = 5;
        Application cut(argc, argv);
        EXPECT_THAT(cut.converter(), Eq(nullptr));
}
