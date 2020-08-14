#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int a[maxn];
struct T
{
    int l,r,mid;
    int GCD;
}tree[maxn<<2];
void push_up(int rt)
{
    tree[rt].GCD=__gcd(tree[rt<<1].GCD,tree[rt<<1|1].GCD);
}
void build(int rt,int l,int r)
{
    tree[rt].l=l;
    tree[rt].r=r;
    if(l==r)
    {
        tree[rt].GCD=a[l];
        return ;
    }
    int mid=tree[rt].mid=l+r>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    push_up(rt);
}
void update(int rt,int pos,int val)
{
    if(tree[rt].l==tree[rt].r)
    {
        tree[rt].GCD=val;
        return ;
    }
    if(pos<=tree[rt].mid) update(rt<<1,pos,val);
    else update(rt<<1|1,pos,val);
    push_up(rt);
}
int query(int rt,int l,int r)
{
    if(tree[rt].r<l||tree[rt].l>r) return 0;
    if(tree[rt].l>=l&&tree[rt].r<=r)
    {
        return tree[rt].GCD;
    }
    int ans=0;
    if(tree[rt].mid>=l) ans=__gcd(ans,query(rt<<1,l,r));
    if(tree[rt].mid<r) ans=__gcd(ans,query(rt<<1|1,l,r));
    return ans;
}
int findpos(int rt,int l,int r,int x)
{
    if(l==r) return 1;//查询到长度为1的区间，说明操作合法
    int ansl=x,ansr=x;
    if(tree[rt].mid>=l) ansl=query(rt<<1,l,tree[rt].mid);
    if(tree[rt].mid<r) ansr=query(rt<<1|1,tree[rt].mid+1,r);
    ansl=__gcd(ansl,x);
    ansr=__gcd(ansr,x);
    if(ansl!=x&&ansr!=x) return -1;//两个子区间的gcd都不是x的倍数，一定不合法
    else if(ansl==x&&ansr==x) return 1;//两个子区间的gcd都是x的倍数，一定合法
    else if(ansl==x) return findpos(rt<<1|1,tree[rt].mid+1,r,x);//转换为子问题求解
    else return findpos(rt<<1,l,tree[rt].mid,x);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int op,l,r,x;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d%d",&l,&r,&x);
            if(findpos(1,l,r,x)==1) puts("YES");
            else puts("NO");
        }
        else
        {
            scanf("%d%d",&l,&x);
            update(1,l,x);
        }
    }
    return 0;
}

