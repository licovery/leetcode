#ifndef N690_EMPLOYEE_INPORTANCE_H
#define N690_EMPLOYEE_INPORTANCE_H

#include <bits/stdc++.h>
using namespace std;

namespace n690
{

class Employee
{
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        map<int, Employee *> info;
        for (auto employee : employees)
        {
            info[employee->id] = employee;
        }
        if (info.find(id) == info.end())
        {
            return 0;
        }

        return dfs(id, info);
    }

    int dfs(int id, const map<int, Employee *> &info)
    {
        auto person = info.find(id)->second;
        int sum = person->importance;
        for (auto subId : person->subordinates)
        {
            sum += dfs(subId, info);
        }
        return sum;
    }
};

}

#endif // N690_EMPLOYEE_INPORTANCE_H
