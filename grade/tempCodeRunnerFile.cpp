#include<iostream>
#include <fstream>
#include <sstream> 
#include <vector>
#include<list>

using namespace std;

void supersplit(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
    std::string::size_type pos1, pos2;
    size_t len = s.length();
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.emplace_back(s.substr(pos1, pos2-pos1));
 
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != len)
        v.emplace_back(s.substr(pos1));
}

void read()
{
    ifstream ifs;
    ifs.open("record.txt", ios::in);
    string temp;
    vector<float> score;
    vector<float> weight;
    float tweight = 0;
    
    while(getline(ifs, temp) && temp.length() > 1)
    {
        vector<string> tempv;
        supersplit(temp, tempv, " ");
        cout << atof(tempv.at(0).data()) << " " << atof(tempv.at(1).data()) << endl;
        score.push_back(atof(tempv.at(0).data()));
        weight.push_back(atof(tempv.at(1).data()));
        tweight += atof(tempv.at(1).data());
    }

    
    double result = 0;
    for(vector<float>::iterator it1 = score.begin(), it2 = weight.begin(); it1 != score.end() || it2 != weight.end();it1++, it2++)
    {
        result += *it1 * (*it2 / tweight);
    }
    
    cout << result;
}

int main()
{
    read();
    return 0;
}


void write()
{
    ofstream ofs;
    ofs.open("record.txt",ios::app);

    list<float> score;
    list<float> weight;
    float temp;
    while(cin >> temp && abs(temp + 1) > 0.01)
    {
        score.push_back(temp);
    }
    while(cin >> temp && abs(temp + 1) > 0.01)
    {
        weight.push_back(temp);
    }
    for(list<float>::iterator it1 = score.begin(), it2 = weight.begin(); it1 != score.end() || it2 != weight.end();it1++, it2++)
    {
        ofs << *it1 << " " << * it2 << endl;
    }
}