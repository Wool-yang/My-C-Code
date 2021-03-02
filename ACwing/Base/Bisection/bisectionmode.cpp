//整数二分模板
bool check(int mid)
{

} //性质判断函数

int bsearch1(int l, int r)
{
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
} //[l,r]=>[l,mid],[mid+1,r]

int bsearch2(int l, int r)
{
    while (l < r)
    {
        int mid = (l + r + 1) / 2; //l ture时mid=(l+r+1)/2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
} //[l,r]=>[l,mid-1],[mid,r]
//浮点数二分模板
bool check(double mid)
{
}

double bsearch3(double l, double r)
{
    while (r - l > eps)
    { //eps为题目所给精度，可以往后推进两位保险
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    return l; //r也可
}
int eps; //emmm;
