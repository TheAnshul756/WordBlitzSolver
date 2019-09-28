#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define	endl		'\n'
#define mii         map<ll int,ll int>
#define msi         map<string,ll int>
#define mis         map<ll int, string>
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define mpi         map<pair<ll int,ll int>,ll int>
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vii         vector<pair<ll int, ll int>>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define what_is(x)  cerr << #x << " is " << x << endl;
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;
#define N  2000005
#define G	4

ll cnt,number;
ll trie[N][26];
bool value[N];
char a[G][G];
bool vis[G][G];
stack<int>st;
vector<vector<int>>ans;
vector<pair<int,int>>pos;
// set<string> ans;
// set<pair<ll,string>> ans;
// vector<>

void print()
{
	if(st.size()<=2)
		return;
	stack<int> tmp;
	// string s="";
	vector<int> tts;
	while(!st.empty())
	{
		tmp.push(st.top());
		st.pop();
	}
	while(!tmp.empty())
	{
		tts.pb(tmp.top());
		// cout<<tmp.top()/G<<tmp.top()%G<<"B";
		// s+=a[tmp.top()/G][tmp.top()%G];
		st.push(tmp.top());
		tmp.pop();
	}
	ans.pb(tts);
	pos.pb({-sz(tts),number});
	number++;
	// cout<<"G";
	// cout<<s;
	// cout<<endl;
	// cout<<endl;
	// if(s.length()>2)
		// cout<<s<<endl;
	// ans.insert(s);
	// ans.insert({-s.length(),s});
}

void clean()
{
	rep(i,0,G)
	{
		rep(j,0,G)
			vis[i][j]=0;
	}
}

void process(ll pos)
{
	if(pos>=N)
	{
		cerr<<"Error\n";
		exit(0);
	}
	value[pos]=0;
	rep(i,0,26)
	trie[pos][i]=-1;
}

void insert(string s)
{
	ll p=0;
	rep(i,0,s.length())
	{
		if(trie[p][s[i]-'a']==-1)
		{
			trie[p][s[i]-'a']=cnt;
			process(cnt);
			cnt++;
		}
		p=trie[p][s[i]-'a'];
	}
	value[p]=1;
}

bool find(string s)
{
	ll p=0;
	rep(i,0,s.length())
	{
		if(trie[p][s[i]-'a']==-1)
		{
			// cout<<"NOT FOUND\n";
			return 0;
		}
		p=trie[p][s[i]-'a'];
	}
	if(value[p])
	{
		return 1;
		// cout<<"FOUND\n";
	}
	else
	{
		return 0;
		// cout<<"NOT FOUND\n";
	}
}

void process_trie()
{
	freopen("words.txt","r",stdin);
	string s;
	process(0);
	cnt=1;
	while(cin>>s)
	{
		insert(s);
	}
	fclose(stdin);
}

void take_input()
{
	freopen("input.txt","r",stdin);
	string s;
	cin>>s;
	rep(i,0,G)
	{
		rep(j,0,G)
		{
			cin>>a[i][j];
			a[i][j]=(a[i][j]-'A')+'a';
		}
	}
	fclose(stdin);
}

void fun(ll i,ll j, ll p)
{
	if(i>=G || j>=G || i<0 || j<0 || vis[i][j])
		return;
	p = trie[p][a[i][j]-'a'];
	if(p==-1)
		return;
	st.push(i*G+j);
	if(value[p])
		print();
	vis[i][j]=1;
	fun(i-1,j-1,p);
	fun(i-1,j,p);
	fun(i-1,j+1,p);
	fun(i,j-1,p);
	fun(i,j+1,p);
	fun(i+1,j-1,p);
	fun(i+1,j,p);
	fun(i+1,j+1,p);
	vis[i][j]=0;
	st.pop();
}

void solve()
{
	/************************************/
	// freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	/***********************************/
	take_input();
	// rep(i,0,G)
	// {
	// 	rep(j,0,G)
	// 	{
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	process_trie();
	
	// find("aerosat");
	// return;	

	rep(i,0,G)
	{
		rep(j,0,G)
		{
			clean();
			fun(i,j,0);
		}
	}
	set<string>st;
	sort(all(pos));
	for(auto i:pos)
	{
		string s="";
		rep(j,0,sz(ans[i.S]))
		{
			// cout<<ans[i.S][j]<<" ";
			s+=a[ans[i.S][j]/G][ans[i.S][j]%G];
			// cout<<ans[i.S][j]/G<<ans[i.S][j]%G<<"B";
		}
		if(st.find(s)!=st.end())
			continue;
		st.insert(s);
		rep(j,0,sz(ans[i.S]))
		{
			// cout<<ans[i.S][j]<<" ";
			// s+=a[ans[i.S][j]/G][ans[i.S][j]%G];
			cout<<ans[i.S][j]/G<<ans[i.S][j]%G<<"B";
		}
		// cout<<s<<endl;
		cout<<"G";
	}
	// what_is(sz(ans));
	// for(auto i:ans)
	// {
	// 	// if(i.F<-3)
	// 	cout<<i.S<<endl;
	// }
	return;
}


int main()
{
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		solve();
	}
	time
	return 0;
}