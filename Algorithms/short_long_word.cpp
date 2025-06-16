#include <string>
#include <iostream>
#include <utility>
#include <cctype>

using namespace std;

pair<string, string> findLongShortWord(string &text){
    string s(100, 'k');
    string l = "";
    string buf;
    for(int i = 0; i < text.size(); i++){
        if (isalpha(text[i])){
            buf += text[i];
        }
        else{
            if(buf.size() > 0){
                if (buf.size() < s.size())
                    s = buf;
                if (buf.size() > l.size())
                    l = buf;
                
                buf = ""; 
            }           
        }

    }
    return make_pair(s, l);


}

int main(){
    string text = "The sun was setting behind the mountains, painting the sky with shades of orange and pink";
    pair<string, string> words = findLongShortWord(text);
    cout << words.first << " " << words.second << endl;

}