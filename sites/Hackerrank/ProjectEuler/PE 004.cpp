
#include <iostream>
#include <string>
#include <set>

using namespace std;

bool isPalindrome(int n){
    string num = to_string(n);

    for (int i = 0; i < num.size()/2; i++)
        if (num[i] != num[num.size()-i-1]) return false;

    return true;
}

void genPalindromes(set<int> &s){
    for (int i = 100; i < 1000; i++)
        for (int j = 100; j < 1000; j++) if (isPalindrome(i*j)) s.insert(i*j);
}

int main(){
    set<int> s; genPalindromes(s);
    int T; cin >> T;

    while(T-- > 0){
        int N; cin >> N;
        cout << *(--s.lower_bound(N)) << endl;
    }

    return 0;
}
