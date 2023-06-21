#include<iostream>
#include<stack>
using namespace std;

int main(){
    int q; cin >> q; //queue<int> Q;
    stack<int> F, R;

    while (q--){
        int type; cin >> type; //Q.clear();
        //F.clear(), R.clear();

        if (type == 1){
            int x; cin >> x; F.push(x); R.push(x);
            //
        }

        else if (type == 2) R.pop();
        else if (type == 3) cout << R.top() << endl;
    }

    return 0;
}
