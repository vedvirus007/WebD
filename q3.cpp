#include<bits/stdc++.h>
using namespace std;
int findpar(int i,vector<int>& parent)
{
	if(i==parent[i]) return i;
	return parent[i]=findpar(parent[i],parent);
}
void unionn(int i,int j,vector<int>&parent,vector<int>&rank)
{
	int u=findpar(i,parent);
	int v=findpar(j,parent);
	if(rank[u]<rank[v])
	{
		parent[u]=v;
	}
	if(rank[u]>rank[v])
	{
		parent[v]=u;
	}
	else{
		parent[u]=v;
		rank[v]++;
	}
}
int main(){
	int n;
	cin>>n;
 vector<pair<int,int>> v;
 for(int i=0;i<n;i++)
 {
	int c,r;
	cin>>c>>r;
	v.push_back({c,r});
 }
 vector<int> rank(n,0);
 vector<int> parent(n);
 for(int i=0;i<n;i++) parent[i]=i;
 vector<int> ans(n,0);
 for(int i=0;i<n;i++)
 {
	for(int j=i+1;j<n;j++)
	{
		int c1=v[i].first;
		int r1=v[i].second;
		int c2=v[j].first;
		int r2=v[j].second;
		if(c1*c1+c2*c2-2*c1*c2<=r1*r1+r2*r2)
		{
			ans[i]++;
			ans[j]++;
			unionn(i,j,parent,rank);
		}
	}
 }
 sort(ans.begin(),ans.end(),greater<int>());
 


}
