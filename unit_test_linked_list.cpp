#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  https://hackingcpp.com/cpp/tools/testing_frameworks.html
 */

#include "doctest.h"
#include "linked_list.h"


int zero_linked_list_elts = 0;
struct node * zero_linked_list_elts_null_node = NULL;

int one_element_linked_list = 1;
int data_value_of_initial_linked_list_elt = 1;
struct node * linked_list_one_elt = build_new_linked_list(one_element_linked_list);

int two_element_linked_list = 2;
int data_value_of_second_elt = 2;
struct node * linked_list_two_elts = build_new_linked_list(two_element_linked_list);

int ten_thousand_element_linked_list = 10000;
int data_value_of_tenthousands_elt = 10000;
struct node * linked_list_ten_thousand_elts = build_new_linked_list(ten_thousand_element_linked_list);

int zero_elt_linked_list_using_build_function = 0;
struct node *zero_linked_list_using_build_function = build_new_linked_list(0);


// used for testing deletion of list containing values that have all been updated
int linked_list_with_all_updated_vals_num=10;
struct node *linked_list_with_all_updated_vals = build_new_linked_list(linked_list_with_all_updated_vals_num);


TEST_CASE("linked_list testing") {

    SUBCASE("build_new_linked_list") {
        CHECK_EQ(build_new_linked_list(zero_linked_list_elts), zero_linked_list_elts_null_node);
        CHECK_EQ(get_linked_list_data_item_value( 
            linked_list_one_elt,
            one_element_linked_list,
            one_element_linked_list), 
            data_value_of_initial_linked_list_elt);

        CHECK_EQ(get_linked_list_data_item_value( 
            linked_list_two_elts,
            two_element_linked_list,
            two_element_linked_list), 
            data_value_of_second_elt);

        // print_linked_list(linked_list_one_elt, 1);
        // print_linked_list(linked_list_two_elts, 2);

        delete_linked_list(linked_list_one_elt);
        linked_list_one_elt = nullptr; // should set a pointer to null ptr after deleting what it pointed to
        one_element_linked_list = 0;

        CHECK_EQ(get_linked_list_data_item_value(
            linked_list_one_elt,
            one_element_linked_list,
            0),
            -1
        );

        CHECK_FALSE(update_data_in_linked_list(linked_list_one_elt, 1, 4, 0));

        int updated_first_val=5;
        CHECK(update_data_in_linked_list(linked_list_two_elts, 0, updated_first_val, two_element_linked_list));
        print_linked_list(linked_list_two_elts, two_element_linked_list);

        // before deletion test
        CHECK_EQ(get_linked_list_data_item_value(linked_list_two_elts, 0, two_element_linked_list), updated_first_val);
        delete_linked_list(linked_list_two_elts);
        linked_list_two_elts = nullptr; // should set a pointer to null ptr after deleting what it pointed to
        two_element_linked_list = 0;

        // after deletion test
        CHECK_EQ(get_linked_list_data_item_value(linked_list_two_elts, 0, 0), -1);

        // deleting an already-deleted list
        delete_linked_list(linked_list_two_elts);

        // should do nothing
        delete_linked_list(zero_linked_list_elts_null_node);

        delete_linked_list(zero_linked_list_using_build_function);

        // testing deletion of a linked list that has been completely updated
        int some_big_number=10'000;
        for (int node_to_update=0; node_to_update < linked_list_with_all_updated_vals_num; node_to_update++) {
            CHECK(update_data_in_linked_list(
                linked_list_with_all_updated_vals,
                node_to_update,
                (some_big_number+node_to_update),
                linked_list_with_all_updated_vals_num
            ));
        }
        delete_linked_list(linked_list_with_all_updated_vals);

    }

}