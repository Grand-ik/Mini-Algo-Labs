#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


char is_mini_symbol(char elem) {
    if (96 < elem) { return 0; }
    else { return 1; }
}


string ClearWord(string word) {
    char b, e;
    b = is_mini_symbol(word[0]);
    e = is_mini_symbol(word[word.size() - 1]);
    if (!(b + e)) { return word; }
    string new_word;
    if (b) { new_word += char(word[0] + 32); }
    for (b; b < word.size() - e; ++b) {
        new_word += word[b];
    }
    return new_word;
}


int MaxMin(vector<string> V, string e) {
    int l, m, r;
    l = 0;
    r = V.size() - 2;
    while (l < r) {
        m = (l + r) / 2 + 1;
        if (V[m] < e) { l = m; }
        else { r = m - 1; }
    }

    return l;
}


int MinMax(vector<string> V, string e) {
    int l, m, r;
    l = 1;
    r = V.size() - 1;
    while (l < r) {
        m = (l + r) / 2;
        if (V[m] > e) { r = m; }
        else { l = m + 1; }
    }
    return l;
}


string OneSymbol(string word) {
    char alf_word[26];
    for (int i = 0; i < 26; ++i) { alf_word[i] = 0; }
    string new_word;
    for (char symbol : word) {
        if (!alf_word[symbol % 26]) {
            ++alf_word[symbol % 26];
            new_word += symbol;
        }
    }
    return new_word;
}


int main() {
    ifstream data_in("input.txt");
    if (!data_in.is_open()) { return 0; }
    vector<string> Words;
    Words.push_back("0");
    for (string word; data_in >> word; ) {
        if (word != "-") {
            Words.push_back(ClearWord(word));
        }
    }
    string last_word = *(Words.end() - 1);
    sort(Words.begin(), Words.end());
    Words.push_back("~");
    data_in.close();

    ofstream data_out("output.txt");
    if (!data_out.is_open()) { return 0; }
    // До последовательности
    for (int i = 1; i <= MaxMin(Words, last_word); ++i) {
        data_out << OneSymbol(Words[i]) << '\n';
    }
    // После последовательности
    for (int i = MinMax(Words, last_word); i < Words.size() - 1; ++i) {
        data_out << OneSymbol(Words[i]) << '\n';
    }
    data_out.close(); 
}