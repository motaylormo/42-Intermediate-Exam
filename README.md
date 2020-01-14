# 42-Intermediate-Exam
Moulinette-passing versions of Intermediate Exam questions.

# Questions
<details><summary><b>Table conventions</b></summary>

Trace test accessibility refers to, "When I look at the trace for this question, can I tell what the tests are?"
* :open_file_folder: Yes, the tests are accessible.
* :lock: No, the tests are locked away in files. It might look something like:
```
= Test 1 ===================================================
$> ./3sdnrgu2oip0738azjrotz8n test_correct_a_00.txt test_correct_b_00.txt
$> diff -U 3 user_output_test1 test1.output | cat -e
```
* :crystal_ball: The trace show _something_, but not enough to recreate the test ourselves. This is particularly common among questions that take structs as input.
</details>

level | question | program/<br>function  | trace | test<br>main |
----: | -------- | :-------------------: | :---: | :----------: |
0 | [`count_of_2`](./level0/count_of_2)            |:gear: |:open_file_folder:|:white_check_mark:|
0 | [`equation`](./level0/equation)                |:gear: |:open_file_folder:|:white_check_mark:|
0 | [`find_pivot`](./level0/find_pivot)            |:gear: |:lock:            |:white_check_mark:|
0 | [`is_anagram`](./level0/is_anagram)            |:gear: |:lock:            |:white_check_mark:|
0 | [`print_doublon`](./level0/print_doublon)      |:gear: |:lock:            |:white_check_mark:|
1 | [`count_alpha`](./level1/count_alpha)          |:pager:|:open_file_folder:|:clipboard:       |
1 | [`flood_fill`](./level1/flood_fill)            |:gear: |:lock:            |:white_check_mark:|
1 | [`height_tree`](./level1/height_tree)          |:gear: |:crystal_ball:    |:no_entry_sign:   |
1 | [`queue`](./level1/queue)                      |:gear: |:crystal_ball:    |:no_entry_sign:   |
1 | [`stack`](./level1/stack)                      |:gear: |:crystal_ball:    |:no_entry_sign:   |
2 | [`is_looping`](./level2/is_looping)            |:gear: |:crystal_ball:    |:white_check_mark:|
2 | [`longest_sequence`](./level2/longest_sequence)|:gear: |:crystal_ball:    |:white_check_mark:|
2 | [`ord_alphlong`](./level2/ord_alphlong)        |:pager:|:open_file_folder:|:clipboard:       |
2 | [`reverse_tree`](./level2/reverse_tree)        |:gear: |:crystal_ball:    |:white_check_mark:|
2 | [`str_maxlenoc`](./level2/str_maxlenoc)        |:pager:|:open_file_folder:|:clipboard:       |
3 | [`can_split`](./level3/can_split)              |:gear: |:crystal_ball:    |:white_check_mark:|
3 | [`convert_bst`](./level3/convert_bst)          |:gear: |:crystal_ball:    |:no_entry_sign:   |
3 | [`gold_gain`](./level3/gold_gain)              |:gear: |:lock:            |:white_check_mark:|
3 | [`perimeter`](./level3/perimeter)              |:gear: |:crystal_ball:    |:white_check_mark:|
3 | [`width_tree`](./level3/width_tree)            |:gear: |:crystal_ball:    |:white_check_mark:|
4 | [`clone_list`](./level4/clone_list)            |:gear: |:crystal_ball:    |:no_entry_sign:   |
4 | [`intersection`](./level4/intersection)        |:gear: |:crystal_ball:    |:no_entry_sign:   |
4 | [`longest_subarray`](./level4/longest_subarray)|:gear: |:open_file_folder:|:white_check_mark:|
4 | [`range_comb`](./level4/range_comb)            |:gear: |:open_file_folder:|:white_check_mark:|
4 | [`volume_histogram`](./level4/volume_histogram)|:gear: |:open_file_folder:|:white_check_mark:|
5 | [`count_island`](./level5/count_island)        |:pager:|:lock:            |:clipboard:       |
5 | [`g_diam`](./level5/g_diam)                    |:pager:|:open_file_folder:|:clipboard:       |
5 | [`infin_add`](./level5/infin_add)              |:pager:|:open_file_folder:|:clipboard:       |
5 | [`infin_mult`](./level5/infin_mult)            |:pager:|:open_file_folder:|:clipboard:       |

***
# Concepts:

### hash table
* is_anagram
* count_alpha

### implementing data structure
* queue
* stack

## linked lists
* is_looping
* convert_bst (doubly-linked list)
* clone_list (tetinically doubly-linked list, but really singly-linked list plus weird other)
* intersection

## trees

### N-ary tree
* height_tree

### binary tree
* longest_sequence
* reverse_tree
* can_split
* perimeter
* width_tree

### binary search tree (BST)
* convert_bst
