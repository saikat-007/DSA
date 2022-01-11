​The key here is tree traversal and generating the numbers as we go from the root towards the leaves.
Using shift operators, we can always keep the current sum value, sum in base 10 and as soon as we reach any leaf, we add this current value to the running answer.


sum = (sum << 1) | root->val;


sum << 1 means we're shifting the bits of sum to the left by 1 place, which is equivalent to multiplying sum by 2 (in base 10). Bitwise OR is used to set a particular bit. Let's take an example!


Suppose, the root-to-leaf path is 1->0->1.
Then, at the root, initially cur_val is 0. We multiply it by 2 and perform bitwise OR with 1 which makes sum 1.
Next, sum is 1. We multiply it by 2 and perform bitwise OR with 0 which makes sum 2.
Last, at the leaf, sum is 2. We multiply it by 2 and perform bitwise OR with 1 which makes sum 5.
101 (base 2) is 5 (base 10).
