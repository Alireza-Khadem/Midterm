#include<iostream>
#include<vector>
#include "genome.h"
using namespace std;
//function baraye peida kardan palindrom
string pal(string a){
    string temp1 = "",temp2 = "";
    for(int i = 0;i < a.length();i++){
        switch(a[i]){
            case 'A':{
                temp2 += 'T';
                break;
            }
            case 'T':{
                temp2 += 'A';
                break;
            }
            case 'C':{
                temp2 += 'G';
                break;
            }
            case 'G':{
                temp2 += 'C';
                break;
            }
        }
    }
    for(int i = temp2.length() - 1;i >= 0;i--){
        temp1 += temp2[i];
    }
    return temp1;
}
class Cell:Genome
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
    void findPalindromes(int);
    vector<Genome> get_chromosomes(){
        return this->chromosomes;
    }
};
//method ijad chromosome jadid
void Cell::addChromosome(Genome g)
{
    chromosomes.push_back(g);
}
//method marg cell
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
//jahesh koochak
void Cell::smallJump(char A, char C, int n, int m)
{
    chromosomes[m-1].smallJump(A, C, n);
}
//jahesh bozorg
void Cell::bigJump(string s1, int n, string s2, int m)
{
    chromosomes[n-1].bigJump(s1, s2);
    chromosomes[m-1].bigJump(s2, s1);
}
//jahesh makoos
void Cell::reverseJump(string s1, int n)
{
    chromosomes[n-1].reverseJump(s1);
}
//method pida kardan palindrom
void Cell::findPalindromes(int num)
{
    for(int NA = 0;NA < 3;NA++){
        vector<string> pals = {};
        string n,m;
        if(NA == 0){
            n = chromosomes[num - 1].getRNA();
            m = "RNA";
        }
        else if(NA == 1){
            n = chromosomes[num - 1].getDNA().first;
            m = "First str of DNA";
        }
        else{
            n = chromosomes[num - 1].getDNA().second;
            m = "Sec str of DNA";
        }
        for(int j = 0;j < n.length() - 2;j++){
            for(int i = 3;i <= n.length() - j;i++){
                string temp = "";
                temp = n.substr(j,i);
                if(temp == (pal(temp))){
                    pals.push_back(temp);
                }
            }
        }
        cout << m << ": [ ";
        for(int i = 0;i < pals.size();i++){
            cout << pals[i] << " ";
        }
        cout << "]" << endl;
    }
}