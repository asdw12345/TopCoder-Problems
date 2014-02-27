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

class SRMCards {
public:
	int maxTurns(vector <int>);
};

int SRMCards::maxTurns(vector <int> cards)
{
    int n=cards.size();
    sort(cards.begin(),cards.end());
    int i,j,k;
    int num=1;
//    for(i=0;i<n;i++) cout<<cards[i]<<" ";
//    cout<<endl;
    int flag=0;
    for(i=0;i<n-1;i++)
    {
        if(cards[i+1]-cards[i]!=1)
        {
            flag=1;
            num++;
        }
        else
        {
            int nn=1;
            if(flag) num--;
            if(i==0) num--;
            for(j=i;j<n-1;j+=1)
            {
                if(cards[j+1]-cards[j]==1) nn++;
                else break;
            }
            flag=0;
//            cout<<nn<<endl;
            i=j-1;
            num+=((nn/2)+(nn%2));
        }
//        cout<<"***"<<i<<" "<<num<<endl;
    }
    return num;
}

//<%:testing-code%>
//<%:start-tests%>
double test0() {
	int t0[] = {498, 499};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SRMCards * obj = new SRMCards();
	clock_t start = clock();
	int my_answer = obj->maxTurns(p0);
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
	int t0[] = {491, 492, 495, 497, 498, 499};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SRMCards * obj = new SRMCards();
	clock_t start = clock();
	int my_answer = obj->maxTurns(p0);
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
double test2() {
	int t0[] = {100, 200, 300, 400};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SRMCards * obj = new SRMCards();
	clock_t start = clock();
	int my_answer = obj->maxTurns(p0);
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
double test3() {
	int t0[] = {11, 12, 102, 13, 100, 101, 99, 9, 8, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SRMCards * obj = new SRMCards();
	clock_t start = clock();
	int my_answer = obj->maxTurns(p0);
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
double test4() {
	int t0[] = {118, 321, 322, 119, 120, 320};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SRMCards * obj = new SRMCards();
	clock_t start = clock();
	int my_answer = obj->maxTurns(p0);
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
double test5() {
	int t0[] = {10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SRMCards * obj = new SRMCards();
	clock_t start = clock();
	int my_answer = obj->maxTurns(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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

	time = test4();
	if (time < 0)
		errors = true;

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
