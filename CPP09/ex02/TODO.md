TODO

- [x] Find why I can't use certain containers
	- Can only use containers with Compare as a template parameter for the merge insert sort
	- Containers available : set, map, multiset, multimap, priority_queue
	- [x] set: can't have duplicates in it
	- [x] map: already used
	- [x] multiset: can be used
	- [x] multimap: too much knowing i only need the key, but can be used
	- [x] priority_queue: can be used

- [x] Implement merge-sort algorithm
	- [x] Push input in vector
	- [x] Group elements by pairs, last one is left alone if amount of numbers is odd
	- [x] Determine larger value in each pair 
	- [x] Insert in mset/pqueue, larger element from each vector pair
	- [x] Insert at the start of mset/pqueue, the element paired with the smallest of the sorted sequence
	- [x] Insert the rest

- [ ] Write merge-sort function for each container
- [ ] Get time for completion of sorting the vector
- [ ] And for fuck's sake, clean your code