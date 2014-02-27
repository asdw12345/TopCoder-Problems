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
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class AnagramFree {
public:
	int getMaximumSubset(vector <string>);
};
#define MAXN 50+5
int s[MAXN][26],temp[MAXN];
int AnagramFree::getMaximumSubset(vector <string> S)
{
    int i,j,k;
    int n=S.size();
    memset(s,0,sizeof(s));
    memset(temp,0,sizeof(temp));
    for(i=0;i<n;i++)
        for(j=0;j<S[i].size();j++)
            s[i][S[i][j]-'a']++;
    int flag;
    int a=1;
    temp[0]=1;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            flag=0;
            for(k=0;k<26;k++)
            {
                if(s[i][k]!=s[j][k])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
               if(temp[j]==0) temp[j]=++a;
            }
            else
            {
                temp[j]=temp[i];
            }
//            cout<<a<<" "<<flag<<" "<<i<<" "<<j<<" "<<temp[i]<<" "<<temp[j]<<endl;
        }
    }
    sort(temp,temp+n);
    int ans=1;
    for(i=0;i<n-1;i++)
    {
//        cout<<temp[i]<<" ";
        if(temp[i]!=temp[i+1]) ans++;
    }
//    cout<<temp[n-1]<<endl;
    return ans;
}

//<%:testing-code%>
//<%:start-tests%>
double test0() {
	string t0[] = {"abcd","abdc","dabc","bacd"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AnagramFree * obj = new AnagramFree();
	clock_t start = clock();
	int my_answer = obj->getMaximumSubset(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"abcd","abac","aabc","bacd"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AnagramFree * obj = new AnagramFree();
	clock_t start = clock();
	int my_answer = obj->getMaximumSubset(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"aa","aaaaa","aaa","a","bbaaaa","aaababaa"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AnagramFree * obj = new AnagramFree();
	clock_t start = clock();
	int my_answer = obj->getMaximumSubset(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"creation","sentence","reaction","sneak","star","rats","snake"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AnagramFree * obj = new AnagramFree();
	clock_t start = clock();
	int my_answer = obj->getMaximumSubset(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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
