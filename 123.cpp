#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a[4];
int main(void)
{
    int c = 0;
    //freopen("data.txt","r",stdin);
    while (~scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]))
    {
        if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0)
        {
            break;
        }
        sort(a, a + 4);
        if (c != 0)
        {
            printf("\n");
        }
        c++;
        int now = a[0];
        int i = 0;
        while (a[i] == 0)
        {
            now = a[++i];
        }
        bool flag = true;
        do
        {
            if (a[0] == 0)
            {
                //printf("\n");
                continue;
            }
            if (flag)
            {
                printf("%d%d%d%d", a[0], a[1], a[2], a[3]);
                flag = false;
            }
            else if (a[0] == now)
            {
                printf(" %d%d%d%d", a[0], a[1], a[2], a[3]);
            }
            else
            {
                printf("\n%d%d%d%d", a[0], a[1], a[2], a[3]);
            }
            now = a[0];
        } while (next_permutation(a, a + 4));
        printf("\n");
    }
    return 0;
}