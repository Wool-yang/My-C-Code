#include <iostream>
#include <stack>

using namespace std;

stack<double> A;

int main()
{
    char c;
    double temp;
    while (1)
    {
        double n;
        cin >> n;
        c = getchar();
        if (n == 0 && c == '\n')
            break;
        A.push(n);
        while (cin >> c >> n)
        {
            if (c == '*')
            {
                temp = A.top() * n;
                A.pop();
                A.push(temp);
            }
            else if (c == '/')
            {
                temp = A.top() / n;
                A.pop();
                A.push(temp);
            }
            else if (c == '+')
                A.push(n);
            if (c == '-')
                A.push(-n);
            if(getchar() == '\n')
                break;
        }
        temp = 0;
        while (A.size())
        {
            temp += A.top();
            A.pop();
        }
        printf("%.2lf\n",temp);
    }
    return 0;
}