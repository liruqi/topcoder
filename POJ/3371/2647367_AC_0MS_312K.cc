//POJ 3371
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string vowel("aeiouy");
string delim(".!?:;");
bool isvowel(char c){
    //c=tolower(c);
    for(int i=0;i<vowel.size();i++)
        if(vowel[i]==c)
            return 1;
            return 0;
}

int syllable(string & word){
    int ed=word.size();
    if(ed<=3) return 1;
    
    if(word.rfind("es")==ed-2)
        ed-=2;
    else if(word.rfind("ed")==ed-2)
        ed-=2;
    else if(word.rfind("e")==ed-1 && word.rfind("le")!=ed-2)
        ed-=1;
    string trunc(&word[0], &word[ed]);
    int cnt=0;
    for(int i=0;i<trunc.size();i++){
        if( isvowel( trunc[i]) ){
            cnt++; 
            do
                i++;
            while(i<trunc.size() && isvowel( trunc[i] ));
        }
    }
    return cnt;
}

bool delimiler(char c){
    for(int i=0;i<delim.size();i++)
        if(delim[i]==c)
            return 1;
            return 0;
}

//#define DEB
/*
Only letters of the English alphabet (both lowercase and uppercase), 
common punctuation marks (periods, question and exclamation marks, colons, 
semicolons as well as commas, quotation marks, hyphens and apostrophes)
*/
int main(){
    int i;
    string wd;
    #ifdef DEB
    while(cin>>wd){
        //
        cout<<wd.rfind("es")<<endl;
        cout<<syllable(wd);
    }
    #endif
    int cnt_words=0,cnt_sylls=0,cnt_sents=0;
    while (cin>>wd){
        for(i=0;i<wd.size();i++)wd[i]=tolower(wd[i]);
        cnt_words++;
        char lt=wd[wd.size()-1];
        if(!isalpha(lt)){
            //wd.pop_back();
            wd.erase(wd.size()-1, 1);
            if(delimiler(lt))
                cnt_sents++;
        }
        cnt_sylls+=syllable(wd);
    }
    double wps=(double)cnt_words/cnt_sents;
    wps*=1.015;
    double spw=(double)cnt_sylls/cnt_words;
    spw*=84.6;
    double ans=206.835 - wps - spw;
    printf("%.2lf\n",ans);
    cin>>wd;
    return 0;
}