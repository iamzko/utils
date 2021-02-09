#define CATCH_CONFIG_MAIN  // 当前宏强制Catch在当前编译单元中创建 main()，这个宏只能出现在一个CPP文件中，因为一个项目只能有一个有效的main函数
#include <iostream>
#include "catch.hpp"
//斐波那契数列
auto fib(int n)
{
    if(n < 3 )
    {
        return 1;
    }
    else
    {
        return fib(n-1) + fib(n-2);
    }
}
//阶乘
auto factorial(int n)
{
    if(n == 0)
    {
        return (1);
    }
    else
    {
        return factorial(n -1) * n;
    }
}


//int main()
//{
//    std::cout << "Hello, World!" << std::endl;
//    std::cout << fib(1) << std::endl;
//    return 0;
//}

TEST_CASE( "fib are computed", "[fib]" )
{
    REQUIRE( fib(0) == 1 );
    REQUIRE( fib(1) == 1 );
    REQUIRE( fib(2) == 1 );
    REQUIRE( fib(3) == 2 );
    REQUIRE( fib(4) == 3 );
    REQUIRE( fib(5) == 5 );
    REQUIRE( fib(6) == 8 );
}
SCENARIO("factorial test","[factorial]")
{
    GIVEN("some n")
    {
        int n = 0;
        REQUIRE(factorial(n) == 1);
        WHEN("n is add by 1")
        {
            n += 1;
            THEN("the result change")
            {
                REQUIRE(factorial(n) == 1);
            }
        }
    }
    REQUIRE(factorial(3) == 6);


}
