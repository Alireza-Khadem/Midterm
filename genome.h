//genome header
#include <iostream>
#include<vector>
using namespace std;
//in function baraye reverse kardan reshte estafade mishavad
string reverse(string a){
    string temp;
    for(int i = a.length() - 1;i >= 0;i--){
        temp += a[i];
    }
    return temp;
}
//tarif class genome
class Genome{
private:
    string RNA = "";
    vector<string> DNA;
public:
    //setter rna & dna
    void Setter(string RNA,string DNA_1,string DNA_2){
        this->RNA = RNA;
        this->DNA = {DNA_1,DNA_2};
    }
    //bargardandan rna
    string GetRNA(){
        return this->RNA;
    }
    //bargardandan dna
    vector<string> GetDNA(){
        return this->DNA;
    }
    //sakht dna az rna
    string DNA_Maker(string RNA){
        //char ha ra yeki yeki mokamel mishavad
        string temp = "";
        for(int i = 0;i < RNA.length();i++){
            if(RNA[i] == 'A'){
                temp += 'T';
            }
            else if(RNA[i] == 'T'){
                temp += 'A';
            }
            else if(RNA[i] == 'C'){
                temp += 'G';
            }
            else if(RNA[i] == 'G'){
                temp += 'C';
            }
        }
        return temp;
    }
    //method jahesh koockak
    void S_Mut(string _NA,char c1,char c2,int num){
        //daryaft rna\dna va char aval va char dovom va tedad
        int counter = 0;
        //agar rna bood vared in shart mishavad
        if(_NA == "RNA"){
            for(int i = 0;i < RNA.length();i++){
                if(RNA[i] == c1){
                    RNA[i] = c2;
                    counter++;
                }
                if(counter == num){
                    cout << "Small Mutation Done!" << endl;
                    break;
                }
            }
        }
        //agar dna bood vared in shart mishavad
        else if(_NA == "DNA"){
            char j;
            switch(c2){
                case 'T':
                    j = 'A';
                    break;
                case 'A':
                    j = 'T';
                    break;
                case 'G':
                    j = 'C';
                    break;
                case 'C':
                    j = 'G';
                    break;
            }
            for(int i = 0;i < DNA[0].length();i++){
                if(DNA[0][i] == c1){
                    DNA[0][i] = c2;
                    DNA[1][i] = j;
                    counter++;
                }
                else if(DNA[1][i] == c1){
                    DNA[1][i] = c2;
                    DNA[0][i] = j;
                    counter++;
                }
                if(counter == num){
                    cout << "Small Mutation Done!" << endl;
                    break;
                }
            }
        }
    }
    //method jahesh bozorg
    void B_Mut(string t,string word,string input){
        //daryaft rna\dna va ebarat aval va dovom
        string temp;
        //agar dna bood vared in shart mishavad
        if(t == "DNA"){
            if(DNA[0].find(word) != -1){
                int index = DNA[0].find(word);
                DNA[0].replace(index,word.length(),input);
                DNA[1].replace(index,word.length(), DNA_Maker(input));
                cout << "Big Mutation Done!" << endl;
            }
            else if(DNA[1].find(word) != -1){
                int index = DNA[1].find(word);
                DNA[1].replace(index,word.length(),input);
                DNA[0].replace(index,word.length(), DNA_Maker(input));
                cout << "Big Mutation Done!" << endl;
            }
            else{
                cout << "No Match!" << endl;
            }
        }
        //agar rna bood vared in shart mishavad
        else{
            if(RNA.find(word) != -1){
                RNA.replace(RNA.find(word),word.length(),input);
                cout << "Big Mutation Done!" << endl;
            }
            else{
                cout << "No Match!" << endl;
            }
        }
    }
    //method jahesh makoos
    void R_Mut(string t,string word){
        //daryaft rna\dna va ebarat
        if(t == "RNA"){
            int index = RNA.find(word);
            if(index != -1){
                RNA.replace(index,word.length(), reverse(word));
                cout << "Reverse Mutation Done!" << endl;
            }
            else{
                cout << "No Match!" << endl;
            }
        }
        else{
            if(DNA[0].find(word) != -1){
                int index = DNA[0].find(word);
                DNA[0].replace(index,word.length(), reverse(word));
                DNA[1].replace(index,word.length(), reverse(DNA_Maker(word)));
                cout << "Reverse Mutation Done!" << endl;
            }
            else if(DNA[1].find(word) != -1){
                int index = DNA[1].find(word);
                DNA[1].replace(index,word.length(), reverse(word));
                DNA[0].replace(index,word.length(), reverse(DNA_Maker(word)));
                cout << "Reverse Mutation Done!" << endl;
            }
            else{
                cout << "No Match!" << endl;
            }
        }
    }
};