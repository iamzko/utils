//#define CATCH_CONFIG_MAIN  // 当前宏强制Catch在当前编译单元中创建 main()，这个宏只能出现在一个CPP文件中，因为一个项目只能有一个有效的main函数
#include <iostream>
#include <functional>
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

int add (int a, int b)
{
    return a + b;
}
void add_a(int &a,int b)
{
    a = a+ b;
    return;
}


void bind_test()
{
    auto add1 = std::bind(add,1,std::placeholders::_1);
    std::cout << add1(3) << std::endl;
    int temp = 1000;
    auto add2 = std::bind(add_a,std::ref(temp),std::placeholders::_1);//bind预先绑定的参数需要传具体的变量或值进去，对于预先绑定的参数，是pass-by-value的。除非该参数被std::ref或者std::cref包装，才pass-by-reference。
    add2(24);
    std::cout << temp << std::endl;
    add_a(temp,24);
    std::cout << temp << std::endl;
}
void function_test()
{
    std::function<int(int,int)> add1 = add;
    std::cout <<  add1(3,4)<< std::endl;
}


#ifndef CATCH_CONFIG_MAIN
int main()
{
    std::cout << "Hello, World!" << std::endl;
//    std::cout << fib(1000) << std::endl;
    bind_test();
    function_test();
    return 0;
}
#else
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
#endif