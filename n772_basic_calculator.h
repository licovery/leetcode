#ifndef N772_BASIC_CALCULATOR_H
#define N772_BASIC_CALCULATOR_H

#include "bits/stdc++.h"
using namespace std;


namespace n772
{

// 使用递归来处理括号
class Solution
{
public:
    int calculate(string s)
    {
        string expr;
        // 去除多余空格
        for (char c : s)
        {
            if (c != ' ')
            {
                expr += c;
            }
        }
        istringstream in(expr);
        return calculate(in);
    }

    //遇到左括号，
    int calculate(istringstream &in)
    {

        long long res = 0;

        long long cur;  //第一个操作数
        long long tmp;  //第二个操作数
        char op;        //操作符

        // 第一个字符不是左括号就是数字

        // 获取第一个操作数
        // 查看下一个字符，如果是左括号，递归计算整个括号表达式的值，然后把计算结果作为一个操作数
        if (in.peek() == '(')
        {
            in.ignore();
            cur = calculate(in); //遇到左括号开始递归
        }
        else
        {
            in >> cur;
        }

        // 先取操作符，再取出第二个操作数
        while (in >> op)
        {
            if (op == ')')
            {
                break; //遇到右括号退出递归
            }

            // 获取第二个操作数，方式和获取第一个操作数完全一样
            if (in.peek() == '(')
            {
                in.ignore();
                tmp = calculate(in);
            }
            else
            {
                in >> tmp;
            }

            // 根据运算符开始处理
            switch (op)
            {
                case '-':
                {
                    tmp = -tmp;
                }
                //此处不break;
                case '+':
                {
                    res += cur;
                    cur = tmp;
                    break;
                }
                case '*':
                {
                    cur *= tmp;
                    break;
                }
                case '/':
                {
                    cur /= tmp;
                    break;
                }
            }
        }
        res += cur;
        return static_cast<int>(res);
    }
};

//使用栈来解决
class SolutionStatk
{
public:
    int calculate(string s)
    {
        string expr;
        for (char c : s)
        {
            if (c != ' ')
            {
                expr += c;
            }
        }
        istringstream in(expr);
        stack<long long> number;
        stack<char> optr;

        int status = ParseNumber; //当前匹配的状态，数字和运算符交替出现

        while (1)
        {
            char op = in.peek();
            if (op == EOF)
            {
                break;
            }
            else if (op == '(') //左括号期待下次匹配到数字
            {
                in >> op;
                optr.push(op);
                status = ParseNumber;
                continue;
            }
            if (op == ')') //右括号期待下次匹配到运算符
            {
                in.ignore();
                while (!optr.empty() && optr.top() != '(')
                {
                    calc(number, optr);
                }
                optr.pop();
                status = ParseOpertator;
                continue;
            }

            if (status == ParseNumber)
            {
                long long n;
                in >> n;
                number.push(n);
                status = ParseOpertator;
            }
            else if (status == ParseOpertator) // + - * /
            {
                in >> op;
                // 当前运算符优先级小于等于栈顶运算符，优先处理栈顶运算符
                // 依次出栈直到当前运算符优先级大于栈顶运算符或者栈空
                while (!optr.empty() && priority(op) <= priority(optr.top()))
                {
                    calc(number, optr);
                }
                optr.push(op);
                status = ParseNumber;
            }
        }

        while (!optr.empty())
        {
            calc(number, optr);
        }

        return static_cast<int>(number.top());
    }
private:
    static constexpr int ParseNumber = 0;
    static constexpr int ParseOpertator = 1;

    int priority(char op)
    {
        if (op == '(') return 0;
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return -1;
    }

    void calc(stack<long long> &number, stack<char> &optr)
    {

        auto op = optr.top();
        optr.pop();

        auto n2 = number.top();
        number.pop();

        auto n1 = number.top();
        number.pop();

        switch (op)
        {
            case '+':
            {
                number.push(n1 + n2);
                break;
            }
            case '-':
            {
                number.push(n1 - n2);
                break;
            }
            case '*':
            {
                number.push(n1 * n2);
                break;
            }
            case '/':
            {
                number.push(n1 / n2);
                break;
            }
        }
    }
};

}

#endif // N772_BASIC_CALCULATOR_H
