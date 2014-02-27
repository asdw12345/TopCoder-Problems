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

class FoxSequence {
public:
	string isValid(vector <int>);
};

string FoxSequence::isValid(vector <int> seq)
{
    int n=seq.size();
    if(n<4) return "NO";
    else
    {
        int diffa=seq[1]-seq[0],diffb,diffd,diffe;
        int a=0,b=0,c=0,d=0;
        int i,j,k,l,ll;
        if(diffa<=0) return "NO";
        else
        {
            for(i=1;i<n;i++)
            {
                if(seq[i]-seq[i-1]==diffa) a=i;
                else break;
            }
//            cout<<"diffa="<<diffa<<" ";
            if(a>=n-1) return "NO";
            else
            {
                diffb=seq[a+1]-seq[a];
                if(diffb>=0) return "NO";
            }
//            cout<<"diffb="<<diffb<<" ";
            for(j=a+1;j<n;j++)
            {
                if(seq[j]-seq[j-1]==diffb) b=j;
                else break;
            }
            if(b>=n-1) return "NO";
            else
            {
                c=b;
                for(k=b+1;k<n;k++)
                {
                    if(seq[k]==seq[k-1]) c=k;
                    else break;
                }
            }
//            cout<<c<<endl;
            if(c>=n-1) return "NO";
            else
            {
                diffd=seq[c+1]-seq[c];
                if(diffd<=0) return "NO";
            }
//            cout<<"diffd="<<diffd<<" ";
            for(l=c+1;l<n;l++)
            {
                if(seq[l]-seq[l-1]==diffd) d=l;
                else break;
            }
//            cout<<d<<endl;
            if(d>=n-1) return "NO";
            else
            {
                diffe=seq[d+1]-seq[d];
                if(diffe>=0) return "NO";
            }
//            cout<<"diffe="<<diffe<<endl;
            for(ll=l+1;ll<n;ll++)
            {
                if(seq[ll]-seq[ll-1]!=diffe) return "NO";
            }
        }
//        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        if(a>0&&a<b&&b<=c&&c<d&&d<n-1) return "YES";
        else return "NO";
    }
}

//<%:testing-code%>
//<%:start-tests%>
double test0() {
	int t0[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {3,6,9,1,9,5,1}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {1,2,3,2,1,2,3,2,1,2,3,2,1}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {1,3,4,3,1,1,1,1,3,4,3,1}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {6,1,6}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
