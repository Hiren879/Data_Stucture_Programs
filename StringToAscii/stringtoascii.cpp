#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
    fstream fin("names");
    vector <string> name;
    vector <string>::size_type siz;
    string temp;
    while(fin>>temp){
        name.push_back(temp);
    }
    fin.close();

    siz = name.size();
    string a[siz];
    for(int i=0;i<siz;i++){
        a[i] = name.at(i);
        cout<<a[i]<<"-->";
        string s = a[i];
        char aa[50];
        int sum = 0;
        int len = s.length();
        for(int j=0;j<len;j++){
            aa[j] = s[j];
            sum = sum + (int)aa[j];
        }
        cout<<sum<<endl;
    }

return 0;
}
