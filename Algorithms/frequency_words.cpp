#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> findFrequencyWords(string &text){
    map<string, int> frequency;
    string buff;
    for(int i = 0; i < text.size(); i++){
        if (isalpha(text[i])){
            buff += text[i];
        }
        else{
            if (buff.size() > 0){
                frequency[buff]++;
                buff = "";
            }
        }
    }
    if (buff.size() > 0)
        frequency[buff]++;

    return frequency;
}

string findMostFrequentWord(string &text){
    map<string, int> frequency = findFrequencyWords(text);
    string flag;
    int i = 0;
    for(auto &[key, value] : frequency){
        if(value > i){
            i = value;
            flag = key;
        }
    }
    return flag;
}


int main(){
    string text = "cat cat cat dog dog pink";
    cout << findMostFrequentWord(text);

}