#include <iostream>
#include<string>

using namespace std;
string replacePascalCase(string line, string word);
int main()
{
    string line;
    cout << "insert a phare to capitalized type like Pascal case " << endl;
    cin >> line;
    line = replacePascalCase(line,"-");
    line = replacePascalCase(line,"_");
    cout << line << endl;
}

string replacePascalCase(string line, string word) {
    int index = line.find(word);
    while(index > 0){
      line.erase(index,1);
      line[index] = toupper(line[index]);
      index = line.find(word);
    }
    return line;
}

string toCamelCase(string text){
for(int i = 0; i < text.length(); i++){
    if(text[i] == '-' || text[i] == '_'){
      text.erase(i,1);
      text[i]= toupper(text[i]);
    }
  }
    return text;
}
