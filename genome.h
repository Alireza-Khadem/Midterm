#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DNAA
{
    string first;
    string second;
};

class Genome
{
private:
    string RNA;
    DNAA DNA;

public:
    Genome();
    Genome(string, DNAA );
    void setter(string, DNAA);
    string getRNA();
    DNAA getDNA();
    void createDNAfromRNA();
    void smallJump(char, char, int);
    void bigJump(string, string);
    void reverseJump(string);
};

Genome::Genome()
{
    this->RNA = "";
    this->DNA.first = "";
    this->DNA.second = "";
}

Genome::Genome(string RNA, DNAA DNA)
{
    this->RNA = RNA;
    this->DNA = DNA;
}

void Genome::setter(string RNA, DNAA DNA)
{
    this->RNA = RNA;
    this->DNA = DNA;
}

string Genome::getRNA()
{
    return this->RNA;
}

DNAA Genome::getDNA()
{
    return this->DNA;
}

void Genome::createDNAfromRNA()
{
    string resultDNA = "";

    for(int i = 0; i < RNA.length(); i++)
    {
        if(RNA[i] == 'A')
        {
            resultDNA += 'T';
        }
        else if(RNA[i] == 'T')
        {
            resultDNA += 'A';
        }
        else if(RNA[i] == 'C')
        {
            resultDNA += 'G';
        }
        else if(RNA[i] == 'G')
        {
            resultDNA += 'C';
        }
    }

    cout << "DNA: " << resultDNA << endl;
}

void Genome::smallJump(char A,char C,int n)
{
    for (int i = 0, c = 0; c < n && i < RNA.length(); i++)
    {
        if (RNA[i] == A)
        {
            RNA[i] = C;
        }

        if (DNA.first[i] == A)
        {
            DNA.first[i] = C;
            if (C == 'A')
            {
                DNA.second[i] = 'T';
            }
            else if (C == 'T')
            {
                DNA.second[i] = 'A';
            }
            else if (C == 'C')
            {
                DNA.second[i] = 'G';
            }
            else if (C == 'G')
            {
                DNA.second[i] = 'C';
            }
        }

        if (DNA.second[i] == A)
        {
            DNA.second[i] = C;
            if (C == 'A')
            {
                DNA.first[i] = 'T';
            }
            else if (C == 'T')
            {
                DNA.first[i] = 'A';
            }
            else if (C == 'C')
            {
                DNA.first[i] = 'G';
            }
            else if (C == 'G')
            {
                DNA.first[i] = 'C';
            }
        }
    }
}

void Genome::bigJump(string s1, string s2)
{
    if(RNA.find(s1) != string::npos)
    {
        int index = RNA.find(s1);
        RNA.replace(index, s1.length(), s2);
    }

    for (int i = 0; i < DNA.first.length(); i++)
    {
        if (DNA.first.substr(i, s1.length()) == s1)
        {
            DNA.first.replace(i, s1.length(), s2);

            for (int j = 0; j < s2.length(); j++)
            {
                if (s2[j] == 'A')
                {
                    DNA.second[i+j] = 'T';
                }
                else if (s2[j] == 'T')
                {
                    DNA.second[i+j] = 'A';
                }
                else if (s2[j] == 'C')
                {
                    DNA.second[i+j] = 'G';
                }
                else
                {
                    DNA.second[i+j] = 'C';
                }
            }

            break;
        }

        if (DNA.second.substr(i, s1.length()) == s1)
        {
            DNA.second.replace(i, s1.length(), s2);

            for (int j = 0; j < s2.length(); j++)
            {
                if (s2[j] == 'A')
                {
                    DNA.first[i+j] = 'T';
                }
                else if (s2[j] == 'T')
                {
                    DNA.first[i+j] = 'A';
                }
                else if (s2[j] == 'C')
                {
                    DNA.first[i+j] = 'G';
                }
                else
                {
                    DNA.first[i+j] = 'C';
                }
            }

            break;
        }
    }
}

void Genome::reverseJump(string s1)
{
    if (RNA.find(s1) != string::npos)
    {
        int index = RNA.find(s1);
        reverse(s1.begin(), s1.end());
        RNA.replace(index, s1.length(), s1);
    }

    for (int i = 0; i < DNA.first.length(); i++)
    {
        if (DNA.first.substr(i, s1.length()) == s1)
        {
            reverse(s1.begin(), s1.end());
            DNA.first.replace(i, s1.length(), s1);

            for (int j = 0; j < s1.length(); j++)
            {
                if (s1[j] == 'A')
                {
                    DNA.second[i+j] = 'T';
                }
                else if (s1[j] == 'T')
                {
                    DNA.second[i+j] = 'A';
                }
                else if (s1[j] == 'C')
                {
                    DNA.second[i+j] = 'G';
                }
                else
                {
                    DNA.second[i+j] = 'C';
                }
            }

            break;
        }

        if (DNA.second.substr(i, s1.length()) == s1)
        {
            reverse(s1.begin(), s1.end());
            DNA.second.replace(i, s1.length(), s1);

            for (int j = 0; j < s1.length(); j++)
            {
                if (s1[j] == 'A')
                {
                    DNA.first[i+j] = 'T';
                }
                else if (s1[j] == 'T')
                {
                    DNA.first[i+j] = 'A';
                }
                else if (s1[j] == 'C')
                {
                    DNA.first[i+j] = 'G';
                }
                else
                {
                    DNA.first[i+j] = 'C';
                }
            }

            break;
        }
    }
}
