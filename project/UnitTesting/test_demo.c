#include "unity.h"
#include "demo.h"

/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown()
{
}

void test_division(void)
{
    int n1 = 10, n2 = 20;
    TEST_ASSERT_EQUAL(0.5, division(n1, n2));
    
    TEST_ASSERT_EQUAL(2, division(n2, n1));

    TEST_ASSERT_EQUAL(2, division(n2, n1));
}

int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();
    /* Run Test functions */
    RUN_TEST(test_division);
    /* Close the Unity Test Framework */
    return UNITY_END();
}
