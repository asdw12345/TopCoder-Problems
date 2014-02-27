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

class ColorfulRabbits {
public:
	int getMinimum(vector <int>);
};
#define MAXN 1000000+5
int num[MAXN];
int ColorfulRabbits::getMinimum(vector <int> replies)
{
	int n=replies.size(),m=*max_element(replies.begin(),replies.end());
	sort(replies.begin(),replies.end());
	int i,j,ans=0;
	memset(num,0,sizeof(num));
	for(i=0;i<n;i++) num[replies[i]]+=1;
	for(i=0;i<=m;i++)
    {
        if(num[i]!=0)
        {
            ans+=(num[i]/(i+1))*(i+1);
            if(num[i]%(i+1)!=0) ans+=(i+1);
        }
    }
	return ans;
}

//<%:testing-code%>
//<%:start-tests%>
double test0() {
	int t0[] = { 1, 1, 2, 2 }
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ColorfulRabbits * obj = new ColorfulRabbits();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
	int t0[] = { 0 }
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ColorfulRabbits * obj = new ColorfulRabbits();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0);
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
double test2() {
	int t0[] = { 2, 2, 44, 2, 2, 2, 444, 2, 2 }
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ColorfulRabbits * obj = new ColorfulRabbits();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 499;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
