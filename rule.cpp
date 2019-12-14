#include "rule.h"

rule::rule()
{

}

void rule::addRule(string input, char state, string output)
{
    listInput.push_back(input);
    listState.push_back(state);
    listOutput.push_back(output);
}

vector<string> rule::getRule(string input, char state)
{
    vector<string> result;
    for (int i=0; i<listInput.size(); i++) {
        if (listInput.at(i) == input) {
            if (listState.at(i) == state)
                result.push_back(listOutput.at(i));
        }
    }
    return result;
}

vector<string> rule::getListInput() const
{
    return listInput;
}

void rule::addRule(vector<string> input, char state, vector<string> output)
{
    listInputDonDinh.push_back(input);
    listStateDonDinh.push_back(state);
    listOutputDonDinh.push_back(output);
}
