#ifndef OTOMATOBJ_H
#define OTOMATOBJ_H

#include <list>
#include <string>
#include "rule.h"
#include <iostream>
#include <vector>

using namespace std;

class otomatObj
{
public:
    otomatObj();

    void addRule(string input, char state, string output);
    void setState(vector<char> state);
    void setAlphabet(vector<string> alphabet);
    void setStart(string start);
    void setEnd(vector<string> end);
    bool contain(vector<string> list, string input);
    bool contain(vector<char> list, char input);
    bool contain(vector<vector<string> > list, vector<string> input);
    bool compare(vector<string> a, vector<string> b);
    bool compare(vector<vector<bool> > a, vector<vector<bool> > b);
    void update(vector<string> m_new_alphabet, vector<vector<bool> > &m_result);
    int getIndex(string input, vector<string> input_alphabet);

    void print(vector<string> input);

    bool compare(string input);
    void buildOtomat();
    void minimum();
private:
    vector<char> m_state;
    vector<string> m_alphabet;
    string m_start;
    vector<string> m_end;
    rule m_ruleObj;

};

#endif // OTOMATOBJ_H
