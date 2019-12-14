#include "otomatobj.h"

otomatObj::otomatObj()
{

}
void otomatObj::addRule(string input, char state, string output)
{
    if (contain(m_alphabet, input) && contain(m_alphabet, output) && contain(m_state, state))
    {
        m_ruleObj.addRule(input, state, output);
    }
    else
    {
        cout << "Can't add rule";
    }
}

void otomatObj::setState(vector<char> state)
{
    m_state = state;
}

void otomatObj::setAlphabet(vector<string> alphabet)
{
    m_alphabet = alphabet;
}

void otomatObj::setStart(string start)
{
    m_start = start;
}

void otomatObj::setEnd(vector<string> end)
{
    m_end = end;
}

bool otomatObj::compare(string input)
{
    if (input.length() == 0)
    {
        cout << "Not found input";
        return false;
    }

    string item1 = m_ruleObj.getRule(m_start, input.at(0)).at(0);
    int i = 1;
    while (i < input.length())
    {
        item1 = m_ruleObj.getRule(item1, input.at(i)).at(0);
        if (item1 == "")
        {
            return false;
        }
        i++;
    }
    if (i == input.length())
    {
        return true;
    }
    return false;
}

bool otomatObj::contain(vector<string> list, string input)
{
    for (int i=0; i<list.size(); i++)
    {
        if (input == list.at(i))
            return true;
    }
    return false;
}

bool otomatObj::contain(vector<char> list, char input)
{
    for (int i=0; i<list.size(); i++)
    {
        if (input == list.at(i))
            return true;
    }
    return false;
}

void otomatObj::buildOtomat()
{
    vector<vector<string> > alphabet_don_dinh;
    vector<string> a0;
    a0.push_back(m_start);
    alphabet_don_dinh.push_back(a0);
    vector<char> state_don_dinh = m_state;
    rule rule_don_dinh;

    for (int i=0; i<m_state.size(); i++)
    {
        vector<string> a = m_ruleObj.getRule(m_start, m_state.at(i));
        vector<string> a1 = a;
        if (a1.size() != 0)
        {
            alphabet_don_dinh.push_back(a1);
            rule_don_dinh.addRule(alphabet_don_dinh.at(0), m_state.at(i), a1);
        }
    }
    print(alphabet_don_dinh.at(1));

    int i = 1;
    while (i < alphabet_don_dinh.size())
    {
        for (int k=0; k<m_state.size(); k++)
        {
            vector<string> a1;
            for (int j=0; j< alphabet_don_dinh.at(i).size(); j++)
            {
                vector<string> a = m_ruleObj.getRule(alphabet_don_dinh.at(i).at(j), m_state.at(i));
                a1 = a;
            }
            if (a1.size() != 0)
            {
                if (!contain(alphabet_don_dinh, a1))
                    alphabet_don_dinh.push_back(a1);
                rule_don_dinh.addRule(alphabet_don_dinh.at(i), m_state.at(i), a1);
            }
        }
        i++;
    }
    cout << "List alphabet: " << endl;
    for (i=0; i<alphabet_don_dinh.size(); i++)
    {
        cout << "Item " << i << ":";
        print(alphabet_don_dinh.at(i));
    }
}

bool otomatObj::contain(vector<vector<string> > list, vector<string> input)
{
    for (uint8_t i=0; i<list.size(); i++)
    {
        if (compare(list.at(i), input))
            return true;
    }
    return false;
}

bool otomatObj::compare(vector<string> a, vector<string> b)
{
    for (uint8_t i=0; i<a.size(); i++)
    {
        if (a.at(i) != b.at(i))
            return false;
    }
    return true;
}

bool otomatObj::compare(vector<vector<bool> > a, vector<vector<bool> > b)
{
    for (int i=0; i<a.size(); i++)
    {
        for (int j=0; j<a[i].size(); j++)
        if (a[i][j] != b[i][j])
            return false;
    }
    return true;
}

void otomatObj::print(vector<string> input)
{
    for (uint8_t i=0; i<input.size(); i++)
    {
        cout << input.at(i) << "\t";
    }
    cout << endl;
}

int otomatObj::getIndex(string input, vector<string> input_alphabet)
{
    for (int i=0; i < input_alphabet.size(); i++)
    {
        if (input_alphabet[i] == input)
            return i;
    }
    return -1;
}

void otomatObj::minimum()
{
    vector<string> m_new_alphabet;
    for (int i=0; i<m_alphabet.size(); i++)
    {
        int j = 0;
        while (j < m_alphabet.size())
        {
            for (int k=0; k< m_state.size(); k++)
            {
                if (m_ruleObj.getRule(m_alphabet[j], m_state[k])[0] == m_alphabet[i])
                {
                    j = m_alphabet.size();
                    break;
                }
            }
            j++;
        }
        if (j == m_alphabet.size() + 1)
        {
            m_new_alphabet.push_back(m_alphabet[i]);
        }
    }

    cout << "New alphabet: " << endl;
    print(m_new_alphabet);

    vector<vector<bool> > m_result;
    for (int i=0; i < m_new_alphabet.size(); i++)
    {
        vector<bool> row(m_new_alphabet.size(), true);
        m_result.push_back(row);
    }

    //set cel have end is false
    for (int i=0; i < m_new_alphabet.size() - 1; i++)
    {
        for (int j=i+1; j < m_new_alphabet.size(); j++)
        {
            for (int k=0; k < m_end.size(); k++)
            {
                if (m_new_alphabet[i] == m_end[k] || m_new_alphabet[j] == m_end[k])
                    m_result[j][i] = false;
            }
        }
    }

    compare(m_new_alphabet, m_result);
    vector<vector<bool> > old;
    while (old != m_result)
    {
        old = m_result;
        compare(m_new_alphabet, m_result);
    }

    cout << "-----------------------------------" << endl;
    for (int i=0; i<m_result.size(); i++)
    {
        for (int j=0; j<m_result[i].size(); j++)
        {
            cout << m_result[i][j];
        }
        cout << endl;
    }
}

void otomatObj::compare(vector<string> m_new_alphabet, vector<vector<bool> > &m_result)
{

    for (int i=0; i < m_new_alphabet.size() - 1; i++)
    {
        for (int j=i+1; j < m_new_alphabet.size(); j++)
        {
            for (int k=0; k < m_state.size(); k++)
            {
                string a = m_ruleObj.getRule(m_new_alphabet[i], m_state[k])[0];
                string b = m_ruleObj.getRule(m_new_alphabet[j], m_state[k])[0];
                int index_a = getIndex(a, m_new_alphabet);
                int index_b = getIndex(b, m_new_alphabet);

                if (m_result[index_a][index_b] != true || m_result[index_b][index_a] != true)
                    m_result[j][i] = false;
            }
        }
    }
}
