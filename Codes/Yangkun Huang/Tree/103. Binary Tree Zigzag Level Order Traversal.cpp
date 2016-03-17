vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
vector<vector<int> > result;
queue<TreeNode*> current, next;
bool left_to_right = true;
if(root == nullptr) {
return result;
} else {
current.push(root);
}
while (!current.empty()) {
vector<int> level; // elments in one level
while (!current.empty()) {
TreeNode* node = current.front();
current.pop();
level.push_back(node->val);
if (node->left != nullptr) next.push(node->left);
if (node->right != nullptr) next.push(node->right);
}
if (!left_to_right) reverse(level.begin(), level.end());
result.push_back(level);
left_to_right = !left_to_right;
swap(next, current);
}
return result;
}