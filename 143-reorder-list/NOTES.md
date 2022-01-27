​There are three concept used in this question:

a -> Reversing a linked list , 
b -> finding middle point of a LL (Using slow pointer - fast pointer concept) , 
c -> merging two lists


Two pointer Approach [Tortoise and Hare method]:-
This approach is much faster and efficient in terms of Time and Space Complexity the only drawback is that it looks a little bit lengthy but trust me it's easy to understand.

Two pointer Approach Algorithm:

First let's take two pointers name it as half and temp . temp is faster than half by 1.
When temp reaches the end of linkedlsit half reaches the middle element .So this is how the linkedlist will get divided in two halfes as the center will become a dividing node .
Now reverse the second half .
After reversing the second half, merge the first half and second half
Let's have a dy run before starting the code:-
Let's take the same example as above:

Linked list:[1,2,3,4,5]
* search for the central element, which will be three in our case
* split the list in two halfes that will be [1,2,3] and [4,5]
* Now reverse the second half that will be [5,4]
* Now merge both the halfes 
[1,2,3]
	[5,4]
=>[1,5,2,4,3]
