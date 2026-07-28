也就是说，Hash Table 的 key 十分灵活。其实把 index 当作 key 也完全没问题。如果暂时不考虑效率，我可以使用 HashTableGet 找到对应的 value。

但是，我这个 function 的目的是寻找“第二个数字”，也就是判断这个数字是否存在于 integer array 中。假设我以 index 为 key、array 中的数字为 value，那么选定第一个数字并确定需要寻找的第二个数字后，我仍然需要先找出哪个 index 对应这个数字。

即使我不用 array，而是不断使用 HashTableGet，逐个 index 获取 value 并进行比较，本质上仍然是在逐个检查所有 index，因此总体时间复杂度还是 O(n)。这样使用 Hash Table 并没有提升查找效率，也就失去了使用它的意义。

如果我把 integer array 中的数字作为 key，那么我就可以直接使用 HashTableContains 检查需要的数字是否存在。这个操作在 best case 和 average case 下是 O(1)，在 worst case 下是 O(n)。相比在 integer array 中逐个搜索数字，average-case efficiency 得到了提升。这才是这里使用 Hash Table 的原因。
