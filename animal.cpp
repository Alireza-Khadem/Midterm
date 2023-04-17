#include <iostream>
#include "cell.h"
using namespace std;
//function baraye ijad mokamel reshteh
//function baraye peyda kardan bozorgtarin zir reshte moshtarak(virus)
string LCSubStr(string X, string Y){
    int m = X.length(),n = Y.length(),result = 0,end,len[2][n + 1],currRow = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                len[currRow][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1]) {
                len[currRow][j] = len[1 - currRow][j - 1] + 1;
                if (len[currRow][j] > result) {
                    result = len[currRow][j];
                    end = i - 1;
                }
            }
            else {
                len[currRow][j] = 0;
            }
        }
        currRow = 1 - currRow;
    }
    if (result == 0){
        return "-1";
    }
    return X.substr(end - result + 1, result);
}
class Animal: private Cell{
public:
    Cell c;
    void set_cell(Cell);
    float Similarity(Animal a);
    bool operator==(Animal a);
    Animal Tmgj();
    Animal operator+(Animal);
    friend class Virus;
};
//setter baraye cell animal
void Animal::set_cell(Cell input){
    this->c = input;
}
//method tashaboh genetic
float Animal::Similarity(Animal a){
    float counter = 0,total = 0;
    if(a.c.get_chromosomes().size() == 0){
        return 0.00;
    }
    for(int i = 0;i < c.get_chromosomes().size();i++){
        for(int j = 0;j < a.c.get_chromosomes().size();j++){
            for(int k = 0;k < c.get_chromosomes()[i].getDNA().first.length();k++){
                if(c.get_chromosomes()[i].getDNA().first[k] == a.c.get_chromosomes()[j].getDNA().first[k]){
                    counter++;
                }
                if(c.get_chromosomes()[i].getDNA().second[k] == a.c.get_chromosomes()[j].getDNA().second[k]){
                    counter++;
                }
                total++;
            }
        }
    }
    return (counter / total) * 100;
}
//baresi yek goone boodan (baz nevisi ==)
bool Animal::operator==(Animal a){
    if(Similarity(a) >= 70 && c.get_chromosomes().size() == a.c.get_chromosomes().size()){
        return true;
    }
    else{
        return false;
    }
}
//method tolid mesl gheir jensi
Animal Animal::Tmgj(){
    Animal child,a;
    a.c = this->c;
    Cell temp = this->c;
    vector<int> nums;
    srand(time(0));
    while(child.Similarity(a) <= 70){
        int r = rand() % temp.get_chromosomes().size();
        if(find(nums.begin(), nums.end(), r) == nums.end()){
            child.c.addChromosome(temp.get_chromosomes()[r]);
            nums.push_back(r);
        }
        else{
            continue;
        }
    }
    while(child.c.get_chromosomes().size() < temp.get_chromosomes().size()){
        int r = rand() % temp.get_chromosomes().size();
        child.c.addChromosome(temp.get_chromosomes()[r]);
    }
    return child;
}
//method tolid mesl jensi(baz nevisi +)
Animal Animal::operator+(Animal a){
    Animal child,n_anim1,n_anim2;
    vector<int> nums1,nums2;
    n_anim1 = Animal::Tmgj();
    n_anim2 = a.Tmgj();
    srand(time(0));
    while(a.Similarity(child) < 70 || Animal::Similarity(child) < 70){
        while(child.c.get_chromosomes().size() < (n_anim1.c.get_chromosomes().size() / 2)){
            int r1 = rand() % (n_anim1.c.get_chromosomes().size() / 2);
            if(find(nums1.begin(), nums1.end(), r1) == nums1.end()){
                child.c.addChromosome(n_anim1.c.get_chromosomes()[r1]);
                nums1.push_back(r1);
            }
            else{
                continue;
            }
        }
        while(child.c.get_chromosomes().size() <= n_anim2.c.get_chromosomes().size()){
            int r2 = rand() % n_anim2.c.get_chromosomes().size();
            if(find(nums2.begin(), nums2.end(), r2) == nums2.end()){
                child.c.addChromosome(n_anim2.c.get_chromosomes()[r2]);
                nums2.push_back(r2);
            }
            else{
                continue;
            }
        }
        if(a.Similarity(child) < 70 && Animal::Similarity(child) < 70){
            Cell temp;
            child.c = temp;
            nums1 = {};
            nums2 = {};
            n_anim1 = Animal::Tmgj();
            n_anim2 = a.Tmgj();
        }
    }
    return child;
}
//tarif virus
class Virus : public Genome{
private:
    Genome v;
public:
    Virus(string rna){
        DNAA temp;
        temp.first = "" , temp.second = "";
        v.setter(rna,temp);
    }
    bool is_dangerous(Animal a){
        vector<Genome> ch = a.c.get_chromosomes();
        string temp = LCSubStr(ch[0].getDNA().first,ch[1].getDNA().first);
        for(int i = 2;i < ch.size();i++){
            temp = LCSubStr(temp,ch[i].getDNA().first);
        }
        cout << "largest common substr: " << temp << endl;
        cout << "Virus RNA: " << v.getRNA() << endl;
        cout << "find: " << v.getRNA().find(temp) << endl;
        if(v.getRNA().find(temp) != -1 || v.getRNA().find(mok_saz(temp)) != -1){
            return true;
        }
        else{
            return false;
        }
    }
};