#include <iostream>
#include "LCS.h"
using namespace std;

int main()
{
    char *x = "abcbdefdaba";
    char *y = "bdcabcbdefa";
    get_lcs(x,y);

    return 0;
}
