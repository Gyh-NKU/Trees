#include<bits/stdc++.h>

using namespace std;

// An AVL tree node
class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int key) {
        this->key = key;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int getHeight(Node *root) {
    if (root)
        return root->height;
    return 0;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left),
                    getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left),
                    getHeight(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left),
                    getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left),
                    getHeight(y->right)) + 1;

    return y;
}

int getBalance(Node *N) {
    if (N == nullptr)
        return 0;
    return getHeight(N->left) -
           getHeight(N->right);
}

class Tree {
public:
    Node *root = nullptr;
    Node *deleteNode(Node *&node, int key) {
//        cout<<node->key<<' ';
        if (node == nullptr)
            return node;

        if (key < node->key)
            node->left = deleteNode(node->left, key);

        else if (key > node->key)
            node->right = deleteNode(node->right, key);

        else {
            if ((node->left == nullptr) ||
                (node->right == nullptr)) {
                Node *temp = node->left ?
                             node->left :
                             node->right;
//                cout<<node->key;
                if (temp == nullptr) {
//                    cout<<"AAA";
                    delete node;
                    node = nullptr;
                    return node;
                } else{
//                    cout<<"BBB";
                    *node = *temp;
                    delete temp;
                    return node;
                }


            } else {
//                cout<<999;
                Node *cur = node->right;

                while (cur->left != nullptr)
                    cur = cur->left;

//                cout<<cur->key;
                node->key = cur->key;

                node->right = deleteNode(node->right,
                                         cur->key);
            }
        }


        if (node == nullptr)
            return node;

        node->height = 1 + max(getHeight(node->left),
                               getHeight(node->right));


        int balance = getBalance(node);
//        cout<<"KKK"<<node->key<<" "<<balance<<" "<<getBalance(node->left);
        // Left Left
        if (balance > 1 &&
            getBalance(node->left) >= 0)
            return rightRotate(node);

        // Left Right
        if (balance > 1 &&
            getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Right
        if (balance < -1 &&
            getBalance(node->right) <= 0)
            return leftRotate(node);

        // Right Left
        if (balance < -1 &&
            getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }



    Node *insert(Node *&node, int key) {

        if (node == nullptr) {
            node = new Node(key);
            return node;
        }


        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(getHeight(node->left),
                               getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    void preOrder(Node *node)
    {
        if(node != nullptr)
        {
            cout << node->key << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    Node *ins(int key){
        insert(root, key);
    }
    Node *del(int key){
        root = deleteNode(root, key);
    }
    void pre(){
        preOrder(root);
    }
    bool find(int n) const{
        Node *pos = root;
        while (pos){
            if(pos->key == n){
                return true;
            } else if(n>pos->key){
                pos = pos->right;
            } else{
                pos = pos->left;
            }
        }
        return false;

    }

};
int data[500010];
int main()
{
    Tree tree;
    srand((unsigned) time(nullptr));
    freopen("./Randomdata.txt", "r", stdin);
    freopen("./ResultOfAVLChart(Random).txt", "w", stdout);
//    printf("Test For Random Data:\n\n");
    for (int i = 1; i <= 500000; i++) {
        scanf("%d", &data[i]);
    }
    int cnt = 10000;
    for (int i = 1; i <= 50; i++) {
//        printf("Test %d\n", i);
//        printf("nums of data: %d\n", i * cnt);
        clock_t start = clock();
        for (int j = 1; j <= i * cnt; j++) {
            tree.ins(data[j]);
        }
        clock_t end = clock();
//        printf("inserting costs: %.3lfs\n", (double) (end - start) / CLOCKS_PER_SEC);
        printf("%.3lf ", (double) (end - start) / CLOCKS_PER_SEC);


        start = clock();
        for (int j = 1; j <= 100000; j++) {
            tree.find(data[rand()]);
        }
        end = clock();
//        printf("finding costs: %.3lfs\n", (double) (end - start) / CLOCKS_PER_SEC);
        printf("%.3lf ", (double) (end - start) / CLOCKS_PER_SEC);


        start = clock();
        for (int j = 1; j <= i * cnt; j++) {
            tree.del(data[j]);
        }
        end = clock();
//        printf("removing costs: %.3lfs\n", (double) (end - start) / CLOCKS_PER_SEC);
        printf("%.3lf ", (double) (end - start) / CLOCKS_PER_SEC);

    }
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    freopen("./MonotonicallyData.txt", "r", stdin);
    freopen("./ResultOfAVLChart(Monotonically).txt", "w", stdout);
//    printf("Test For Monotonically Data:\n\n");
    for (int i = 1; i <= 500000; i++) {
        scanf("%d", &data[i]);
    }
    cnt = 10000;
    for (int i = 1; i <= 50; i++) {
//        printf("Test %d\n", i);
//        printf("nums of data: %d\n", i * cnt);
        clock_t start = clock();
        for (int j = 1; j <= i * cnt; j++) {
            tree.ins(data[j]);
        }
        clock_t end = clock();
//        printf("inserting costs: %.3lfs\n", (double) (end - start) / CLOCKS_PER_SEC);
        printf("%.3lf ", (double) (end - start) / CLOCKS_PER_SEC);


        start = clock();
        for (int j = 1; j <= 100000; j++) {
            tree.find(data[rand()]);
        }
        end = clock();
//        printf("finding costs: %.3lfs\n", (double) (end - start) / CLOCKS_PER_SEC);
        printf("%.3lf ", (double) (end - start) / CLOCKS_PER_SEC);


        start = clock();
        for (int j = 1; j <= i * cnt; j++) {
            tree.del(data[j]);
        }
        end = clock();
//        printf("removing costs: %.3lfs\n", (double) (end - start) / CLOCKS_PER_SEC);
        printf("%.3lf ", (double) (end - start) / CLOCKS_PER_SEC);

    }
    return 0;

}