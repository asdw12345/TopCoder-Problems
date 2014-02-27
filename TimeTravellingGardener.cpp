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
#define MAXN 50
#define INF 0x3f3f3f3f
#define eps 1e-6
class TimeTravellingGardener {
public:
	int determineUsage(vector <int>, vector <int>);
};
double pos[MAXN];
int TimeTravellingGardener::determineUsage(vector <int> distance, vector <int> height)
{
    int n=height.size();
    int i,j,k;
    double tan;
    pos[0]=0;
    for(i=1;i<n;i++)
    {
        pos[i]=pos[i-1]+distance[i-1];
//        cout<<pos[i]<<endl;
    }
    int minn=INF;
    double h;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            int num=0;
            bool flag=false;
            tan=(height[i]-height[j])*1.0/(1.0*(pos[i]-pos[j]));
            for(k=0;k<n;k++)
            {
                if(k!=i&&k!=j)
                {
                    h=tan*(pos[k]-pos[j])*1.0+height[j]*1.0;
                    if(h-height[k]*1.0>eps||h<-eps)
                    {
                        num=n-1;
                        flag=true;
                    }
                    else if(h-height[k]*1.0<=eps&&h-height[k]*1.0>=0) continue;
                    else num++;
//                cout<<"****"<<i<<" "<<j<<" "<<k<<" "<<h<<" "<<height[k]*1.0<<" "<<h-height[k]*1.0<<" "<<num<<endl;
                if(flag==true) break;
                }
            }
            minn=min(minn,num);
//            cout<<"&&&&"<<i<<" "<<j<<" "<<num<<" "<<minn<<endl;
        }
    }
    return minn;
}

//<%:testing-code%>
//<%:start-tests%>
double test0() {
	int t0[] = {48, 38, 50, 36};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {102, 87, 51, 710, 246};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TimeTravellingGardener * obj = new TimeTravellingGardener();
	clock_t start = clock();
	int my_answer = obj->determineUsage(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int t0[] = {3,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3,1,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TimeTravellingGardener * obj = new TimeTravellingGardener();
	clock_t start = clock();
	int my_answer = obj->determineUsage(p0, p1);
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
double test2() {
	int t0[] = {1,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {4,4,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TimeTravellingGardener * obj = new TimeTravellingGardener();
	clock_t start = clock();
	int my_answer = obj->determineUsage(p0, p1);
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
double test3() {
	int t0[] = {4,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {9,8,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TimeTravellingGardener * obj = new TimeTravellingGardener();
	clock_t start = clock();
	int my_answer = obj->determineUsage(p0, p1);
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
double test4() {
	int t0[] = {476,465,260,484};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {39,13,8,72,80};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TimeTravellingGardener * obj = new TimeTravellingGardener();
	clock_t start = clock();
	int my_answer = obj->determineUsage(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
double test5() {
	int t0[] = {173,36,668,79,26,544};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {488,743,203,446,444,91,453};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TimeTravellingGardener * obj = new TimeTravellingGardener();
	clock_t start = clock();
	int my_answer = obj->determineUsage(p0, p1);
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
double test6() {
	int t0[] = {2,4,2,2,4,2,4,2,2,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,2,10,10,10,16,16,22,22,28,28};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	TimeTravellingGardener * obj = new TimeTravellingGardener();
	clock_t start = clock();
	int my_answer = obj->determineUsage(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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

	time = test5();
	if (time < 0)
		errors = true;

	time = test6();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
