/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node* >  qe;
        // if(root==NUUL)  return root;
        Node* ptr = root;

        if(ptr!=NULL)   qe.push(ptr);

        while(!qe.empty())
        {
            int si = qe.size();
            Node* prev = NULL;

            for(int i=0;i<si;i++)
            {
                auto node = qe.front();
                qe.pop();

                node->next = prev;

                if(node->right) qe.push(node->right);
                if(node->left)  qe.push(node->left);

                prev = node;
            }
        }

        return root;
    }
};
