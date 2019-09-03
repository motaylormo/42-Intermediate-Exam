# 42-Intermediate-Exam
Moulinette-passing versions of Intermediate Exam questions.<br>Subject + trace + my passing code + sometimes a test main.

<details><summary><b>Table conventions</b></summary>

Trace test accessibility refers to, "When I look at the trace for this question, can I tell what the tests are?"
* :open_file_folder: means yes—the tests are accessible.
* :lock: means no—the tests are locked away in files. It might look something like:
```
= Test 1 ===================================================
$> ./3sdnrgu2oip0738azjrotz8n test_correct_a_00.txt test_correct_b_00.txt
$> diff -U 3 user_output_test1 test1.output | cat -e
```
* :crystal_ball: means the traces show _something_, but not enough to recreate the test ourselves. This is particularly common among questions that take structs as input.
</details>

Level | Question | Trace | Solution | Test main
----: | -------- | ----- | -------- | ---------
0 | [`count_of_2`](./level0/count_of_2)          | :open_file_folder: | :white_check_mark: | :white_check_mark:
0 | [`equation`](./level0/equation)              | :open_file_folder: | :white_check_mark: | :white_check_mark:
0 | [`find_pivot`](./level0/find_pivot)          | :lock:             | :white_check_mark: | :white_check_mark:
0 | [`is_anagram`](./level0/is_anagram)          | :lock:             | :white_check_mark: | :white_check_mark:
0 | [`print_doublon`](./level0/print_doublon)    | :lock:             | :white_check_mark: | :white_check_mark:
1 | `count_alpha`      | :open_file_folder: | :white_check_mark: | :clipboard:
1 | `flood_fill`       | :lock:             | :white_check_mark: | :white_check_mark:
1 | `height_tree`      | :crystal_ball:     | :white_check_mark: | :no_entry_sign:
1 | `queue`            | :crystal_ball:     | :white_check_mark: | :no_entry_sign:
1 | `stack`            | :crystal_ball:     | :white_check_mark: | :no_entry_sign:
2 | `is_looping`       | :crystal_ball:     | :white_check_mark: | :white_check_mark:
2 | `longest_sequence` | :crystal_ball:     | :white_check_mark: | :white_check_mark:
2 | `ord_alphlong`     | :open_file_folder: | :white_check_mark: | :clipboard:
2 | `reverse_tree`     | :crystal_ball:     | :white_check_mark: | :white_check_mark:
2 | `str_maxlenoc`     | :open_file_folder: | :white_check_mark: | :clipboard:
3 | `can_split`        | :crystal_ball:     | :white_check_mark: | :white_check_mark:
3 | `convert_bst`      | :crystal_ball:     | :white_check_mark: | :no_entry_sign:
3 | `gold_gain`        | :lock:             | :white_check_mark: | :white_check_mark:
3 | `perimeter`        | :crystal_ball:     | :white_check_mark: | :white_check_mark:
3 | `width_tree`       | :crystal_ball:     | :white_check_mark: | :white_check_mark:
4 | `clone_list`       | :crystal_ball:     | :white_check_mark: | :no_entry_sign:
4 | `intersection`     | :crystal_ball:     | :white_check_mark: | :no_entry_sign:
4 | `longest_subarray` | :open_file_folder: | :white_check_mark: | :white_check_mark:
4 | `range_comb`       |                    | :no_entry_sign:    | :no_entry_sign:
4 | `volume_histogram` | :open_file_folder: | :white_check_mark: | :white_check_mark:
5 | `count_island`     | :lock:             | :white_check_mark: | :clipboard:
5 | `g_diam`           |                    | :no_entry_sign:    | :no_entry_sign:
5 | `infin_add`        | :open_file_folder: | :white_check_mark: | :clipboard:
5 | `infin_mult`       | :open_file_folder: | :white_check_mark: | :clipboard:

***
# Concepts:
### Hash table
* is_anagram
* count_alpha

### Implementing data structure
* queue
* stack

## Tree
### N-ary tree
* height_tree

### binary search tree (BST)
* convert_bst

### Binary tree
* reverse_tree
* longest_sequence
* width_tree
* perimeter
* can_split

## Linked list
* is_looping
* clone_list
* intersection
