Traverse LL1 and LL2 and find the length of both the LLs.
find the diffrence b/w their lengths and then move the longer LL by that difference.
This will make them both to cover the extra distance between them.
Now move both pointers together(at the start of LL1 & one at x distance from start of LL2)
Keep checking if they meet at any point.
Even if they wont intersect, their value will become same when they reach null.
So, if they're not intersecting, null will be returned.

Time Complexity : O(n)
Space Complexity : O(1)
