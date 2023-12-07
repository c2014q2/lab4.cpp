#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>


using namespace std;

int main () 
{
    vector<int> c = {1,2,3,3,4,4,4,4,5,6,7,8,9,10};
    vector<int> c2 = {11,12,13,14,15,16,17,18,19,20};


    vector<int> c3 (c.size()+c2.size());  //pentru ex4
    

    vector<int> cPalindrom = {1, 3, 3, 3, 3, 1};   //pentru ex5

    auto palindromCh = std::equal(cPalindrom.begin(), cPalindrom.begin() + cPalindrom.size() / 2, cPalindrom.rbegin());
    if (palindromCh) cout << "cPalindrom Este Palindrom" << endl;
        else cout <<  "cPalindrom Nu Este Palindrom" << endl;



    auto duplicate = std::unique(c.begin(), c.end());   // unique muta elementele care se repeta la sfarsit si 
    c.erase(duplicate, c.end());                       //eliminarea elementelor care se repeta


    std::merge(c.begin(), c.end(), c2.begin(), c2.end(), c3.begin());

    c3.erase(unique(begin(c3),end(c3)),end(c3));  //eliminarea elementelor asemanatoare din c3


    std::cout << "c [ ";
  { for (auto n = c.begin();n!=c.end();++n)           //afisarea vectoruului c (ex3)
    {
        std::cout << *n << " "  ;
    }
    std::cout << "]"<< endl ;
  }



    int res1 = accumulate(begin(c), end(c), 0);
    int res2 = binary_search(begin(c), end(c), 9);


    std::cout << "1.REZULTAT:" << res1  << endl;                       //ex1


    if (res2) std::cout << "2. Se gaseste" << endl;                    //ex 2
        else std::cout << "2. Nu se gaseste" << endl;


    return 0;
}



