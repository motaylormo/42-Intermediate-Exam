`perimeter` is actually pretty simple, though the subject desribes it very poorly. It wants, in this order:
1. The root node
2. The nodes in an unbroken chain of node->left, decending from the root
3. Any leaf nodes (ones where both left and right child nodes are NULL), ordered left-to-right
4. The nodes in an unbroken chain of node->right, coming up the right side to the root

The only "trick" to `perimeter` is avoiding double inclusion. For example, a node at the end of the chain of node->left which is also a leaf node. Or a root node which is also a leaf node.

Here is the tree from the subject, for whom the output is: ```92 85 79 96 58 58 41 22 35 31 55 99 51 85 78 64 26```

I've marked it up:
* Root node is in `<>`
* Leftmost nodes are in `()`
* Leaf nodes are in `[]`
* Rightmost nodes are in `{}`

```
	                 <92>
	                  / \
	                 /   \
	               (85)  {26}
	               /       \
	             (79)     {64}
	               \       / \
	               10     /   \
	              /     /     \
	              39    /       \
	             /     /         \
	            35    /           \
	           /     /             \
	         [96]   /               \
	               /                 \
	              40                {78}
	             / \                 / \
	            /   \               /   \
	           /     \             2    {85}
	          /       \           / \     \
	         /         \         /   \   {[51]}
	        /           \       /     \
	       /             \     33     11
	      88             10     \     /
	     / \             / \   [55] [99]
	    /   \           /   \
	   12   55         52   87
	  /     / \       / \     \
	[58]   /   \     /   \    [31]
	     [58] [41] [22]  [35]
```
