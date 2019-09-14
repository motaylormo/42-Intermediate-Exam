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

level | question | trace | solution | test<br>main
----: | -------- | :---: | :------: | :----------:
0 | [`count_of_2`](./level0/count_of_2)            | :open_file_folder: | :white_check_mark: | :white_check_mark: |
0 | [`equation`](./level0/equation)                | :open_file_folder: | :white_check_mark: | :white_check_mark: |
0 | [`find_pivot`](./level0/find_pivot)            | :lock:             | :white_check_mark: | :white_check_mark: |
0 | [`is_anagram`](./level0/is_anagram)            | :lock:             | :white_check_mark: | :white_check_mark: |
0 | [`print_doublon`](./level0/print_doublon)      | :lock:             | :white_check_mark: | :white_check_mark: |
1 | [`count_alpha`](./level1/count_alpha)          | :open_file_folder: | :white_check_mark: | :clipboard:        |
1 | [`flood_fill`](./level1/flood_fill)            | :lock:             | :white_check_mark: | :white_check_mark: |
1 | [`height_tree`](./level1/height_tree)          | :crystal_ball:     | :white_check_mark: | :no_entry_sign:    |
1 | [`queue`](./level1/queue)                      | :crystal_ball:     | :white_check_mark: | :no_entry_sign:    |
1 | [`stack`](./level1/stack)                      | :crystal_ball:     | :white_check_mark: | :no_entry_sign:    |
2 | [`is_looping`](./level2/is_looping)            | :crystal_ball:     | :white_check_mark: | :white_check_mark: |
2 | [`longest_sequence`](./level2/longest_sequence)| :crystal_ball:     | :white_check_mark: | :white_check_mark: |
2 | [`ord_alphlong`](./level2/ord_alphlong)        | :open_file_folder: | :white_check_mark: | :clipboard:        |
2 | [`reverse_tree`](./level2/reverse_tree)        | :crystal_ball:     | :white_check_mark: | :white_check_mark: |
2 | [`str_maxlenoc`](./level2/str_maxlenoc)        | :open_file_folder: | :white_check_mark: | :clipboard:        |
3 | [`can_split`](./level3/can_split)              | :crystal_ball:     | :white_check_mark: | :white_check_mark: |
3 | [`convert_bst`](./level3/convert_bst)          | :crystal_ball:     | :white_check_mark: | :no_entry_sign:    |
3 | [`gold_gain`](./level3/gold_gain)              | :lock:             | :white_check_mark: | :white_check_mark: |
3 | [`perimeter`](./level3/perimeter)              | :crystal_ball:     | :white_check_mark: | :white_check_mark: |
3 | [`width_tree`](./level3/width_tree)            | :crystal_ball:     | :white_check_mark: | :white_check_mark: |
4 | [`clone_list`](./level4/clone_list)            | :crystal_ball:     | :white_check_mark: | :no_entry_sign:    |
4 | [`intersection`](./level4/intersection)        | :crystal_ball:     | :white_check_mark: | :no_entry_sign:    |
4 | [`longest_subarray`](./level4/longest_subarray)| :open_file_folder: | :white_check_mark: | :white_check_mark: |
4 | [`range_comb`](./level4/range_comb)            | :open_file_folder: | :no_entry_sign:    | :white_check_mark: |
4 | [`volume_histogram`](./level4/volume_histogram)| :open_file_folder: | :white_check_mark: | :white_check_mark: |
5 | [`count_island`](./level5/count_island)        | :lock:             | :white_check_mark: | :clipboard:        |
5 | [`g_diam`](./level5/g_diam)                    | :open_file_folder: | :no_entry_sign:    | :clipboard:        |
5 | [`infin_add`](./level5/infin_add)              | :open_file_folder: | :white_check_mark: | :clipboard:        |
5 | [`infin_mult`](./level5/infin_mult)            | :open_file_folder: | :white_check_mark: | :clipboard:        |

***
# Concepts:

level | question | program/<br>function | struct?
----: | -------- | :-------------------:| :-----:
0 | [`count_of_2`](./level0/count_of_2)            |:gear: | 
0 | [`equation`](./level0/equation)                |:gear: | 
0 | [`find_pivot`](./level0/find_pivot)            |:gear: | 
0 | [`is_anagram`](./level0/is_anagram)            |:gear: | 
0 | [`print_doublon`](./level0/print_doublon)      |:gear: | 
1 | [`count_alpha`](./level1/count_alpha)          |:pager:| 
1 | [`flood_fill`](./level1/flood_fill)            |:gear: | 
1 | [`height_tree`](./level1/height_tree)          |:gear: | :deciduous_tree:
1 | [`queue`](./level1/queue)                      |:gear: | :books:
1 | [`stack`](./level1/stack)                      |:gear: | :books:
2 | [`is_looping`](./level2/is_looping)            |:gear: | :link:
2 | [`longest_sequence`](./level2/longest_sequence)|:gear: | :deciduous_tree:
2 | [`ord_alphlong`](./level2/ord_alphlong)        |:pager:| 
2 | [`reverse_tree`](./level2/reverse_tree)        |:gear: | :deciduous_tree:
2 | [`str_maxlenoc`](./level2/str_maxlenoc)        |:pager:| 
3 | [`can_split`](./level3/can_split)              |:gear: | :deciduous_tree:
3 | [`convert_bst`](./level3/convert_bst)          |:gear: | :deciduous_tree: :link:
3 | [`gold_gain`](./level3/gold_gain)              |:gear: | 
3 | [`perimeter`](./level3/perimeter)              |:gear: | :deciduous_tree:
3 | [`width_tree`](./level3/width_tree)            |:gear: | :deciduous_tree:
4 | [`clone_list`](./level4/clone_list)            |:gear: | :link:
4 | [`intersection`](./level4/intersection)        |:gear: | :link:
4 | [`longest_subarray`](./level4/longest_subarray)|:gear: | 
4 | [`range_comb`](./level4/range_comb)            |:gear: | 
4 | [`volume_histogram`](./level4/volume_histogram)|:gear: | 
5 | [`count_island`](./level5/count_island)        |:pager:| 
5 | [`g_diam`](./level5/g_diam)                    |:pager:| 
5 | [`infin_add`](./level5/infin_add)              |:pager:| 
5 | [`infin_mult`](./level5/infin_mult)            |:pager:| 

### Hash table
* is_anagram
* count_alpha

### Implementing data structure
* queue
* stack

### N-ary tree
* height_tree

### binary search tree (BST)
* convert_bst
