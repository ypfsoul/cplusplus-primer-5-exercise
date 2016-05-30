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
//         Name:  elimDups
//  Description:  remove repeat words in vector
// =====================================================================================
void elimDups(vector<string>& words)
{
    //按字典排序
    sort(words.begin(), words.end());
    //unique 重排输入范围，使得单词只出现一次，并排在前面，多余的单词在后面
    //多余单词的起始位置
    auto start_repeat = unique(words.begin(), words.end());
    //删除重复单词
    words.erase(start_repeat, words.end());
}
// -----  end of function elimDups  -----




// ===  FUNCTION  ======================================================================
//         Name:  isShorter
//  Description:
// =====================================================================================
bool isShorter(const string& str1, const string& str2)
{
    return str1.size() < str2.size();
}
// -----  end of function isShorter  -----




// ===  FUNCTION  ======================================================================
//         Name:  biggies
//  Description:  select string who's size > x
// =====================================================================================
void biggies(vector<string>& words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), isShorter);
    //获取第一个大于给定sz的迭代器(find_if第三个参数只支持一元谓词，但是这里需要额外的sz变量，所以用lamda表达式实现)
    auto result = find_if(words.cbegin(), words.cend(), [sz](const string& str) -> bool { return str.size() > sz; });
    if (result != words.cbegin())
    {
        words.erase(words.begin(), result - 1);
    }
}
// -----  end of function biggies  -----





// ===  FUNCTION  ======================================================================
//         Name:  make_plural
//  Description:
// =====================================================================================
string make_plural(size_t ctr, const string& word, const string& ending)
{
    return (ctr > 1) ? word + ending : word;
}
// -----  end of function make_plural  -----





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
        for (unsigned long i = 0; i < vec.size(); i++)
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
        for (unsigned long i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    //-----------------------------------------------------------------------------
    //  add a value to vector by back_inserter
    //-----------------------------------------------------------------------------
    {
        vector<int> vec = { 1, 2, 3, 4, 5 };
        auto it = back_inserter(vec);
        *it = 6;
        cout << "Add value to vector by back_inserter.\n";
        for (unsigned long i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    //-----------------------------------------------------------------------------
    // add value to vector with fill_n and back_inserter
    //-----------------------------------------------------------------------------
    {
        vector<int> vec = { 1, 2, 3, 4, 5 };
        auto it = back_inserter(vec);
        fill_n(it, 5, 6);
        cout << "Add value to vector with fill_n and back_inserter.\n";
        for (unsigned long i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    //-----------------------------------------------------------------------------
    //  copy array1 to array2
    //-----------------------------------------------------------------------------
    {
        int iArray1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
        int iArray2[sizeof(iArray1) / sizeof(int)];
        copy(begin(iArray1), end(iArray1), iArray2);
        cout << "copy 10 value of array1 to array2.\n";
        for (unsigned int i = 0; i < sizeof(iArray1) / sizeof(int); i++)
        {
            cout << iArray2[i] << " ";
        }
        cout << endl;
    }

    //-----------------------------------------------------------------------------
    //  replace a old value in vector with a new value
    //-----------------------------------------------------------------------------
    {
        vector<int> vec = { 1, 1, 2, 2, 33, 33, 12, 12 };
        replace(vec.begin(), vec.end(), 1, 3);
        cout << "Replace 1 with 3.\n";
        for (unsigned long i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    //-----------------------------------------------------------------------------
    //  replace value in vector and save to a new vector
    //-----------------------------------------------------------------------------
    {
        vector<int> vec1 = { 1, 1, 2, 2, 3, 3 };
        vector<int> vec2;
        replace_copy(vec1.cbegin(), vec1.cend(), back_inserter(vec2), 1, 4);
        cout << "Replace value in vec1 and save to vec2.\n";
        for (unsigned long i = 0; i < vec2.size(); i++)
        {
            cout << vec2[i] << " ";
        }
        cout << endl;
    }

    //-----------------------------------------------------------------------------
    //  remove repeat words
    //-----------------------------------------------------------------------------
    {

        cout << "Remove repeat words.\n";
        vector<string> vec = { " two ", " one ", " three ", " two ", " three ", " four ", " five " };
        //字典排序，移除相同元素
        //elimDups(vec);
        //按大小排序，大小相同的维持字典序列
        //stable_sort(vec.begin(), vec.end(), isShorter);
        //筛选长度大于6的字符串
        int iFlagSize = 6;
        biggies(vec, iFlagSize);
        unsigned long iCount = vec.size();
        //for (unsigned long i = 0; i < vec.size(); i++)
        //{
        //cout << vec[i] << "";
        //}
        //循环打印容器的简便写法
        for_each(vec.cbegin(), vec.cend(), [](const string& str) -> void { cout << str << " "; });
        cout << '\n';
        cout << iCount << " " << make_plural(iCount, "word", "s")
             << " of length " << iFlagSize << " or longer!";
        cout << endl;
    }




    return EXIT_SUCCESS;
}
// ----------  end of function main  ----------
