#ifndef N227_BASIC_CALCULATOR_II_H
#define N227_BASIC_CALCULATOR_II_H

#include "bits/stdc++.h"
using namespace std;

namespace n227
{

// 再没有括号的情况下，先计算完所有的乘除法，再算加减
class Solution
{
public:
    int calculate(string s)
    {
        int res = 0;

        istringstream in(s);
        int cur;
        char op;
        in >> cur;
        while (in >> op)
        {
            if (op == ' ')
            {
                continue;
            }
            else if (op == '+' || op == '-') //遇到一级运算符，第一个操作数可以直接加到结果中，第二个操作数继续参与运算
            {
                res += cur;
                in >> cur;
                if (op == '-') //减法变成加上相反数
                {
                    cur = -cur;
                }
            }
            else if (op == '*' || op == '/') //遇到二级运算符，先计算乘除法
            {
                int tmp;
                in >> tmp;
                if (op == '*')
                {
                    cur *= tmp;
                }
                else
                {
                    cur /= tmp;
                }
            }
        }
        res += cur;
        return res;
    }
};

}




#endif // N227_BASIC_CALCULATOR_II_H
