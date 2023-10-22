#include "unit_test.h"

TEST(multiset, allcase) {
  s21::multiset<int> my_multiset;
  my_multiset.insert(10);
  my_multiset.insert(10);
  my_multiset.insert(10);
  my_multiset.insert(10);
  my_multiset.insert(10);
  my_multiset.insert(10);
  my_multiset.insert(10);
  my_multiset.insert(10);
  my_multiset.insert(10);
  my_multiset.insert(10);
  EXPECT_EQ(my_multiset.size(), 10U);
  auto it = my_multiset.begin();
  my_multiset.erase(it);
  EXPECT_EQ(my_multiset.size(), 9U);
  it = my_multiset.begin();
  EXPECT_EQ(*it, 10);
  my_multiset.erase(it);
  EXPECT_EQ(my_multiset.size(), 8U);
}

TEST(multiset_cons, case1) {
  s21::multiset<int> s21_set_int;
  s21::multiset<double> s21_set_double;
  s21::multiset<std::string> s21_set_string;

  EXPECT_EQ(s21_set_int.size(), 0U);
  EXPECT_EQ(s21_set_double.size(), 0U);
  EXPECT_EQ(s21_set_string.size(), 0U);
}

TEST(multiset_cons, case2) {
  s21::multiset<int> s21_set_int{1, 2, 3, 4, 5};
  s21::multiset<double> s21_set_double{1.30359, 2847.4925, 923.39281};
  s21::multiset<std::string> s21_set_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_set_int.size(), 5U);
  EXPECT_EQ(s21_set_double.size(), 3U);
  EXPECT_EQ(s21_set_string.size(), 4U);
}

TEST(multiset_cons, case3) {
  s21::multiset<int> s21_set_ref_int{1, 2, 3, 4, 5};
  s21::multiset<int> s21_set_res_int{s21_set_ref_int};

  s21::multiset<double> s21_set_ref_double{1.30359, 2847.4925, 923.39281};
  s21::multiset<double> s21_set_res_double{s21_set_ref_double};

  s21::multiset<std::string> s21_set_ref_string{"Hello", ",", "world", "!"};
  s21::multiset<std::string> s21_set_res_string{s21_set_ref_string};

  EXPECT_EQ(s21_set_ref_int.size(), s21_set_res_int.size());
  EXPECT_EQ(s21_set_ref_double.size(), s21_set_res_double.size());
  EXPECT_EQ(s21_set_ref_string.size(), s21_set_res_string.size());
}

TEST(multiset_cons, case4) {
  s21::multiset<int> s21_set_ref_int{1, 2, 3, 4, 5};
  s21::multiset<int> s21_set_res_int = std::move(s21_set_ref_int);

  s21::multiset<double> s21_set_ref_double{1.30359, 2847.4925, 923.39281};
  s21::multiset<double> s21_set_res_double = std::move(s21_set_ref_double);

  s21::multiset<std::string> s21_set_ref_string{"Hello", ",", "world", "!"};
  s21::multiset<std::string> s21_set_res_string = std::move(s21_set_ref_string);

  EXPECT_EQ(s21_set_ref_int.size(), 0U);
  EXPECT_EQ(s21_set_res_int.size(), 5U);

  EXPECT_EQ(s21_set_ref_double.size(), 0U);
  EXPECT_EQ(s21_set_res_double.size(), 3U);

  EXPECT_EQ(s21_set_ref_string.size(), 0U);
  EXPECT_EQ(s21_set_res_string.size(), 4U);
}

TEST(multiset_cons, case5) {
  s21::multiset<int> s21_set_ref_int{1, 2, 3, 4, 5};
  s21::multiset<int> s21_set_res_int;
  s21_set_res_int = std::move(s21_set_ref_int);

  s21::multiset<double> s21_set_ref_double{1.30359, 2847.4925, 923.39281};
  s21::multiset<double> s21_set_res_double;
  s21_set_res_double = std::move(s21_set_ref_double);

  s21::multiset<std::string> s21_set_ref_string{"Hello", ",", "world", "!"};
  s21::multiset<std::string> s21_set_res_string;
  s21_set_res_string = std::move(s21_set_ref_string);

  EXPECT_EQ(s21_set_ref_int.size(), 0U);
  EXPECT_EQ(s21_set_res_int.size(), 5U);

  EXPECT_EQ(s21_set_ref_double.size(), 0U);
  EXPECT_EQ(s21_set_res_double.size(), 3U);

  EXPECT_EQ(s21_set_ref_string.size(), 0U);
  EXPECT_EQ(s21_set_res_string.size(), 4U);
}

TEST(multiset_cons, case7) {
  s21::multiset<int> s21_set_ref_int{1, 2, 3, 4};
  s21::multiset<int> s21_set_res_int{s21_set_ref_int};

  s21::multiset<double> s21_set_ref_double{1.30359, 2847.4925, 923.39281, 1.23};
  s21::multiset<double> s21_set_res_double{s21_set_ref_double};

  s21::multiset<std::string> s21_set_ref_string{"Hello", ",", "world", "!"};
  s21::multiset<std::string> s21_set_res_string{s21_set_ref_string};

  auto it_res_int = s21_set_res_int.begin();
  for (auto it_ref_int = s21_set_ref_int.begin();
       it_ref_int <= s21_set_ref_int.end(); ++it_ref_int) {
    EXPECT_EQ(*it_res_int, *it_ref_int);
    ++it_res_int;
  }

  auto it_res_double = s21_set_res_double.begin();
  for (auto it_ref_double = s21_set_ref_double.begin();
       it_ref_double <= s21_set_ref_double.end(); ++it_ref_double) {
    EXPECT_EQ(*it_res_double, *it_ref_double);
    ++it_res_double;
  }

  auto it_res_string = s21_set_res_string.begin();
  for (auto it_ref_string = s21_set_ref_string.begin();
       it_ref_string <= s21_set_ref_string.end(); ++it_ref_string) {
    EXPECT_EQ(*it_res_string, *it_ref_string);
    ++it_res_string;
  }
}

TEST(multiset_insert, case5) {
  s21::multiset<double> s21_set = {21};

  std::pair<s21::multiset<double>::iterator, bool> insert1 =
      s21_set.insert(1.4);
  EXPECT_EQ(insert1.second, true);

  EXPECT_EQ(s21_set.size(), 2U);
}

TEST(multiset_insert, case6) {
  s21::multiset<std::string> s21_set = {"hello"};

  std::pair<s21::multiset<std::string>::iterator, bool> insert1 =
      s21_set.insert("hi");
  EXPECT_EQ(*insert1.first, "hi");
  EXPECT_EQ(insert1.second, true);

  EXPECT_EQ(s21_set.size(), 2U);
}

TEST(multiset_begin, case1) {
  s21::multiset<int> s21_set = {9, 15, 7, 23, 2};

  EXPECT_EQ(*s21_set.begin(), 2);
}

TEST(multiset_begin, case2) {
  s21::multiset<double> s21_set = {11.4, 2.770001, 3.901, 2.77, 3.9};

  EXPECT_EQ(*s21_set.begin(), 2.77);
}

TEST(multiset_begin, case3) {
  s21::multiset<std::string> s21_set = {"hello", "hi", "hi-hi", "hola",
                                        "hello, there"};

  EXPECT_EQ(*s21_set.begin(), "hello");
}

TEST(multiset_begin, case4) {
  s21::multiset<int> s21_set;

  EXPECT_THROW(s21_set.begin(), std::out_of_range);
}

TEST(multiset_begin, case5) {
  s21::multiset<double> s21_set = {1.4, 1.4};

  EXPECT_EQ(*s21_set.begin(), 1.4);
}

TEST(multiset_begin, case6) {
  s21::multiset<std::string> s21_set = {"hello", "hello", "hello"};

  EXPECT_EQ(*s21_set.begin(), "hello");
}

TEST(multiset_end, case1) {
  s21::multiset<int> s21_set = {9, 15, 7, 23, 2};

  EXPECT_EQ(*s21_set.end(), 23);
}

TEST(multiset_end, case2) {
  s21::multiset<double> s21_set = {11.4, 2.770001, 3.901, 11.400000001, 3.9};

  EXPECT_EQ(*s21_set.end(), 11.400000001);
}

TEST(multiset_end, case3) {
  s21::multiset<std::string> s21_set = {"hello", "hi", "hola-hola", "hola",
                                        "hello, there"};

  EXPECT_EQ(*s21_set.end(), "hola-hola");
}

TEST(multiset_end, case4) {
  s21::multiset<int> s21_set;

  EXPECT_THROW(s21_set.end(), std::out_of_range);
}

TEST(multiset_end, case5) {
  s21::multiset<double> s21_set = {1.4, 1.4};

  EXPECT_EQ(*s21_set.end(), 1.4);
}

TEST(multiset_end, case6) {
  s21::multiset<std::string> s21_set = {"hello", "hello", "hello"};

  EXPECT_EQ(*s21_set.end(), "hello");
}

TEST(multiset_balance, case1) {
  s21::multiset<int> s21_set = {1, 15, 5};

  EXPECT_EQ(*s21_set.end(), 15);
  EXPECT_EQ(s21_set.size(), 3U);
}

TEST(multiset_balance, case2) {
  s21::multiset<double> s21_set = {11.4, 2.770001, 3.901};

  EXPECT_EQ(*s21_set.end(), 11.4);
  EXPECT_EQ(s21_set.size(), 3U);
}

TEST(multiset_balance, case3) {
  s21::multiset<std::string> s21_set = {"hello", "hi", "hola-hola", "hola",
                                        "hello, there"};

  EXPECT_EQ(*s21_set.end(), "hola-hola");
  EXPECT_EQ(s21_set.size(), 5U);
}

TEST(multiset_balance, case4) {
  s21::multiset<int> s21_set = {10, 5, 20, 30, 1543};

  EXPECT_EQ(*s21_set.end(), 1543);
  EXPECT_EQ(*s21_set.begin(), 5);
  EXPECT_EQ(s21_set.size(), 5U);
}

TEST(multiset_balance, case5) {
  s21::multiset<int> s21_set = {30, 5, 43, 1, 20, 40, 60, 35, 32};

  EXPECT_EQ(*s21_set.end(), 60);
  EXPECT_EQ(*s21_set.begin(), 1);
  EXPECT_EQ(s21_set.size(), 9U);
}

TEST(multiset_erase, case1) {
  s21::multiset<int> s21_set = {10, 5, 15, 4, 18, 13, 16};

  auto it = s21_set.begin();
  ++it;
  ++it;
  ++it;
  ++it;
  s21_set.erase(it);
  EXPECT_EQ(*s21_set.begin(), 4);
  EXPECT_EQ(*s21_set.end(), 18);
  EXPECT_EQ(s21_set.size(), 6U);

  it = s21_set.begin();
  s21_set.erase(it);
  EXPECT_EQ(*s21_set.begin(), 5);
  EXPECT_EQ(*s21_set.end(), 18);
  EXPECT_EQ(s21_set.size(), 5U);

  it = s21_set.begin();
  ++it;
  s21_set.erase(it);
  EXPECT_EQ(*s21_set.begin(), 5);
  EXPECT_EQ(*s21_set.end(), 18);
  EXPECT_EQ(s21_set.size(), 4U);

  it = s21_set.end();
  s21_set.erase(it);
  EXPECT_EQ(*s21_set.begin(), 5);
  EXPECT_EQ(*s21_set.end(), 16);
  EXPECT_EQ(s21_set.size(), 3U);

  it = s21_set.begin();
  ++it;
  s21_set.erase(it);

  it = s21_set.begin();
  ++it;
  s21_set.erase(it);

  it = s21_set.begin();
  s21_set.erase(it);

  EXPECT_EQ(s21_set.size(), 0U);
}

TEST(multiset_erase, case2) {
  s21::multiset<int> s21_set = {30, 1543};

  auto it = s21_set.begin();
  ++it;
  s21_set.erase(it);
  it = s21_set.begin();
  s21_set.erase(it);

  EXPECT_EQ(s21_set.size(), 0U);
}

TEST(multiset_erase, case3) {
  s21::multiset<std::string> s21_set = {"hello", "hi", "hola-hola", "hola",
                                        "hello, there"};

  auto it = s21_set.end();
  s21_set.erase(it);
  EXPECT_EQ(*s21_set.end(), "hola");
  EXPECT_EQ(s21_set.size(), 4U);

  it = s21_set.end();
  s21_set.erase(it);
  EXPECT_EQ(*s21_set.end(), "hi");
  EXPECT_EQ(s21_set.size(), 3U);

  s21_set.insert("hola-hola");
  s21_set.insert("hola");
  it = s21_set.end();
  s21_set.erase(it);
  EXPECT_EQ(*s21_set.end(), "hola");
  EXPECT_EQ(s21_set.size(), 4U);
}

TEST(multiset_erase, case4) {
  s21::multiset<double> s21_set = {22.2, 12.4457, 56.84, 941.44, 44.48};

  auto it = s21_set.end();
  --it;
  s21_set.erase(it);
  it = s21_set.end();
  EXPECT_EQ(*it, 941.44);
  EXPECT_EQ(s21_set.size(), 4U);

  it = s21_set.begin();
  ++it;
  ++it;
  ++it;
  s21_set.erase(it);
  it = s21_set.begin();
  ++it;
  ++it;
  ++it;
  EXPECT_EQ(*s21_set.end(), 44.48);
  EXPECT_EQ(s21_set.size(), 3U);
}

TEST(multiset_erase, case5) {
  s21::multiset<double> s21_set = {22.2, 44.48, 12.4457, 1.44};

  auto it = s21_set.begin();
  ++it;
  s21_set.erase(it);
  it = s21_set.begin();
  ++it;
  ++it;
  EXPECT_EQ(*it, 44.48);
  EXPECT_EQ(s21_set.size(), 3U);
}

TEST(multiset_erase, case6) {
  s21::multiset<double> s21_set = {22.2, 44.48, 12.4457, 6.84, 1.44};

  auto it = s21_set.begin();
  ++it;
  ++it;
  ++it;
  s21_set.erase(it);
  it = s21_set.begin();
  ++it;
  ++it;
  ++it;
  EXPECT_EQ(*it, 44.48);
  EXPECT_EQ(s21_set.size(), 4U);
}

TEST(multiset_erase, case7) {
  s21::multiset<double> s21_set = {22.2, 12.4457, 56.84, 941.44, 44.48};

  auto it = s21_set.begin();
  ++it;
  s21_set.erase(it);
  it = s21_set.begin();
  ++it;
  EXPECT_EQ(*it, 44.48);
  EXPECT_EQ(s21_set.size(), 4U);
}

TEST(multiset_erase, case8) {
  s21::multiset<double> s21_set = {22.2, 44.48, 12.4457, 1.44};

  auto it = s21_set.begin();
  ++it;
  s21_set.erase(it);
  it = s21_set.begin();
  ++it;
  EXPECT_EQ(*it, 22.2);
  EXPECT_EQ(s21_set.size(), 3U);
}

TEST(multiset_erase, case9) {
  s21::multiset<double> s21_set = {22.2,  44.48, 12.4457, 32.45,
                                   65.12, 66.32, 40.54,   6.4};

  auto it = s21_set.end();
  --it;
  --it;
  --it;
  --it;
  s21_set.erase(it);
  it = s21_set.begin();
  ++it;
  ++it;
  ++it;
  EXPECT_EQ(*it, 40.54);
  EXPECT_EQ(s21_set.size(), 7U);
}

TEST(multiset_erase, case10) {
  s21::multiset<double> s21_set = {22.2};

  auto it = s21_set.end();
  --it;
  ++it;
  s21_set.erase(it);
  EXPECT_EQ(s21_set.size(), 0U);
}

TEST(multiset_empty, case1) {
  s21::multiset<double> s21_set = {22.2, 44.48, 12.4457, 1.44};

  EXPECT_EQ(s21_set.empty(), 0);
}

TEST(multiset_empty, case2) {
  s21::multiset<double> s21_set;

  EXPECT_EQ(s21_set.empty(), 1);
}

TEST(multiset_ms, case1) {
  s21::multiset<double> s21_set;
  std::set<double> std_set;

  EXPECT_EQ(s21_set.max_size(), std_set.max_size());
}

TEST(multiset_ms, case2) {
  s21::multiset<double> s21_set = {22.2, 44.48, 12.4457, 1.44};

  std::set<double> std_set = {22.2, 44.48, 12.4457, 1.44};

  EXPECT_EQ(s21_set.max_size(), std_set.max_size());
}

TEST(multiset_sw, case1) {
  s21::multiset<double> s21_set_ref = {22.2, 44.48};
  s21::multiset<double> s21_set_res = {12.4457, 1.44, 22.2};

  s21_set_ref.swap(s21_set_res);

  EXPECT_EQ(s21_set_ref.size(), 3U);
  EXPECT_EQ(*s21_set_ref.begin(), 1.44);

  EXPECT_EQ(s21_set_res.size(), 2U);
  EXPECT_EQ(*s21_set_res.begin(), 22.2);
}

TEST(multiset_sw, case2) {
  s21::multiset<double> s21_set_ref = {22.2, 44.48};
  s21::multiset<double> s21_set_res;

  s21_set_ref.swap(s21_set_res);

  EXPECT_EQ(s21_set_ref.size(), 0U);

  EXPECT_EQ(s21_set_res.size(), 2U);
  EXPECT_EQ(*s21_set_res.begin(), 22.2);
}

TEST(multiset_sw, case3) {
  s21::multiset<double> s21_set_ref;
  s21::multiset<double> s21_set_res = {12.4457, 1.44, 22.2};

  s21_set_ref.swap(s21_set_res);

  EXPECT_EQ(s21_set_ref.size(), 3U);
  EXPECT_EQ(*s21_set_ref.begin(), 1.44);

  EXPECT_EQ(s21_set_res.size(), 0U);
}

TEST(multiset_sw, case4) {
  s21::multiset<double> s21_set_ref;
  s21::multiset<double> s21_set_res;

  s21_set_ref.swap(s21_set_res);

  EXPECT_EQ(s21_set_ref.size(), 0U);
  EXPECT_EQ(s21_set_res.size(), 0U);
}

TEST(multiset_cont, case1) {
  s21::multiset<double> s21_set = {22.2, 44.48};

  EXPECT_EQ(s21_set.contains(22.2), true);
  EXPECT_EQ(s21_set.contains(44.48), true);
}

TEST(multiset_cont, case2) {
  s21::multiset<double> s21_set_ref = {22.2, 44.48};
  s21::multiset<double> s21_set_res;

  s21_set_ref.swap(s21_set_res);

  EXPECT_EQ(s21_set_ref.size(), 0U);
  EXPECT_EQ(s21_set_ref.contains(22.2), false);
  EXPECT_EQ(s21_set_ref.contains(44.48), false);

  EXPECT_EQ(s21_set_res.size(), 2U);
  EXPECT_EQ(s21_set_res.contains(22.2), true);
  EXPECT_EQ(s21_set_res.contains(44.48), true);
}

TEST(multiset_cont, case3) {
  s21::multiset<double> s21_set_ref;
  s21::multiset<double> s21_set_res = {12.4457, 1.44, 22.2};

  s21_set_ref.swap(s21_set_res);

  EXPECT_EQ(s21_set_ref.size(), 3U);
  EXPECT_EQ(s21_set_ref.contains(12.4457), true);
  EXPECT_EQ(s21_set_ref.contains(1.44), true);
  EXPECT_EQ(s21_set_ref.contains(22.2), true);

  EXPECT_EQ(s21_set_res.size(), 0U);
  EXPECT_EQ(s21_set_res.contains(12.4457), false);
  EXPECT_EQ(s21_set_res.contains(1.44), false);
  EXPECT_EQ(s21_set_res.contains(22.2), false);
}

TEST(multiset_cont, case4) {
  s21::multiset<double> s21_set;

  EXPECT_EQ(s21_set.size(), 0U);
  EXPECT_EQ(s21_set.contains(12.4457), false);
}

TEST(multiset_find, case1) {
  s21::multiset<double> s21_set;

  EXPECT_THROW(s21_set.find(23.4), std::out_of_range);
}

TEST(multiset_find, case2) {
  s21::multiset<double> s21_set = {12.4457, 1.44, 22.2};

  auto it = s21_set.begin();
  ++it;
  EXPECT_EQ(*s21_set.find(12.4457), *it);

  --it;
  EXPECT_EQ(*s21_set.find(1.44), *it);

  ++it;
  ++it;
  EXPECT_EQ(*s21_set.find(22.2), *it);
}

TEST(test, ConstructorsList) {
  s21::multiset<int> new_multiset;

  std::initializer_list<int> items{1, 1, 1, 2, 1, 1, 1, 1, 3, 4};
  s21::multiset<int> my_multiset2(items);
  std::multiset<int> std_multiset2(items);
  auto my_iter = my_multiset2.begin();
  auto std_iter = std_multiset2.begin();
  while (my_iter <= my_multiset2.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
  // s21::multiset<int>new_multiset4 = std::move(new_multiset3);
  // s21::multiset<int>new_multiset5 = new_multiset4;
}

TEST(test, ConstructorsList2) {
  std::initializer_list<int> items{2, 1, 2, 2};
  s21::multiset<int> my_multiset2(items);
  std::multiset<int> std_multiset2(items);
  auto my_iter = my_multiset2.begin();
  auto std_iter = std_multiset2.begin();
  while (my_iter <= my_multiset2.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, ConstructorsCopy) {
  s21::multiset<int> new_multiset;

  std::initializer_list<int> items{2, 1, 3, 4};
  s21::multiset<int> my_multiset2(items);
  std::multiset<int> std_multiset2(items);

  s21::multiset<int> my_multiset3(my_multiset2);
  std::multiset<int> std_multiset3(std_multiset2);
  auto my_iter = my_multiset3.begin();
  auto std_iter = std_multiset3.begin();
  while (my_iter <= my_multiset3.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }

  // s21::multiset<int>new_multiset5 = new_multiset4;
}

TEST(test, ConstructorsMove) {
  std::initializer_list<int> items{2, 1, 2, 2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  s21::multiset<int> my_multiset2 = std::move(my_multiset);
  std::multiset<int> std_multiset2 = std::move(std_multiset);

  auto my_iter = my_multiset2.begin();
  auto std_iter = std_multiset2.begin();
  while (my_iter <= my_multiset2.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, ConstructorsMove2) {
  std::initializer_list<int> items{2, 1, 2, 2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  s21::multiset<int> my_multiset2 = my_multiset;
  std::multiset<int> std_multiset2 = std_multiset;

  auto my_iter = my_multiset2.begin();
  auto std_iter = std_multiset2.begin();
  while (my_iter <= my_multiset2.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, IteratorTest) {
  std::initializer_list<int> items{1, 2, 3};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  while (my_iter <= my_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, IteratorTestSolo) {
  std::initializer_list<int> items{2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();

  while (my_iter <= my_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, IteratorTestDoubleInc) {
  std::initializer_list<int> items{1, 2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();

  while (my_iter <= my_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, IteratorTestDoubleDec) {
  std::initializer_list<int> items{2, 1};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();

  while (my_iter <= my_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Insert) {
  // std::initializer_list<int> items{1,5,3,2,};
  s21::multiset<int> my_multiset;
  std::multiset<int> std_multiset;
  my_multiset.insert(1);
  std_multiset.insert(1);
  my_multiset.insert(-1);
  std_multiset.insert(-1);
  my_multiset.insert(45);
  std_multiset.insert(45);
  my_multiset.insert(-24);
  std_multiset.insert(-24);
  my_multiset.insert(-24);
  std_multiset.insert(-24);
  my_multiset.insert(-24);
  std_multiset.insert(-24);
  my_multiset.insert(24);
  std_multiset.insert(24);
  my_multiset.insert(-24000);
  std_multiset.insert(-24000);
  my_multiset.insert(-2400);
  std_multiset.insert(-2400);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Erase1) {
  std::initializer_list<int> items{1, 5, 3, 2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  ++std_iter;
  ++my_iter;
  ++std_iter;
  ++my_iter;
  std_multiset.erase(std_iter);
  my_multiset.erase(my_iter);
  my_iter = my_multiset.begin();
  std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Erase2) {
  std::initializer_list<int> items{1, 5, 3, 4};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  ++std_iter;
  ++my_iter;
  ++std_iter;
  ++my_iter;
  std_multiset.erase(std_iter);
  my_multiset.erase(my_iter);
  my_iter = my_multiset.begin();
  std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Erase3) {
  std::initializer_list<int> items{1, 5, 7, 6};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  ++std_iter;
  ++my_iter;
  ++std_iter;
  ++my_iter;
  ++std_iter;
  ++my_iter;
  std_multiset.erase(std_iter);
  my_multiset.erase(my_iter);
  my_iter = my_multiset.begin();
  std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Erase4) {
  std::initializer_list<int> items{1, 5, 7, 8};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  ++std_iter;
  ++my_iter;
  ++std_iter;
  ++my_iter;
  std_multiset.erase(std_iter);
  my_multiset.erase(my_iter);
  my_iter = my_multiset.begin();
  std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Erase5) {
  std::initializer_list<int> items{1, 5, 7, 6};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  std_multiset.erase(std_iter);
  my_multiset.erase(my_iter);
  my_iter = my_multiset.begin();
  std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Erase6) {
  std::initializer_list<int> items{5, 1, 7, 6};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  std_multiset.erase(std_iter);
  my_multiset.erase(my_iter);
  my_iter = my_multiset.begin();
  std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Clear) {
  std::initializer_list<int> items{1, 5, 7, 6};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  my_multiset.clear();
  std_multiset.clear();
  ASSERT_TRUE(my_multiset.size() == 0);
}

TEST(test, Clear2) {
  s21::multiset<int> my_multiset;
  std::multiset<int> std_multiset;
  my_multiset.clear();
  std_multiset.clear();
  ASSERT_TRUE(my_multiset.size() == 0);
}

TEST(test, Swap) {
  std::initializer_list<int> items{1, 5, 7, 6};
  std::initializer_list<int> items2{17, 25, 57, 66, 34, 12, 5};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  s21::multiset<int> my_multiset2(items2);
  std::multiset<int> std_multiset2(items2);
  my_multiset.swap(my_multiset2);
  std_multiset.swap(std_multiset2);

  ASSERT_TRUE(my_multiset.size() == std_multiset.size());
  ASSERT_TRUE(my_multiset2.size() == std_multiset2.size());

  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
  auto my_iter2 = my_multiset2.begin();
  auto std_iter2 = std_multiset2.begin();
  while (std_iter2 != std_multiset2.end()) {
    ASSERT_TRUE(*my_iter2 == *std_iter2);
    ++my_iter2;
    ++std_iter2;
  }
}

TEST(test, lower_bound) {
  std::initializer_list<int> items{10, 50, 30, 30, 60, 20, 23, 40};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_iter = my_multiset.lower_bound(30);
  auto std_iter = std_multiset.lower_bound(30);
  ASSERT_TRUE(*my_iter == *std_iter);
  my_iter = my_multiset.lower_bound(23);
  std_iter = std_multiset.lower_bound(23);
  ASSERT_TRUE(*my_iter == *std_iter);
  my_iter = my_multiset.lower_bound(10);
  std_iter = std_multiset.lower_bound(10);
  ASSERT_TRUE(*my_iter == *std_iter);
  my_iter = my_multiset.lower_bound(40);
  std_iter = std_multiset.lower_bound(40);
  ASSERT_TRUE(*my_iter == *std_iter);
}

TEST(test, upper_bound) {
  std::initializer_list<int> items{10, 50, 30, 30, 60, 20, 23, 40};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_iter = my_multiset.upper_bound(30);
  auto std_iter = std_multiset.upper_bound(30);
  ASSERT_TRUE(*my_iter == *std_iter);
  my_iter = my_multiset.upper_bound(23);
  std_iter = std_multiset.upper_bound(23);
  ASSERT_TRUE(*my_iter == *std_iter);
  my_iter = my_multiset.upper_bound(10);
  std_iter = std_multiset.upper_bound(10);
  ASSERT_TRUE(*my_iter == *std_iter);
  my_iter = my_multiset.upper_bound(40);
  std_iter = std_multiset.upper_bound(40);
  ASSERT_TRUE(*my_iter == *std_iter);
}

TEST(test, equal_range) {
  std::initializer_list<int> items{1, 2, 2, 3, 3, 3, 3, 3, 3, 5, 2, 35, 463, 2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_pair = my_multiset.equal_range(2);
  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator>
      std_pair = std_multiset.equal_range(2);

  auto my_iter = my_pair.first;
  auto std_iter = std_pair.first;

  while (my_iter <= my_pair.second) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }

  my_iter = my_pair.first;
  std_iter = std_pair.first;

  while (std_iter != std_pair.second) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, multisetEmplace) {
  std::initializer_list<int> items{1, 2, 3};
  std::initializer_list<int> items2{2, 3, 543};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  std::multiset<int> std_multiset2(items2);
  std_multiset.merge(std_multiset2);
  my_multiset.insert_many(2, 3, 543);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  while (my_iter <= my_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}