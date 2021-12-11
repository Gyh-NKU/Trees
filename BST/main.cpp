#include<iostream>
#include <cstdio>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node {

    int data;
    Node *left;
    Node *right;

    Node(int x) : left(nullptr), right(nullptr), data(x) {}
};

class BST {
    Node *root;

    void iinsert(int x, Node *&pos) {
        if (pos == nullptr) {
            Node *tem = new Node(x);
            pos = tem;
        } else if (pos->data == x) {
            return;
        } else if (x > pos->data) {
            iinsert(x, pos->right);
        } else if (x < pos->data) {
            iinsert(x, pos->left);
        }
    }

public:
    void insert(int x) {
        iinsert(x, root);
    }

    bool find(int x) {
        Node *pos = root;
        while (pos) {
            if (pos->data == x) {
                return 1;
            } else if (pos->data > x) {
                pos = pos->left;
            } else if (pos->data < x) {
                pos = pos->right;
            }
        }
        return 0;
    }

    Node *Del(Node *node, int x) {
        if (node == nullptr) {
            return nullptr;
        }
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
            } else {
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
            node->data = cur->data;

            node->right = Del(node->right,
                              cur->data);
        }
        return node;
    }

    void del(int x) {
        root = Del(root, x);
    }

    void print() {
        queue<Node *> q;
        if (root == nullptr)return;
        q.push(root);
        while (!q.empty()) {
            Node *a = q.front();
            cout << a->data << ' ';
            if (a->left)q.push(a->left);
            if (a->right)q.push(a->right);
            q.pop();
        }
        cout << endl;
    }

    BST() : root(nullptr) {}
};

int data[500010];

int main() {
    BST tree;
    srand((unsigned) time(nullptr));
    freopen("./Randomdata.txt", "r", stdin);
    freopen("./ResultOfBSTChart(Random).txt", "w", stdout);
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
            tree.insert(data[j]);
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
    freopen("./ResultOfBSTChart(Monotonically).txt", "w", stdout);
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
            tree.insert(data[j]);
        }
        clock_t end = clock();
        printf("%.3lf ", (double) (end - start) / CLOCKS_PER_SEC);
//        printf("inserting costs: %.3lfs\n", (double) (end - start) / CLOCKS_PER_SEC);


        start = clock();
        for (int j = 1; j <= 1000; j++) {
            tree.find(data[rand()]);
        }
        end = clock();
        printf("%.3lf ", (double) (end - start) / CLOCKS_PER_SEC);
//        printf("finding costs: %.3lfs\n", (double) (end - start) / CLOCKS_PER_SEC);


        start = clock();
        for (int j = 1; j <= i * cnt; j++) {
            tree.del(data[j]);
        }
        end = clock();
        printf("%.3lf ", (double) (end - start) / CLOCKS_PER_SEC);
//        printf("removing costs: %.3lfs\n", (double) (end - start) / CLOCKS_PER_SEC);

    }
    return 0;
}