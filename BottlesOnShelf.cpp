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
typedef long long LL;
class BottlesOnShelf {
public:
	int getNumBroken(int, vector <int>, vector <int>, vector <int>);
};

LL GCD(int x,int y)
{
    if(x<y) return GCD(y,x);
    return x%y==0?y:GCD(y,x%y);
}
int BottlesOnShelf::getNumBroken(int N, vector <int> left, vector <int> right, vector <int> damage)
{
    int len=right.size();
    int i,j;
    int ans=0;
    for(i=1;i<(1<<len);i++)
    {
        bool flag=true;
        LL num=0,lcm=1;
        int minn=1,maxx=N;
        for(j=0;j<len;j++)
        {
            if(i&(1<<j))
            {
                minn=max(minn,left[j]);
                maxx=min(maxx,right[j]);
                lcm=lcm*(damage[j]/GCD(lcm,damage[j]));
                num++;
//                cout<<i<<" "<<j<<" "<<minn<<" "<<maxx<<" "<<lcm<<endl;
                if(lcm>N)
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag==false||minn>maxx) continue;
        else
        {
//            cout<<"******"<<maxx/lcm-(minn-1)/lcm<<endl;
            if(num&1) ans+=maxx/lcm-(minn-1)/lcm;
            else ans-=maxx/lcm-(minn-1)/lcm;
        }
    }
    return ans;
}

//<%:testing-code%>
//<%:start-tests%>
double test0() {
	int p0 = 7;
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {7};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	BottlesOnShelf * obj = new BottlesOnShelf();
	clock_t start = clock();
	int my_answer = obj->getNumBroken(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 7;
	int t1[] = {1,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {7,7};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2,3};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	BottlesOnShelf * obj = new BottlesOnShelf();
	clock_t start = clock();
	int my_answer = obj->getNumBroken(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 7;
	int t1[] = {1,1,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {7,7,7};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2,3,6};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	BottlesOnShelf * obj = new BottlesOnShelf();
	clock_t start = clock();
	int my_answer = obj->getNumBroken(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 10;
	int t1[] = {1,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {5,10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,7};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	BottlesOnShelf * obj = new BottlesOnShelf();
	clock_t start = clock();
	int my_answer = obj->getNumBroken(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 5;
	int t1[] = {4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {7};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	BottlesOnShelf * obj = new BottlesOnShelf();
	clock_t start = clock();
	int my_answer = obj->getNumBroken(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 1000000000;
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1000000000};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	BottlesOnShelf * obj = new BottlesOnShelf();
	clock_t start = clock();
	int my_answer = obj->getNumBroken(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1000000000;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
