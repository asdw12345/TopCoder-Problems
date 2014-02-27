#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

struct point
{
    string str;
    int b;
    point(string str_,int b_):str(str_),b(b_){}
    bool operator<(const point&a)const{return b>a.b;};
};

string rev(string s)
{
     return string(s.rbegin(),s.rend());
}

class PalindromeGame{
public:
    int getMaximum( vector <string> front, vector <int> back )
{
    int N = (int)front.size();
    vector<point> card;
    for ( int i=0; i<N; i++ )
        card.push_back( point(front[i],back[i]) );
    sort( card.begin(), card.end() );

    int ans = 0;

    vector<bool> used(N);
    for ( int i=0; i<N; i++ )
    if ( !used[i] )
    {
        for ( int j=i+1; j<N; j++ )
        if ( !used[j] && card[i].str==rev(card[j].str) )
        {
            ans += card[i].b + card[j].b;
            used[i] = used[j] = true;
            break;
        }
    }

    for ( int i=0; i<N; i++ )
    if ( !used[i] && card[i].str==rev(card[i].str) )
    {
        ans += card[i].b;
        used[i] = true;
        break;
    }

    return ans;
}
};
///****************************************************************************
//³ÂË¼½ÝµÄ´úÂë
//struct node{
//    string s;
//    int num;
//    node(string F,int N){s=F,num=N;}
//    node(){}
//};
//bool cmp(node a,node b){
//    if(a.s==b.s)return a.num>b.num;
//    return a.s<b.s;
//}
//
//int PalindromeGame::getMaximum(vector <string> f, vector <int> b) {
//    int v[1999];
//    string str1,str2;
//    int n=b.size();
//    vector <node> Q;
//    for(int i=0;i<n;i++)Q.push_back(node(f[i],b[i]));
//    sort(Q.begin(),Q.end(),cmp);
//     for(int i=0;i<Q.size();i++)cout<<Q[i].s <<" "<<Q[i].num<<endl;
//    memset(v,0,sizeof(v));
//    int cnt=0;
//    for(int i=0;i<n;i++){
//        if(!v[i]){
//            str1=Q[i].s;
//            for(int j=i+1;j<n;j++){
//                if(!v[j]){
//                    str2=Q[j].s;
//                    reverse(str2.begin(),str2.end());
//                    if(str1==str2){
//                        cnt+=(Q[i].num+Q[j].num);
//                        v[i]=1,v[j]=1;
//                        cout<<i<<" "<<j<<endl;
//                        break;
//                    }
//                }
//            }
//        }
//    }
//    int maxn=0;
//    for(int i=0;i<n;i++){
//        if(!v[i]){
//            str1=Q[i].s;
//            str2=str1;
//            reverse(str2.begin(),str2.end());
//            if(str1==str2)
//                maxn=max(maxn,Q[i].num);
//        }
//    }
// return cnt+maxn;
//
//}
///*****************************************************************************

//<%:testing-code%>
//<%:start-tests%>
double test0() {
	string t0[] = { "topcoder", "redcoder", "redocpot" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = { 7, 5, 3 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PalindromeGame * obj = new PalindromeGame();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = { "rabbit" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = { 1000000 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PalindromeGame * obj = new PalindromeGame();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = { "abc", "abc", "def", "cba", "fed" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = { 24, 7, 63, 222, 190 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PalindromeGame * obj = new PalindromeGame();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 499;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3()
{
    string t0[] = {"xyx", "xyx", "xyx", "zzz", "zzz", "zzz"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {5, 7, 2, 1, 6, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PalindromeGame * obj = new PalindromeGame();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 24;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
//<%:end-tests%>
int main() {
	int time;
	bool errors = false;

	time = test0();
	if (time < 0)
		errors = true;

	time = test1();
	if (time < 0)
		errors = true;

	time = test2();
	if (time < 0)
		errors = true;

    time = test3();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}


//Powered by [KawigiEdit] 2.0!
