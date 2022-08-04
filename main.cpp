#include<iostream>
#include<string>
#include <stack>
#include<queue>
#include<vector>
using namespace std;
namespace xiao{
    int X;
    class TT;
}
template<typename T>
struct Tnode{
    T value;
    Tnode* left,*right;
    Tnode():left(nullptr),right(nullptr){ }
    Tnode(T x):value(x),left(nullptr),right(nullptr){}
};

template<typename T>
Tnode<T>* buildTree(vector<T> prestr,int& cur,vector<T> inorderstr,int b,int e){
    Tnode<T>* tree = nullptr;
    if(b>=e) return tree;
    if(cur<prestr.size()){
        tree = new Tnode<int>;
        tree->value = prestr[cur];
        int lb = b,le,rb,re = e;
        for(int i=b;i<e;i++){
            if(inorderstr[i]==prestr[cur]){
                le = i;
                rb = i+1;
            }
        }
        cur++;
        tree->left = buildTree(prestr,cur,inorderstr,lb,le);
        tree->right = buildTree(prestr,cur,inorderstr,rb,re);
    }
    return tree;
}

//����ƽ�������     ���ڸ��ӣ���δʵ��
template<typename T>
Tnode<T>* BalancedTree(){
    return nullptr;
}

Tnode<char>* buildTree(string prestr,int& cur,string inorderstr,int b,int e){
    Tnode<char>* tree = nullptr;
    if(b>=e) return tree;
    if(cur<prestr.size()){
        tree = new Tnode<char>;
        tree->value = prestr[cur];
        int lb = b,le,rb,re = e;
        for(int i=b;i<e;i++){
            if(inorderstr[i]==prestr[cur]){
                le = i;
                rb = i+1;
            }
        }
        cur++;
        tree->left = buildTree(prestr,cur,inorderstr,lb,le);
        tree->right = buildTree(prestr,cur,inorderstr,rb,re);
    }
    return tree;
}

//�������������
void buildBST(Tnode<int>* &tree,int x){
    if(tree== nullptr){
        Tnode<int>* p = new Tnode<int>(x);
        tree = p;
    }else{
        if(x>tree->value){
            buildBST(tree->right,x);
        }else{
            buildBST(tree->left,x);
        }
    }
}

void BST(Tnode<int>* &tree){
    cout<<"��������������������У�����-1��ʾ��������"<<endl;
    int x=-1;
    while(cin>>x){
        if(x!=-1){
            buildBST(tree,x);
        }else break;
    }
}

//�ݹ�ǰ�����
template<typename T>
void pretravel(Tnode<T>* tree){
    if(tree){
        cout<<tree->value<<" ";
        pretravel(tree->left);
        pretravel(tree->right);
    }
}

//�ݹ��������
template<typename T>
void inordertravel(Tnode<T>* tree){
    if(tree){
        inordertravel(tree->left);
        cout<<tree->value<<" ";
        inordertravel(tree->right);
    }
}

//�ݹ�������
template<typename T>
void posttravel(Tnode<T>* tree){
    if(tree){
        posttravel(tree->left);
        posttravel(tree->right);
        cout<<tree->value<<" ";
    }
}

//�ǵݹ�ǰ�����
template<typename T>
void previsit(Tnode<T>* tree){
    stack<Tnode<T>*> stk;
    Tnode<T>* p = tree;
    while(p||!stk.empty()){
        if(p){
            cout<<p->value<<" ";
            if(p->right) stk.push(p->right);
            p = p->left;
        }else{
            p = stk.top();
            stk.pop();
        }
    }
}

//�ǵݹ��������
template<typename T>
void inordervisit(Tnode<T>* tree){
    stack<Tnode<T>*> stk;
    Tnode<T> *p = tree;
    while(p||!stk.empty()){
        while(p){
            stk.push(p);
            p=p->left;
        }
        p = stk.top();
        stk.pop();
        cout<<p->value<<" ";
        p = p->right;
    }
}

//�ǵݹ�������
template<typename T>
void postvisit(Tnode<T>* tree){
    stack<Tnode<T>*> stk;
    Tnode<T>* p = tree;
    Tnode<T>* rchild = nullptr;
    while(p||!stk.empty()){
        while(p){
            stk.push(p);
            p = p->left;
        }
        p = stk.top();
        if(!p->right||rchild==p->right){
            stk.pop();
            cout<<p->value<<" ";
            rchild = p;
            p = nullptr;
        }else p = p->right;
    }
}

//�������Ĳ������
template<typename T>
void levelorder(Tnode<T>* tree){
    queue<Tnode<T>*> que;
    Tnode<T>* p = tree;
    que.push(p);
    int size = 0;
    while(!que.empty()){
        size = que.size();
        for(int i = 0;i<size;i++){
            p = que.front();
            cout<<p->value<<" ";
            que.pop();
            if(p->left) que.push(p->left);
            if(p->right) que.push(p->right);
        }
    }

}

//���¶��ϡ������Ҳ�α���
template<typename T>
void DowntoTop(Tnode<T>* root){
    queue<Tnode<T>*> que;
    stack<Tnode<T>*> stk;
    Tnode<T>* p = root;
    que.push(p);
    int size = 0;
    while(!que.empty()){
        size = que.size();
        for(int i = 0;i<size;i++){
            p = que.front();
            que.pop();
            stk.push(p);
            if(p->left) que.push(p->left);
            if(p->right) que.push(p->right);
        }
    }
    Tnode<T>* q = nullptr;
    while(!stk.empty()){
        q = stk.top();
        cout<<q->value<<" ";
        stk.pop();
    }
}

//���ĸ߶�
template<typename T>
int Height(Tnode<T>* tree){
    if(!tree) return 0;
    return 1+ max(Height(tree->left),Height(tree->right));
}

//�ǵݹ����ĸ߶�
template<typename T>
int Height_(Tnode<T>* tree){
    int height = 0;
    if(!tree) return height;
    Tnode<T>* p = tree;
    queue<Tnode<T>*> que;
    que.push(p);
    int size = 0;
    while(!que.empty()){
        size = que.size();
        height++;
        for(int i = 0;i<size;i++){
            p = que.front();
            que.pop();
            if(p->left) que.push(p->left);
            if(p->right) que.push(p->right);
        }
    }
    return height;
}

//��Ҷ�ڵ��Ȩ·����

int WPL(Tnode<int>* root){
    int ans = 0;
    if(root){
        ans += WPL(root->left);
        ans += WPL(root->right);
        if(!root->left&&!root->right){
            return ans+root->value;
        }else return ans;
    }
    return ans;
}

template<typename T>
void WPL(Tnode<T>* root,T &sumofwpl){
    if(root){
        WPL(root->left,sumofwpl);
        WPL(root->right,sumofwpl);
        if(!root->left&&root->right) sumofwpl+=root->value;
    }
}

void test1(){
    string prestr="",inorderstr="";
    cout<<"����ǰ�����У�"<<endl;
    cin>>prestr;
    cout<<"�����������У�"<<endl;
    cin>>inorderstr;
    int cur = 0;
    Tnode<char>* tree = buildTree(prestr,cur,inorderstr,0,inorderstr.size());
    cout<<"ǰ�����"<<endl;
    pretravel(tree);
    cout<<endl<<"�ǵݹ�ǰ�����"<<endl;
    previsit(tree);
    cout<<endl<<"�������"<<endl;
    inordertravel(tree);
    cout<<endl<<"�ǵݹ��������"<<endl;
    inordervisit(tree);
    cout<<endl<<"�������"<<endl;
    posttravel(tree);
    cout<<endl<<"�ǵݹ�������"<<endl;
    postvisit(tree);
}

void test2(){
    vector<int> pre,inorder;
    cout<<"����ǰ�����У�"<<endl;
    int x = 0;
    while(cin>>x){
        if(x!=-1)
            pre.push_back(x);
        else break;
    }
    cout<<"�����������У�"<<endl;
    while(cin>>x){
        if(x!=-1)
            inorder.push_back(x);
        else break;
    }
    int cur = 0;
    Tnode<int>* tree = buildTree(pre,cur,inorder,0,inorder.size());
    cout<<"ǰ�����"<<endl;
    pretravel(tree);
    cout<<endl<<"�ǵݹ�ǰ�����"<<endl;
    previsit(tree);
    cout<<endl<<"�������"<<endl;
    inordertravel(tree);
    cout<<endl<<"�ǵݹ��������"<<endl;
    inordervisit(tree);
    cout<<endl<<"�������"<<endl;
    posttravel(tree);
    cout<<endl<<"�ǵݹ�������"<<endl;
    postvisit(tree);
    cout<<endl<<"�������"<<endl;
    levelorder(tree);
}

void test3(){
    Tnode<int>* tree = nullptr;
    BST(tree);
    cout<<"ǰ�����"<<endl;
    pretravel(tree);
    cout<<endl<<"�ǵݹ�ǰ�����"<<endl;
    previsit(tree);
    cout<<endl<<"�������"<<endl;
    inordertravel(tree);
    cout<<endl<<"�ǵݹ��������"<<endl;
    inordervisit(tree);
    cout<<endl<<"�������"<<endl;
    posttravel(tree);
    cout<<endl<<"�ǵݹ�������"<<endl;
    postvisit(tree);
    cout<<endl<<"�������"<<endl;
    levelorder(tree);
    cout<<endl<<"���¶��ϡ������Ҳ�α���"<<endl;
    DowntoTop(tree);
}

void test4(){
    Tnode<int>* tree = nullptr;
    BST(tree);
    cout<<"���ĸ߶ȣ�"<<Height(tree)<<endl<<Height_(tree)<<endl;
    cout<<"��Ȩ·���ͣ�"<<WPL(tree)<<"    ";
    int sum = 0;
    WPL(tree,sum);
    cout<<sum<<endl;
}

int main(){
    //test3();
    test4();
    return 0;
}