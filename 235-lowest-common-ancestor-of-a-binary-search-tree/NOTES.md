We can solve this problem using BST properties. We can recursively traverse the BST from root. The main idea of the solution is, while traversing from top to bottom, the first node n we encounter with value between n1 and n2.

If both p and q are smaller than data at current node, call the function recursively for finding LCA in the left subtree.
If both p and q are greater than data at current node, call the function recursively for finding LCA in the right subtree.
Otherwise, current node is LCA (assuming that both n1 and n2 are present in BST)
