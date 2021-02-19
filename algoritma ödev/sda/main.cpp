#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <locale.h>
#define guesslong 8
#define source "bba.txt"
#define text "bba - Kopya.txt"
using namespace std;
struct cell {
	string word;
	int scorekar;
	int scorenor;
};
struct word {
	float readword[50];
	float bestenthropy;
	string kelime;
}word1;
cell guess[guesslong];
int num=1;
void addword(){
string newword;
			cout << "please enter the word that kept in your mind ";
			cin>>newword;
			ofstream base;
			base.open(source,ios::app);
			base << endl;
			for(int k=0;newword[k]!=NULL;k++){
                if(newword[k]==-121){
                    base<<char(231);
                    continue;
                }
                if(newword[k]==-97){
                    base<<char(254);
                    continue;
                }
                if(newword[k]==-115){//ý
                    base<<char(253);
                    continue;
                }
                if(newword[k]==-89){//ð
                    base<<char(240);
                    continue;
                }
                if(newword[k]==-108){//ö
                    base<<char(246);
                    continue;
                }
                if(newword[k]==-127){//ü
                    base<<char(252);
                    continue;
                }
                    base<<newword[k];
			}
			base.close();



}
int compare(string word1, string word2){
	int common = 0;
	for (int i = 0; word1[i] != 0; i++) {
		for (int j = 0; word2[j] != 0; j++) {
			if (word1[i] == word2[j] /*|| (word1[i]+32)==word2[j]||(word2[j]+32)==word1[i]*/) {
				common++;
				word2[j] = 1;
				word1[i] = -1;
			}
		}
	}
	return common;
}
int comparekar(string word1, string word2) {
	int common = 0;
	for (int i = 0; word1[i] != 0; i++) {
		for (int j = 0; word2[j] != 0; j++) {
			if (word1[i] == word2[j] /*|| (word1[i]-32)==word2[j]||(word2[j]-32)==word1[i]*/) {
				common++;
			}
		}
	}
	return common;
}
float enthropy(float dizi[]){
	float total = 0;
	float uzunluk = 0;
	float px = 0;
	for (int i = 0; i < 20; i++) {
		uzunluk += dizi[i];
	}
	for (int t = 0; t < 20; t++) {
		if (dizi[t] != 0) {
			px = (dizi[t] / uzunluk);
			total += px * log2(px);
		}
	}
	total *= -1;
	//if(total==0)
	//cout<<"uzunluk:"<<uzunluk<<endl;
	//cout<<"total:"<<total<<endl;
	return total;
}
int getlong(){
	int i = 0;
	string kelime1;
	ifstream income;
	income.open(text);
	for (i = 0; !income.eof(); i++) {
		income >> kelime1;
		if(kelime1=="")
            return i;
	}
	income.close();
	return i;
}
bool isthere(string word){
string kelime;
ifstream income;
income.open(source);
int longness = getlong();
	for (int i = 0; i <= longness; i++) {
		income >> kelime;
		if(kelime==word){
            return true;
		}
	}
income.close();
cout<<"kelime bulunamadý";
return false;
}
int compareall(string kelime){
	ifstream file;
	string kelime2;
	file.open(text);
	int longness = getlong();
	float enth=0;
	for (int i = 0; i < 20; i++) {
		word1.readword[i] = 0;
	}

	for (int i = 0; i < longness; i++){

		file >> kelime2;
		if (longness <= 2){
			word1.kelime = kelime;
			return 1;
		}
		if (kelime == kelime2)continue;
        word1.readword[comparekar(kelime, kelime2)]++;
        //cout<<comparekar(kelime, kelime2)<<" "<<kelime<<" "<<kelime2<<endl;
        enth=enthropy(word1.readword);
        if (enth > word1.bestenthropy){
            word1.kelime = kelime;
            word1.bestenthropy = enth;
		}
		//cout<<kelime<<" "<<kelime2<<" "<<endl;
	}

       /* for(int t=0;t<10;t++)
            cout<<word1.readword[t]<<" ";
        cout<<endl;*/
	file.close();
}
string findword(){//find for best enthropy
	ifstream income;
	string kelime;
	income.open(text);
	int longness = getlong();
	for (int i = 1; i <= longness; i++) {
		income >> kelime;
		//cout<<kelime<<endl;
		compareall(kelime);
	}
	income.close();
	//cout<<getlong()-1;
    //cout<<"word"<<word1.kelime;
	return word1.kelime;
}
string randomword(){
	srand(time(NULL)*time(NULL)*num*num);
	num++;
	long int random = ((rand() % getlong()) + 1);
	ifstream database;
	string kelime;
	database.open(text);
	for (int i = 0; i < random; i++) {
		database >> kelime;
	}
	database.close();
	return kelime;
}
string getrandomword(){
	string kelime1;
	string commo;
	int commo2=0;
	int t = 0;
	int longness = getlong();
	if (longness < 2000) {
		word1.bestenthropy = -1;
		for (int i = 0; i < 40; i++) {
			word1.readword[i] = 0;
		}
		word1.kelime = " ";

		return findword();
	}
	do {
		kelime1 = randomword();
        if(comparekar(kelime1, kelime1)>commo2){
            commo=kelime1;
            commo2=comparekar(kelime1, kelime1);
        }
		t++;
		if (t > 300) {
			t = 0;
			break;
		}
	} while (comparekar(kelime1, kelime1) <= (sizeof(kelime1) + 2));

	return commo;
}
void cleartxt(int number){
	ofstream space;
	ifstream database;
	string kelime3;
	space.open("aaa.txt");
	database.open(text);
	for (int i = 0; !database.eof(); i++) {
		database >> kelime3;
		if ((comparekar(guess[number].word, kelime3) == guess[number].scorekar) &&
			(compare(guess[number].word, kelime3) == guess[number].scorenor) &&
			guess[number].word != kelime3) {
			space << kelime3;
			if (!database.eof()){
				space << endl;
			}
		}
	}
	space.close();
	database.close();
	remove(text);
	rename("aaa.txt", text);
}
int main(){
	setlocale(LC_ALL, "Turkish");
	char usersettings;
	cout<<"1-Pc-user(Computer guess you try to know)"<<endl<<"2-User-Pc(you guess computer tries to know)"<<endl;
	cin>>usersettings;
	if(usersettings=='2'){
        string secretword;
        cin>>secretword;
        for(int f=0;f<sizeof(secretword);f++){
                if(secretword[f]==-121){
                    secretword[f]=char(231);
                    continue;
                }
                if(secretword[f]==-97){
                    secretword[f]=char(254);
                    continue;
                }
                if(secretword[f]==-115){//ý
                    secretword[f]=char(253);
                    continue;
                }
                if(secretword[f]==-89){//ð
                    secretword[f]=char(240);
                    continue;
                }
                if(secretword[f]==-108){//ö
                    secretword[f]=char(246);
                    continue;
                }
                if(secretword[f]==-127){//ü
                    secretword[f]=char(252);
                    continue;
                }
        }
        for (int i = 0; i < guesslong; i++) {
                getchar();
            int longness = getlong();
            cout << "örnek uzay:" << longness << endl;
            guess[i].word = getrandomword();
            if(word1.bestenthropy==0&&longness<10&&longness!=2){
                string wrd;
                ifstream file;
                file.open(text);
                cout<<"Care! All compare of words on dictionary to each other are equal"<< endl;
                for(int k=1;k<longness;k++){
                    file >> wrd;
                    cout<<wrd<<endl;
                }
                cout<<endl;
                    file.close();
            }
            if (longness == 0) {
                addword();
                return 3;
            }
            cout << "Senin tuttuðunu düþündüðüm kelime :" << guess[i].word;
            for (int t = 1; t <= guesslong; t++) {
                cout << endl << t << ". kelime :" << guess[t - 1].word;
            }
            guess[i].scorenor=compare(secretword,guess[i].word);
            guess[i].scorekar=comparekar(secretword,guess[i].word);

            cout<<endl<<"kartezyen"<< guess[i].scorekar<<endl;
            cout<<"normal"<< guess[i].scorenor<<endl;
            cout<<"kelime "<<guess[i].word<<endl;
            cout<<"secretword "<<secretword;
            if(secretword==guess[i].word)
                guess[i].scorenor = -1;
            cout<<endl;
            /*cout << endl << "please enter normal compare";
            cin >> guess[i].scorenor;
            cout<< "please enter cartesian compare";
            cin >> guess[i].scorekar;*/
            if (guess[i].scorenor == -1 || guess[i].scorekar == -1) {
                if (i < 5)
                    cout << endl << "It was the simplest word that i have ever guessed.";
                else if (i == 5)
                    cout << endl << "I am better than you.HaHaa.";
                else if (i == 6)
                    cout << endl << "HuH.It was rough one";
                cout << endl;
                return 2;
            }
            cleartxt(i);
        }
	}
	else if (usersettings=='1'){
        string hlwrd;
        hlwrd=randomword();
        cout<<"secret word is "<<hlwrd<<endl;
        cout<<"please enter word that dictionari include"<<endl;
        for (int t = 1; t <= guesslong; t++) {


                do {
                        cout << endl << t << ". kelime :";
                        cin>>guess[t-1].word;
                }while(!isthere(guess[t-1].word));
                if(guess[t-1].word==hlwrd){
                    cout<<"Congratulations u found secret word"<<endl;
                    return 0;
                }
                guess[t-1].scorekar=comparekar(guess[t-1].word,hlwrd);
                guess[t-1].scorenor=compare(guess[t-1].word,hlwrd);
                cout<<"cartesian compare is:"<<guess[t-1].scorekar<<endl;
                cout<<"normal compare is:"<<guess[t-1].scorenor;
            }
	}
	return 0;
}
