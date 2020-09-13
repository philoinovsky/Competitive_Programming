#include<bits/stdc++.h>
#define maxl 300010
 
using namespace std;
 
int n,k,m,cas;
struct node{
	int x,c;
}a[maxl];
typedef pair<int,int> p;
priority_queue<int> q1;
set <int> s;
priority_queue<p,vector<p>,greater<p> > q2;
long long ans;
 
inline bool cmp(const node &x,const node &y){ return x.x<y.x; }
 
inline void prework(){
	scanf("%d%d",&k,&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].x);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].c);
	sort(a+1,a+1+n,cmp);
} 
 
inline void mainwork(){
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	s.clear();
	int k1=k/2,k2=k-k1;
	long long tmp=a[k1+1].c;p d;
	for(int i=1;i<=k1;i++){
		q1.push(a[i].c-a[i].x);
		tmp+=-a[i].x+a[i].c; 
	}
	for(int i=n;i>=k1+2;i--)
		q2.push(make_pair(a[i].c+a[i].x,i));
	for(int i=1;i<=k2;i++){
		d=q2.top();q2.pop();
		tmp+=d.first;
		s.insert(d.second);
	}
	ans=tmp+1ll*k1*a[k1+1].x-1ll*k2*a[k1+1].x;
	for(int i=k1+2;i<=n-k2;i++){
		tmp-=a[i-1].c;tmp+=a[i].c;
		if(!q1.empty())
		if(a[i-1].c-a[i-1].x<q1.top()){
			tmp-=q1.top();q1.pop();
			tmp+=a[i-1].c-a[i-1].x;
			q1.push(a[i-1].c-a[i-1].x);
		}
		if(s.begin()!=s.end()) if((*s.begin())==i){
			tmp-=a[i].c+a[i].x;
			s.erase(s.begin()); 
			do{
				d=q2.top();q2.pop();
			} while (d.second<=i);
			tmp+=d.first;
			s.insert(d.second);
		}
		ans=min(ans,tmp+1ll*k1*a[i].x-1ll*k2*a[i].x);
	}
}
 
inline void print(){
	printf("Case #%d: ",cas);
	printf("%lld\n",ans);
}
 
int main(){
	int t;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){ 
		prework();
		mainwork();
		print();
	}
	return 0;
}