#include <iostream>
#include "animal.h"
using namespace std;
int main() {
    Animal animal1,animal2;
    int choose,anim;
    //choose->kari ke gharar ast anjam shavad
    //anim->shomare animal
    while(choose != -1){
        cout << "which animal 1 or 2: ";
        cin >> anim;
        cout << "choose what to do:\n "
                "0.Display DNA/RNA of chromosome\n"
                "1.Add Chromosome\n"
                "2.Make DNA from RNA\n"
                "3.Small Mutation\n"
                "4.Reverse Mutation\n"
                "5.Big Mutation\n"
                "6.Check Dead Cells\n"
                "7.Find Palindormes\n"
                "8.Similarity of animals\n"
                "9.Equality of animals\n"
                "10.Asexual reproduction\n"
                "11.Sexual reproduction\n"
                "12.Enter Virus\n";
        cin >> choose;
        //baresi entekhab va anjam amal marbot
        switch(choose){
            case 0:{
                int chr;
                cout << "Which chromosome: ";
                cin >> chr;
                if(anim == 1){
                    cout << "RNA:\n" << animal1.c.get_chromosomes()[chr - 1].getRNA()
                         << endl << "DNA:\n" << animal1.c.get_chromosomes()[chr - 1].getDNA().first
                         << endl << animal1.c.get_chromosomes()[chr - 1].getDNA().second << endl;
                }
                else{
                    cout << "RNA:\n" << animal2.c.get_chromosomes()[chr - 1].getRNA()
                         << endl << "DNA:\n" << animal2.c.get_chromosomes()[chr - 1].getDNA().first
                         << endl << animal2.c.get_chromosomes()[chr - 1].getDNA().second << endl;
                }
                break;
            }
            case 1:{
                Genome gen;
                Cell c1,c2;
                string RNA,DNA_1,DNA_2;
                DNAA dna;
                int count;
                //daryaft tedad chromosome ha va mohtava gen
                cout << "how many chromosome: ";
                cin >> count;
                for(int i = 0;i < count;i++){
                    cout << "Enter RNA and DNA_1 and DNA_2: ";
                    cin >> RNA >> DNA_1 >> DNA_2;
                    dna.first = DNA_1;
                    dna.second = DNA_2;
                    gen.setter(RNA,dna);
                    if(anim == 1){
                        c1.addChromosome(gen);
                        animal1.set_cell(c1);
                    }
                    else if(anim == 2){
                        c2.addChromosome(gen);
                        animal2.set_cell(c2);
                    }
                }
                break;
            }
            case 2:{
            	//entekhab chromosome va method sakht dna az rna
                int num;
                cout << "which chromosome: ";
                cin >> num;
                if(anim == 1){
                    cout << animal1.c.get_chromosomes()[num - 1].getRNA()
                    << endl << animal1.c.get_chromosomes()[num - 1].createDNAfromRNA() << endl;
                }
                else if(anim == 2){
                    cout << animal2.c.get_chromosomes()[num - 1].getRNA()
                    << endl << animal2.c.get_chromosomes()[num - 1].createDNAfromRNA() << endl;
                }
                break;
            }
            case 3:{
            	//method jahesh koochak
                string NA;
                char first,second;
                int count,num;
                cout << "which chromosome: ";
                cin >> num;
                cout << "RNA or DNA: ";
                cin >> NA;
                cout << "Enter first char and sec char and count: ";
                cin >> first >> second >> count;
                if(anim == 1){
                    animal1.c.smallJump(NA,first,second,count,num);
                }
                else if(anim == 2){
                    animal2.c.smallJump(NA,first,second,count,num);
                }
                break;
            }
            case 4:{
            	//method jahesh makoos
                string str;
                int num;
                cout << "which chromosome: ";
                cin >> num;
                cout << "Enter str: ";
                cin >> str;
                if(anim == 1){
                    animal1.c.reverseJump(str,num);
                }
                else if(anim == 2){
                    animal2.c.reverseJump(str,num);
                }
                break;
            }
            case 5:{
                //method jahesh bozorg bein do chromosome
                string first,second;
                int num1,num2;
                cout << "which chromosomes: ";
                cin >> num1 >> num2;
                cout << "Enter first str and sec str: ";
                cin >> first >> second;
                if(anim == 1){
                    animal1.c.bigJump(first,num1,second,num2);
                }
                else if(anim == 2){
                    animal2.c.bigJump(first,num1,second,num2);
                }
                break;
            }
            case 6:{
            	//method marg cell
                if(anim == 1){
                    cout << "Cell befor death: " << animal1.c.get_chromosomes().size() << endl;
                    animal1.c.cellDeath();
                    cout << "Cell after death: " << animal1.c.get_chromosomes().size() << endl;
                }
                else if(anim == 2){
                    cout << "Cell befor death: " << animal2.c.get_chromosomes().size() << endl;
                    animal2.c.cellDeath();
                    cout << "Cell after death: " << animal2.c.get_chromosomes().size() << endl;
                }
                break;
            }
            case 7:{
            	//method palindrom yab
                int num;
                cout << "which chromosome: ";
                cin >> num;
                if(anim == 1){
                    animal1.c.findPalindromes(num);
                }
                else if(anim == 2){
                    animal2.c.findPalindromes(num);
                }
                break;
            }
            case 8:{
            	//method tashaboh genetic bein do animal
                cout << "Similarity: " << animal1.Similarity(animal2) << "%" << endl;
                break;
            }
            case 9:{
            	//method az yek goone boodan do animal
                if(animal1==animal2){
                    cout << "They are equal" << endl;
                }
                else{
                    cout << "They are not equal" << endl;
                }
                break;
            }
            case 10:{
            	//method tolid mesl gheir jensy
                cout << "Asexual reproduction done!" << endl;
                cout << "Similarity of child: " << animal1.Tmgj().Similarity(animal1) << "%" << endl;
                break;
            }
            case 11:{
            	//method tolid mesl jensy
                cout << "Sexual reproduction done!" << endl;
                if(anim == 1){
                    cout << "Similarity with first anim: " << (animal1 + animal2).Similarity(animal1) << endl;
                    cout << "Similarity with second anim: " << (animal1 + animal2).Similarity(animal2) << endl;
                }
                else{
                    cout << "Similarity with first anim: " << (animal2 + animal1).Similarity(animal1) << endl;
                    cout << "Similarity with second anim: " << (animal2 + animal1).Similarity(animal2) << endl;
                }
                break;
            }
            case 12:{
            	//virus
                string RNA;
                bool temp;
                cout << "Enter virus RNA: ";
                cin >> RNA;
                Virus virus(RNA);
                if(anim == 1){
                    temp = virus.is_dangerous(animal1);
                }
                else{
                    temp = virus.is_dangerous(animal2);
                }
                if(temp){
                    cout << "virus is dangerous!" << endl;
                }
                else{
                    cout << "Virus is not dangerous" << endl;
                }
                break;
            }
        }
    }
}