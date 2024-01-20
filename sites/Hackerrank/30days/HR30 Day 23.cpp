#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }
           return root;
           }
        }

	void levelOrder(Node * root){
      //Write your code here



      queue<Node *> q;

        if (root != NULL) {
            q.push(root); int c = 0;

            while (not q.empty()){
                if (c > 0) cout << ' '; c++;

                Node *t = q.front();

                cout << t->data; q.pop();

                if (t->left  != NULL) q.push(t->left );
                if (t->right != NULL) q.push(t->right);
            }   cout << endl;
        }

	}

};//End of Solution
int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}
