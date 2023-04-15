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
    Genome(string, DNAA);
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

    for (int i = 0; i < RNA.length(); i++)
    {
        if (RNA[i] == 'A')
        {
            resultDNA += 'T';
        }
        else if (RNA[i] == 'T')
        {
            resultDNA += 'A';
        }
        else if (RNA[i] == 'C')
        {
            resultDNA += 'G';
        }
        else if (RNA[i] == 'G')
        {
            resultDNA += 'C';
        }
    }

    cout << "DNA: " << resultDNA << endl;
}

void Genome::smallJump(char A, char C, int n)
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
    if (RNA.find(s1) != string::npos)
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
                    DNA.second[i + j] = 'T';
                }
                else if (s2[j] == 'T')
                {
                    DNA.second[i + j] = 'A';
                }
                else if (s2[j] == 'C')
                {
                    DNA.second[i + j] = 'G';
                }
                else
                {
                    DNA.second[i + j] = 'C';
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
                    DNA.first[i + j] = 'T';
                }
                else if (s2[j] == 'T')
                {
                    DNA.first[i + j] = 'A';
                }
                else if (s2[j] == 'C')
                {
                    DNA.first[i + j] = 'G';
                }
                else
                {
                    DNA.first[i + j] = 'C';
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
                    DNA.second[i + j] = 'T';
                }
                else if (s1[j] == 'T')
                {
                    DNA.second[i + j] = 'A';
                }
                else if (s1[j] == 'C')
                {
                    DNA.second[i + j] = 'G';
                }
                else
                {
                    DNA.second[i + j] = 'C';
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
                    DNA.first[i + j] = 'T';
                }
                else if (s1[j] == 'T')
                {
                    DNA.first[i + j] = 'A';
                }
                else if (s1[j] == 'C')
                {
                    DNA.first[i + j] = 'G';
                }
                else
                {
                    DNA.first[i + j] = 'C';
                }
            }

            break;
        }
    }
}

class Cell :Genome
{
private:
    int numberOfChromosomes;
    vector<Genome> chromosomes;
public:
    void addChromosome(Genome);
    void cellDeath();
    void smallJump(char, char, int, int);
    void bigJump(string, int, string, int);
    void reverseJump(string, int);
    void findPalindromes();
};

void Cell::addChromosome(Genome g)
{
    chromosomes.push_back(g);
}

void Cell::cellDeath()
{
    int wrongPair = 0;
    int atPair = 0;
    int cgPair = 0;

    for (Genome chromosome : chromosomes)
    {
        DNAA DNA = chromosome.getDNA();

        for (int i = 0; i < DNA.first.length(); i++)
        {
            if ((DNA.first[i] == 'A' || DNA.second[i] == 'T') || (DNA.first[i] == 'T' && DNA.second[i] == 'A'))
            {
                atPair++;
            }
            else if ((DNA.first[i] == 'C' || DNA.second[i] == 'G') || (DNA.first[i] == 'G' || DNA.second[i] == 'C'))
            {
                cgPair++;
            }
            else
            {
                wrongPair++;
            }
        }

        if (wrongPair > 5 || 3 * atPair > cgPair)
        {
            delete this;
        }
    }
}

void Cell::smallJump(char A, char C, int n, int m)
{
    chromosomes[m - 1].smallJump(A, C, n);
}

void Cell::bigJump(string s1, int n, string s2, int m)
{
    chromosomes[n - 1].bigJump(s1, s2);
    chromosomes[m - 1].bigJump(s2, s1);
}

void Cell::reverseJump(string s1, int n)
{
    chromosomes[n - 1].reverseJump(s1);
}

void Cell::findPalindromes()
{
}

int main()
{
    /*
    int input;
    Genome g1;
    string RNA,DNA_1,DNA_2;
    string w1,w2,temp,t;
    cout << "Enter RNA: " << endl;
    cin >> RNA;
    cout << "Enter DNA: " << endl;
    cin >> DNA_1 >> DNA_2;
    g1.Setter(RNA,DNA_1,DNA_2);
    while(input != 5)
    {
        cout << "choose-> \n 0.show RNA & DNA \n 1.Make DNA \n 2.Big Mutation \n 3.Small Mutation \n 4.Reverse Mutation \n 5.Exit" << endl;
        cin >> input;
        switch (input)
        {
        case 0:
            cout << "RNA: " << endl << g1.GetRNA() << endl;
            cout << "DNA: " << endl << g1.GetDNA()[0] << endl << g1.GetDNA()[1] << endl;
            break;
        case 1:
            cout << g1.GetRNA() << endl;
            cout << g1.DNA_Maker(RNA) << endl;
            break;
        case 2:
            cout << "Enter DNA or RNA: ";
            cin >> temp;
            cout << "Enter part: ";
            cin >> w1;
            cout << "Enter string: ";
            cin >> w2;
            g1.B_Mut(temp,w1,w2);
            break;
        case 4:
            cout << "Enter DNA or RNA: ";
            cin >> temp;
            cout << "Enter part: ";
            cin >> w1;
            g1.R_Mut(temp,w1);
            break;
        case 3:
            int count;
            char t1, t2;
            string ch;
            cout << "Enter DNA or RNA: ";
            cin >> ch;
            cout << "Enter first char: ";
            cin >> t1;
            cout << "Enter sec char: ";
            cin >> t2;
            cout << "Enter how many times: ";
            cin >> count;
            g1.S_Mut(ch,t1, t2, count);
            break;
        }
    }
    */

    return 0;
}