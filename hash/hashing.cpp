#include <bits/stdc++.h>

using namespace std;

class Hashing
{
public:
    vector<long long> prefixHash;
    vector<long long> power;
    long long m = 1e9 + 9; // 1/m = proba te3 colison donc win akber win 5ir
    long long p = 10;      // p should be the closet prime number to the size of the alphabet used ! ( in this case only lowerCase 26 ->31)
    Hashing(string s)
    {
        this->prefixHash.resize(s.size());
        this->power.resize(s.size());
        prefixHash[0] = s[0] - 'a' + 1; // bech nabdew min 1 not 0
        power[0] = 1;
        for (int i = 1; i < s.size(); i++)
        {
            power[i] = (power[i - 1] * p) % m;                                           // calculating the power of p everytime
            prefixHash[i] = (prefixHash[i - 1] + ((s[i] - 'a' + 1) * power[i]) % m) % m; // hash(s)=s[0]+s[1]*p+s[2]*p^2+...+s[n-1]*p^(n-1)
        }
    }
    long long getHash(int i, int j) // mil -> INDICE <- i to j
    {
        if (i == 0)
            return prefixHash[j];
        return ((prefixHash[j] - prefixHash[i - 1]) / power[i]);
    }
};

int main()
{
    Hashing h("ab");
    Hashing h1("abxabxabxab");
    cout <<"target hash := " <<h.getHash(0, 1) << endl;
    cout <<"(1->4) " <<h1.getHash(0, 1) << endl;
    cout <<"(3->4) " <<h1.getHash(3, 4) << endl;
    cout <<"(6->7) " <<h1.getHash(6, 7) << endl;

    return 0;
};