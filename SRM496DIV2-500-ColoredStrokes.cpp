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

class ColoredStrokes {
public:
	int getLeast(vector <string>);
};

int ColoredStrokes::getLeast(vector <string> picture)
{
	int n=picture.size(),m=picture[0].size();
	int i,j,k;
	int num=0;
	for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(picture[i][j]=='B')
            {
                num++;
                for(k=i;k<n;k++)
                {
                    if(picture[k][j]=='B') picture[k][j]='.';
                    else if(picture[k][j]=='G') picture[k][j]='R';
                    else break;
                }
            }
            else if(picture[i][j]=='R')
            {
                num++;
                for(k=j;k<m;k++)
                {
                    if(picture[i][k]=='R') picture[i][k]='.';
                    else if(picture[i][k]=='G') picture[i][k]='B';
                    else break;
                }
            }
            else if(picture[i][j]=='G')
            {
                picture[i][j]='R';
                for(k=i+1;k<n;k++)
                {
                    if(picture[k][j]=='B') picture[k][j]='.';
                    else if(picture[k][j]=='G') picture[k][j]='R';
                    else break;
                }
                for(k=j;k<m;k++)
                {
                    if(picture[i][k]=='R') picture[i][k]='.';
                    else if(picture[i][k]=='G') picture[i][k]='B';
                    else break;
                }
                num+=2;
            }
//            for(int ii=0;ii<n;ii++)
//            {
//                for(int jj=0;jj<m;jj++)
//                {
//                    cout<<picture[ii][jj]<<" ";
//                }
//                cout<<endl;
//            }
//            cout<<"*****"<<num<<endl;
        }
    }
    return num;
}
//<%:testing-code%>
//<%:start-tests%>
double test0() {
	string t0[] = {"...",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	string t0[] = {"..B.",
 "..B."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
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
	string t0[] = {".BB."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
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
double test3() {
	string t0[] = {"...B..",
 ".BRGRR",
 ".B.B.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	string t0[] = {"...B..",
 ".BRBRR",
 ".B.B.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
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
	string t0[] = {"GR",
 "BG"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
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
