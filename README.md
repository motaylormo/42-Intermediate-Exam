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

## Level 0
| Question | Solution | Tester main | Trace test<br>accessibility
| -------- | -------- | ----------- | ------------------------
| [count_of_2](./0-count_of_2)       | [:white_check_mark:](./0-count_of_2/mine)    | [:white_check_mark:](./0-count_of_2/tester)    | :open_file_folder:
| [equation](./0-equation)           | [:white_check_mark:](./0-equation/mine)      | [:white_check_mark:](./0-equation/tester)      | :open_file_folder:
| [find_pivot](./0-find_pivot)       | [:white_check_mark:](./0-find_pivot/mine)    | [:white_check_mark:](./0-find_pivot/tester)    | :lock:
| [is_anagram](./0-is_anagram)       | [:white_check_mark:](./0-is_anagram/mine)    | [:white_check_mark:](./0-is_anagram/tester)    | :lock:
| [print_doublon](./0-print_doublon) | [:white_check_mark:](./0-print_doublon/mine) | [:white_check_mark:](./0-print_doublon/tester) | :lock:

## Level 1
| Question | Solution | Tester main | Trace test<br>accessibility
| -------- | -------- | ----------- | ------------------------
| [count_alpha](./1-count_alpha) | [:white_check_mark:](./1-count_alpha/mine) | [:eight_spoked_asterisk:](./1-count_alpha/tester) | :open_file_folder:
| [flood_fill](./1-flood_fill)   | [:white_check_mark:](./1-flood_fill/mine)  | [:white_check_mark:](./1-flood_fill/tester)       | :lock:
| [height_tree](./1-height_tree) | [:white_check_mark:](./1-height_tree/mine) | :no_entry_sign:                                   | :crystal_ball:
| [queue](./1-queue)             | [:white_check_mark:](./1-queue/mine)       | :no_entry_sign:                                   | :crystal_ball:
| [stack](./1-stack)             | [:white_check_mark:](./1-stack/mine)       | :no_entry_sign:                                   | :crystal_ball:

## Level 2
| Question | Solution | Tester main | Trace test<br>accessibility
| -------- | -------- | ----------- | ------------------------
| [is_looping](./2-is_looping)             | [:white_check_mark:](./2-is_looping/mine)       | [:white_check_mark:](./2-is_looping/tester)        | :crystal_ball:
| [longest_sequence](./2-longest_sequence) | [:white_check_mark:](./2-longest_sequence/mine) | [:white_check_mark:](./2-longest_sequence/tester)  | :crystal_ball:
| [ord_alphlong](./2-ord_alphlong)         | [:white_check_mark:](./2-ord_alphlong/mine)     | [:eight_spoked_asterisk:](./2-ord_alphlong/tester) | :open_file_folder:
| [reverse_tree](./2-reverse_tree)         | [:white_check_mark:](./2-reverse_tree/mine)     | [:white_check_mark:](./2-reverse_tree/tester)      | :crystal_ball:
| [str_maxlenoc](./2-str_maxlenoc)         | [:white_check_mark:](./2-str_maxlenoc/mine)     | [:eight_spoked_asterisk:](./2-str_maxlenoc/tester) | :open_file_folder:

## Level 3
| Question | Solution | Tester main | Trace test<br>accessibility
| -------- | -------- | ----------- | ------------------------
| [can_split](./3-can_split)     | [:white_check_mark:](./3-can_split/mine)   | [:white_check_mark:](./3-can_split/tester)  | :crystal_ball:
| [convert_bst](./3-convert_bst) | [:white_check_mark:](./3-convert_bst/mine) | :no_entry_sign:                             | :crystal_ball:
| [gold_gain](./3-gold_gain)     | [:white_check_mark:](./3-gold_gain/mine)   | [:white_check_mark:](./3-gold_gain/tester)  | :lock:
| [perimeter](./3-perimeter)     | [:white_check_mark:](./3-perimeter/mine)   | [:white_check_mark:](./3-perimeter/tester)  | :crystal_ball:
| [width_tree](./3-width_tree)   | [:white_check_mark:](./3-width_tree/mine)  | [:white_check_mark:](./3-width_tree/tester) | :crystal_ball:

## Level 4
| Question | Solution | Tester main | Trace test<br>accessibility
| -------- | -------- | ----------- | ------------------------
| [clone_list](./4-clone_list)             | [:white_check_mark:](./4-clone_list/mine)       | :no_entry_sign:                                   | :crystal_ball:
| [intersection](./4-intersection)         | [:white_check_mark:](./4-intersection/mine)     | :no_entry_sign:                                   | :crystal_ball:
| [longest_subarray](./4-longest_subarray) | [:white_check_mark:](./4-longest_subarray/mine) | [:white_check_mark:](./4-longest_subarray/tester) | :open_file_folder:
| [range_comb](./4-range_comb)             | :no_entry_sign:                                 | :no_entry_sign:
| [volume_histogram](./4-volume_histogram) | [:white_check_mark:](./4-volume_histogram/mine) | [:white_check_mark:](./4-volume_histogram/tester) | :open_file_folder:

## Level 5
| Question | Solution | Tester main | Trace test<br>accessibility
| -------- | -------- | ----------- | ------------------------
| [count_island](./5-count_island) | [:white_check_mark:](./5-count_island/mine) | :no_entry_sign: | :lock:
| [g_diam](./5-g_diam)             | :no_entry_sign:                             | :no_entry_sign:
| [infin_add](./5-infin_add)       | [:white_check_mark:](./5-infin_add/mine)    | [:eight_spoked_asterisk:](./5-infin_add/tester)  | :open_file_folder:
| [infin_mult](./5-infin_mult)     | [:white_check_mark:](./5-infin_mult/mine)   | [:eight_spoked_asterisk:](./5-infin_mult/tester) | :open_file_folder:
