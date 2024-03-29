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

class NinePuzzle {
public:
	int getMinimumCost(string, string);
};
int a[26],b[26],c[26];
bool cmp(int x,int y)
{
    return x>y?true:false;
}
int NinePuzzle::getMinimumCost(string init, string goal)
{
	int n=init.size();
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int i,j;
	for(i=0;i<n;i++)
        if(init[i]!='*') a[init[i]-'A']++;
    for(i=0;i<n;i++)
        if(goal[i]!='*') b[goal[i]-'A']++;
    for(i=0;i<26;i++) c[i]=a[i]-b[i];
    sort(c,c+26,cmp);
    int sum=0;
    for(i=0;i<n;i++)
    {
        if(c[i]>0) sum+=c[i];
        else break;
    }
    return sum;
}

//<%:testing-code%>
//<%:start-tests%>
double test0() {
	string p0 = "RYYGYB*YYY" ;
	string p1 = "BYBB*GBBRB" ;
	NinePuzzle * obj = new NinePuzzle();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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
	string p0 = "GBBB*BGBBG" ;
	string p1 = "RYYY*YRYYR";
	NinePuzzle * obj = new NinePuzzle();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 9;
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
	string p0 = "RRBR*BRBBB" ;
	string p1 = "BBRB*RBRRR" ;
	NinePuzzle * obj = new NinePuzzle();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
