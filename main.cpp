#include <gmock/gmock.h>
using namespace ::testing;

#define RUN_TESTS

int main(int argc, char **argv) {

        #if defined RUN_TESTS
                InitGoogleMock(&argc, argv);
                return RUN_ALL_TESTS();
        #endif
        return 0;
}
