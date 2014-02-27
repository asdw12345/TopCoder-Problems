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

using namespace std;

class TimeTravellingCellar {
public:
	int determineProfit(vector <int>, vector <int>);
};

int TimeTravellingCellar::determineProfit(vector <int> profit, vector <int> decay)
{
	int len=profit.size();
	int i,j;
	int maxx=0;
	for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            if(i==j) continue;
            else
            {
                maxx=max(maxx,profit[i]-decay[j]);
            }
        }
    }
    return maxx;
}

//<%:testing-code%>
//<%:start-tests%>
double test0() {
	int t0[] = {1,2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3,1,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TimeTravellingCellar * obj = new TimeTravellingCellar();
	clock_t start = clock();
	int my_answer = obj->determineProfit(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	int t0[] = {3,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TimeTravellingCellar * obj = new TimeTravellingCellar();
	clock_t start = clock();
	int my_answer = obj->determineProfit(p0, p1);
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
double test2() {
	int t0[] = {3,3,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,1,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TimeTravellingCellar * obj = new TimeTravellingCellar();
	clock_t start = clock();
	int my_answer = obj->determineProfit(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
double test3() {
	int t0[] = {1000,500,250,125};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {64,32,16,8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TimeTravellingCellar * obj = new TimeTravellingCellar();
	clock_t start = clock();
	int my_answer = obj->determineProfit(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 992;
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
