#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;


int main()
{

// =============================
// STRING METHODS
// =============================

string text="Hello C++";


cout << text.length();        // 1
cout << text.size();          // 2

text.push_back('!');          // 3

text.pop_back();              // 4

text.append(" World");        // 5

cout << text.substr(0,5);     // 6

cout << text.find("C++");     // 7

text.replace(0,5,"Hi");       // 8

text.insert(2,"ABC");         // 9

text.erase(2,3);              // 10



// =============================
// VECTOR METHODS
// =============================

vector<int> nums={5,2,8};


nums.push_back(10);           // 11

nums.pop_back();              // 12

cout<<nums.size();            // 13

cout<<nums.front();           // 14

cout<<nums.back();            // 15

nums.clear();                 // 16

nums.empty();                 // 17

nums.resize(10);              // 18

nums.at(2);                   // 19

nums.begin();                 // 20



// =============================
// ALGORITHM METHODS
// =============================

vector<int> a={5,3,1,4};


sort(a.begin(),a.end());      // 21


reverse(a.begin(),a.end());   // 22


auto x=find(
a.begin(),
a.end(),
3);                           // 23


count(
a.begin(),
a.end(),
3);                           // 24


max(10,20);                   // 25


min(10,20);                   // 26


swap(a[0],a[1]);              // 27


binary_search(
a.begin(),
a.end(),
3);                           // 28


accumulate(
a.begin(),
a.end(),
0);                           // 29



// =============================
// MATH METHODS
// =============================


sqrt(25);                     // 30

pow(2,3);                     // 31

abs(-5);                      // 32

ceil(4.2);                    // 33

floor(4.8);                   // 34

round(4.5);                   // 35

sin(1);                       // 36

cos(1);                       // 37

tan(1);                       // 38

log(10);                      // 39



// =============================
// MAP METHODS
// =============================


map<string,int> ages;


ages["John"]=25;


ages.insert(
{"Bob",30});                  // 40


ages.erase("Bob");            // 41


ages.find("John");            // 42


ages.size();                  // 43


ages.empty();                 // 44


ages.clear();                 // 45



// =============================
// SET METHODS
// =============================


set<int> numbers;


numbers.insert(10);           // 46


numbers.erase(10);            // 47


numbers.find(5);              // 48


numbers.count(5);             // 49


numbers.size();               // 50


numbers.empty();              // 51



// =============================
// STACK METHODS
// =============================


stack<int> s;


s.push(5);                    // 52


s.pop();                      // 53


s.top();                      // 54


s.size();                     // 55


s.empty();                    // 56



// =============================
// QUEUE METHODS
// =============================


queue<int> q;


q.push(10);                   // 57


q.pop();                      // 58


q.front();                    // 59


q.back();                     // 60


q.size();                     // 61


q.empty();                    // 62



// =============================
// INPUT / OUTPUT
// =============================


int number;


cin>>number;                  // 63


cout<<number;                 // 64


getline(cin,text);            // 65


endl;                         // 66



// =============================
// POINTER / MEMORY
// =============================


int *ptr=new int;             // 67


delete ptr;                   // 68



// =============================
// FILE METHODS
// =============================

/*
ofstream file;

file.open("data.txt");        //69

file<<"Hello";                //70

file.close();                 //71

*/


// =============================
// CHARACTER METHODS
// =============================


isdigit('5');                 //72

isalpha('A');                 //73

toupper('a');                 //74

tolower('A');                 //75



// =============================
// ITERATORS
// =============================


a.begin();                    //76

a.end();                      //77

a.rbegin();                   //78

a.rend();                     //79



// =============================
// VECTOR INSERT / REMOVE
// =============================


vector<int> v={1,2,3};


v.insert(
v.begin(),
100);                         //80


v.erase(
v.begin());                   //81



// =============================
// PAIR METHODS
// =============================


pair<int,string> p;


p.first=1;                    //82

p.second="C++";               //83



// =============================
// CONVERSION METHODS
// =============================


stoi("123");                  //84

stod("3.14");                 //85

to_string(100);               //86



// =============================
// RANDOM
// =============================


rand();                       //87

srand(10);                    //88



// =============================
// BOOLEAN
// =============================


true;                         //89

false;                        //90



// =============================
// CLASS OBJECT METHODS
// =============================


/*
constructor();                //91

destructor();                 //92

copy constructor();           //93

operator overload();         //94

getter();                     //95

setter();                     //96
*/


// =============================
// MODERN C++ FEATURES
// =============================


auto value=100;               //97


nullptr;                      //98


constexpr int x2=5;           //99


static_cast<int>(3.5);        //100



return 0;

// 100 most used methods in C++

}