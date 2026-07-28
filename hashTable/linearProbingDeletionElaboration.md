这是在讲 **open addressing + linear probing（线性探测）** 的删除问题。

哈希函数是：

`h(k) = k % 10`

也就是说，一个 key 最开始应该去的位置，是它除以 10 的余数。

先看这些数字原本应该去哪：

`24 % 10 = 4`

所以 24 放在 index 4。

`14 % 10 = 4`

14 也应该放在 index 4，但 index 4 已经被 24 占了，所以它继续往后找：

- index 5 被 5 占了
- index 6 是空的

于是 14 放在 index 6。

再看 4：

`4 % 10 = 4`

4 也从 index 4 开始找：

- index 4：24
- index 5：5
- index 6：14
- index 7：空

所以 4 最后放在 index 7。

因此 14 和 4 的 probe path 都要经过 index 4：

```text
查找 14：
4 → 5 → 6

查找 4：
4 → 5 → 6 → 7
```

现在假设我们直接把 24 删除，把 index 4 改成普通的 `No Item`：

```text
index 4: empty
index 5: 5
index 6: 14
index 7: 4
```

接下来查找 14：

1. 计算：

   `14 % 10 = 4`

2. 从 index 4 开始查找。

3. 发现 index 4 是空的。

查找算法会认为：

> 既然这里是空的，那么 14 当初不可能跨过这个空位放到后面，所以 14 不在 table 中。

于是搜索直接停止，错误地返回“找不到 14”。

但实际上 14 在 index 6。

这就是图片说的：

> Probe path for 14 and 4 is broken.

也就是删除 24 后，原本连续的查找路径被切断了。
