#ifndef N299_BULLS_AND_COWS_H
#define N299_BULLS_AND_COWS_H

#include "bits/stdc++.h"
using namespace std;

namespace n299
{

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bull = 0;
        int cow = 0;
        int sHt[DIGHTSIZE] = {0};
        int gHt[DIGHTSIZE] = {0};
        for (int i = 0; i < secret.size() && i < guess.size(); i++)
        {
            if (secret[i] == guess[i]) bull++;

            sHt[secret[i] - '0']++;
            gHt[guess[i] - '0']++;
        }
        for (int i = 0; i < DIGHTSIZE; i++)
        {
            cow += min(gHt[i], sHt[i]);
        }
        cow -= bull;

        return to_string(bull) + "A" + to_string(cow) + "B";
    }

private:
    static constexpr int DIGHTSIZE = 10;
};

}

#endif // N299_BULLS_AND_COWS_H
