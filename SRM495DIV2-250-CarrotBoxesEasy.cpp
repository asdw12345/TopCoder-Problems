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

class CarrotBoxesEasy {
public:
	int theIndex(vector <int>, int);
};
#define MAXN 100
struct ca
{
    int num,pos;
}temp[MAXN];
bool cmp(ca x,ca y)
{
    if(x.num<y.num) return true;
    else if(x.num==y.num) return x.pos<y.pos?true:false;
    return false;
}
int CarrotBoxesEasy::theIndex(vector <int> carrots, int K)
{
    int n=carrots.size();
    int i,j;
    for(i=0;i<n;i++)
    {
        temp[i].num=carrots[i];
        temp[i].pos=i;
    }
    sort(temp,temp+n,cmp);
    int po,poss,sum,flag;
    for(i=0;i<n-1;i++)
    {
        sum=0;
        for(j=i+1;j<n;j++) sum+=(temp[j].num-temp[i].num);
        if(sum<=K)
        {
            flag=i;
            po=temp[i].pos;
            poss=temp[i+1].pos;
            break;
        }
    }
    if(sum>K) return temp[n-1].pos;
//    cout<<sum<<" "<<flag<<" "<<po<<endl;
    if(sum==K) return poss;
    else if(sum<K)
    {
        int anss=(K-sum)%(n-flag);
        if(anss==0)
        {
            for(i=n-1;i>=0;i--)
            {
                if(carrots[i]>=temp[flag].num) return i;
            }
        }
        for(i=0;i<n;i++)
        {
            if(carrots[i]>=temp[flag].num) anss--;
            if(anss==0) return i;
        }
    }
}

//<%:testing-code%>
//<%:start-tests%>
double test0() {
	int t0[] = {2,2, 10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 4;
	CarrotBoxesEasy * obj = new CarrotBoxesEasy();
	clock_t start = clock();
	int my_answer = obj->theIndex(p0, p1);
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
	int t0[] = {5, 8};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 4;
	CarrotBoxesEasy * obj = new CarrotBoxesEasy();
	clock_t start = clock();
	int my_answer = obj->theIndex(p0, p1);
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
	int t0[] = {4, 9, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 18;
	CarrotBoxesEasy * obj = new CarrotBoxesEasy();
	clock_t start = clock();
	int my_answer = obj->theIndex(p0, p1);
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
	int t0[] = {13, 75, 24, 55};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 140;
	CarrotBoxesEasy * obj = new CarrotBoxesEasy();
	clock_t start = clock();
	int my_answer = obj->theIndex(p0, p1);
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
double test4() {
	int t0[] = {14, 36, 52, 86, 27, 97, 3, 67};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 300;
	CarrotBoxesEasy * obj = new CarrotBoxesEasy();
	clock_t start = clock();
	int my_answer = obj->theIndex(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
