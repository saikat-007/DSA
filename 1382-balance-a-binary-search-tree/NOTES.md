​Example:  [1,null,2,null,3,null,4,null,null]
	
	1. 	Create a vector Inorder to store the nodes. 
	
	2. 	Traverse the tree in such a way that the nodes stored in the vector are in ascending order i.e. Inorder Traversal. 
								Inorder: [ 1, 2, 3, 4 ]
								
	3. 	Then use this vector of nodes to find the root node of the balanced BST.
	
	4. 	The newRoot node will be mid element of the array;
								newRoot= Inorder[mid]=2
								
	5. Then recursively add the mid of first half to the left of the tree.
								newRoot->left=1
								
	6. And the mid of second half to the right of the tree.
								newRoot->right=3
