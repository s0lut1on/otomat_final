#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include "otomatobj.h"
#include <vector>

using namespace std;

int main()
{
    vector<string> m_alphabet;
    m_alphabet.push_back("A");
    m_alphabet.push_back("B");
    m_alphabet.push_back("C");
    m_alphabet.push_back("D");
    m_alphabet.push_back("E");
    m_alphabet.push_back("F");
    m_alphabet.push_back("G");
    m_alphabet.push_back("H");
    vector<char> m_state;
    m_state.push_back('0');
    m_state.push_back('1');
    string m_start = "A";
    vector<string> m_end;
    m_end.push_back("C");

    otomatObj obj;
    obj.setAlphabet(m_alphabet);
    obj.setState(m_state);
    obj.setStart(m_start);
    obj.setEnd(m_end);
    /*
    obj.addRule("S", 'a', "S1");
    obj.addRule("S1", 'a', "S1");
    obj.addRule("S1", 'a', "S2");
    obj.addRule("S2", 'b', "S3");
    obj.addRule("S3", 'c', "S3");
    obj.addRule("S3", 'c', "S4");
    */
    //obj.buildOtomat();

    obj.addRule("A", '0', "B");
    obj.addRule("A", '1', "F");
    obj.addRule("B", '1', "C");
    obj.addRule("B", '0', "G");
    obj.addRule("C", '1', "C");
    obj.addRule("C", '0', "A");
    obj.addRule("D", '0', "C");
    obj.addRule("D", '1', "G");
    obj.addRule("E", '1', "F");
    obj.addRule("E", '0', "H");
    obj.addRule("F", '1', "G");
    obj.addRule("F", '0', "C");
    obj.addRule("G", '0', "G");
    obj.addRule("G", '1', "E");
    obj.addRule("H", '0', "G");
    obj.addRule("H", '1', "C");
    obj.minimum();

    return 0;
}
