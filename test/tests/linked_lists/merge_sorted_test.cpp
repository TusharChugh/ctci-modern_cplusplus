#include <linked_lists/merge_sorted.h>
#include <gtest/gtest.h>

TEST(MERGE_SORTED, DEMO){
    auto list1 = make_list({5, 4, 1});
    auto list2 = make_list({6, 3, 2});
    auto merged = algorithm::merge_sorted(list1, list2);
    int expected_value = 1;
	while(merged) {
	   ASSERT_EQ(expected_value++, merged->val);
	   merged = merged->next;
	}
}