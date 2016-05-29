// =====================================================================================
//
//       Filename:  Test.cpp
//
//    Description:  章节中的测试代码
//
//        Version:  1.0
//        Created:  2016年05月29日 20时34分51秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Mr.yan (gk), 827324013@qq.com
//   Organization:  cn
//
// =====================================================================================
#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <stdlib.h>
#include <vector>

using namespace std;

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  入口函数
// =====================================================================================
int main(int argc, char* argv[])
{

    //-----------------------------------------------------------------------------
    //  find int value in vector
    //-----------------------------------------------------------------------------
    {
        vector<int> vec = { 32, 33, 23, 43 };
        int iValue = 32;
        auto result = find(vec.cbegin(), vec.cend(), iValue);
        cout << "The value " << iValue
             << (result == vec.cend() ? " is not present" : " is present") << "!\n"
             << endl;
    }

    //-----------------------------------------------------------------------------
    //  find int value in array
    //-----------------------------------------------------------------------------
    {
        int iArray[] = { 2, 3, 4, 5, 6, 12, 14 };
        int iValue = 14;
        auto result1 = find(begin(iArray), end(iArray), iValue);
        cout << "The value " << iValue
             << (result1 == end(iArray) ? " is not present" : " is present") << "!\n"
             << endl;
        auto result2 = find(iArray, iArray + sizeof(iArray) / sizeof(int), iValue);
        cout << "The value " << iValue
             << (result2 == end(iArray) ? " is not present" : " is present") << "!\n"
             << endl;
    }
    //-----------------------------------------------------------------------------
    //  find string value int vector
    //-----------------------------------------------------------------------------
    {
        vector<string> vec = { "hello", "world", "one", "two" };
        string sValue = "one";
        auto result = find(vec.cbegin(), vec.cend(), sValue);
        cout << "The value " << sValue
             << (result == vec.cend() ? " is not presnet" : " is present") << "!\n"
             << endl;
    }

    //-----------------------------------------------------------------------------
    //  add all int value in vector and return
    //-----------------------------------------------------------------------------
    {

        vector<int> vec = { 12, 19, 10, 3 };
        int result = accumulate(vec.cbegin(), vec.cend(), 0);
        cout << "Accumulate the vec is " << result << ".\n"
             << endl;
    }

    //-----------------------------------------------------------------------------
    //  add all string value in vector and return
    //-----------------------------------------------------------------------------
    {
        vector<string> vec = { "hello ", "accumulate", "!" };
        string result = accumulate(vec.cbegin(), vec.cend(), string(""));
        cout << "Accumulate the vec is \"" << result << "\".\n"
             << endl;
    }

    //-----------------------------------------------------------------------------
    //  compare two int vector with x num
    //-----------------------------------------------------------------------------
    {
        vector<int> vec1 = { 3, 4, 6 };
        vector<int> vec2 = { 3, 4, 6, 2 };
        bool result = equal(vec1.cbegin(), vec1.cend(), vec2.cbegin());
        cout << "vec1 and vec2 is "
             << (result ? "same " : "not same ") << "in " << vec1.size() << " num !\n"
             << endl;
    }
    //-----------------------------------------------------------------------------
    //  compare two string vector with x num
    //-----------------------------------------------------------------------------
    {
        vector<string> vec1 = { "aa", "bb", "cc", "dd" };
        list<const char*> vec2 = { "aa", "bb", "cc", "dd", "ee" };
        bool result = equal(vec1.cbegin(), vec1.cend(), vec2.cbegin());
        cout << "vec1 and vec2 is "
             << (result ? "same " : "not same ") << "in " << vec1.size() << " num !\n"
             << endl;
    }

    //-----------------------------------------------------------------------------
    //  write value to vector
    //-----------------------------------------------------------------------------
    {
        vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int iFillValue = 9;
        fill(vec.begin(), vec.end(), iFillValue);
        cout << "fill the vector<int> with " << iFillValue << ".\n";
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    //-----------------------------------------------------------------------------
    //  write value to vector with x num and y value
    //-----------------------------------------------------------------------------
    {
        vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int iFillValue = 8;
        fill_n(vec.begin(), vec.size(), iFillValue);
        cout << "fill the vector<int> with " << iFillValue << ".\n";
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
} // ----------  end of function main  ----------
