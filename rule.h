#ifndef RULE_H
#define RULE_H

#include <list>
#include <string>
#include <vector>
using namespace std;

class rule
{
public:
    rule();
    void addRule(string input, char state, string output);
    vector<string> getRule(string input, char state);

    void addRule(vector<string> input, char state, vector<string> output);

    vector<string> getListInput() const;
private:
    vector<string> listInput;
    vector<char> listState;
    vector<string> listOutput;

    vector<vector<string> > listInputDonDinh;
    vector<vector<string> > listOutputDonDinh;
    vector<char> listStateDonDinh;
};

#endif // RULE_H
