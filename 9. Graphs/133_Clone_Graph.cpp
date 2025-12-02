class Solution {
public:
    Node* helper(Node* node, unordered_map<Node*, Node*>& mp){
        Node* newNode = new Node(node->val);
        mp[node]=newNode;
        for(auto neighbor: node->neighbors){
            if(mp.find(neighbor) == mp.end()){
                (newNode->neighbors).push_back(helper(neighbor,mp));
            }
            else{
                (newNode->neighbors).push_back(mp[neighbor]);
            }
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> mp;
        return helper(node, mp);
    }
};

