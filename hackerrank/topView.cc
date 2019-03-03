//Printing the top view of the tree when the root of the tree is passed as a function the function below

if (root == NULL)
        return;
 
    unordered_map<int, int> m;
    queue<pair<Node*, int>> q;
 
    // push node and horizontal distance to queue
    q.push(make_pair(root, 0));
    
    while (!q.empty())
    {
        pair<Node*, int> p = q.front();
        Node *n = p.first;
        int val = p.second;
        q.pop();
         
        // if horizontal value is not in the hashmap 
        // that means it is the first value with that
        // horizontal distance so print it and store 
        // this value in hashmap
        if (m.find(val)==m.end())
        {
            m[val] = n->data;
            printf("%d ", n->data);
        }
         
        if (n->left != NULL)
            q.push(make_pair(n->left, val-1));
         
        if (n->right != NULL)
            q.push(make_pair(n->right, val+1));
    }
