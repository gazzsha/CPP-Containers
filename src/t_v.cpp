// #include <iostream>
// #include "s21_vector.h"
// #include <vector>
// #include <algorithm>

// int main() {

//     s21_vector<int> n(10);
//     s21_vector <int> v = n;
//     std::vector<int> vv(10);

//    std::cout << v.capacity();
//    std::cout << v.at(5);
//    v[9] = 10;

//     for (auto i = 0; i < v.size(); i++) {
//         std::cout << v[i] << " ";
//     }

//     std::cout << "\n";
//     s21_vector<int>::iterator it = v.begin();
//     *it = 2131;
//     std::cout << *it;
//     s21_vector<std::string> ss;
//    std::for_each(v.begin(), v.end(), [](const int n) { std::cout << n << ' ';
//    }); std::cout << "\n"; std::cout << ss.empty();

//    std::cout << "\n";

//    s21_vector<std::string> c;
//    std::vector<std::string> cc;
//    std::cout << c.max_size() << " --- " << cc.max_size();
//    std::cout << "\n";
//     std::vector<std::string> ss1(5);
//    s21_vector<std::string> ss_v(5);
//   std::cout << ss1[1];
//   std::cout << ss_v[1];
//      std::cout << "\n";
//  // for (auto n : ss1) std::cout<<n;

//    std::cout << ss1.capacity() << " - " << ss_v.capacity() << "\n";
//    ss1.reserve(10);
//    ss_v.reserve(10);
//      std::cout << ss1.capacity() << " - " << ss_v.capacity() << " | " <<
//      ss1.size() << " - " << ss_v.size() << "\n"; ss1.shrink_to_fit();
//      ss_v.shrink_to_fit();
//      std::cout << ss1.capacity() << " - " << ss_v.capacity() << " | " <<
//      ss1.size() << " - " << ss_v.size() << "\n"; ss1.clear(); ss_v.clear();
//      std::cout << ss1.capacity() << " - " << ss_v.capacity() << " | " <<
//      ss1.size() << " - " << ss_v.size() << "\n";

//     std::cout << "-------------------------\n";

//     auto pr = [](auto& n) { for (const auto v : n) std::cout << v << " "; };

//     s21_vector<int> is_v(5);
//     std::vector<int> is(5);

//     pr(is_v);
//     std::cout << "\n";
//     pr(is);
//      std::cout << "\n";

//     is_v.pop_back();
//     is.pop_back();

//     pr(is_v);
//     std::cout << "\n";
//     pr(is);
//      std::cout << "\n";
//      std::cout << is.capacity() << " - " << is_v.capacity() << " | " <<
//      is.size() << " - " << is_v.size() << "\n"; s21_vector<int>::iterator
//      it1_v = is_v.end(); std::vector<int>::iterator it1 = is.end();
//      *(--it1_v) = 5;
//      *(--it1) = 5;
//          std::cout << "\n";
//      pr(is_v);
//     std::cout << "\n";
//     pr(is);
//      std::cout << "\n";
//      is.push_back(100);
//      is_v.push_back(100);
//           is.push_back(50);
//      is_v.push_back(50);
//           is.push_back(20);
//      is_v.push_back(20);
//           std::cout << "\n";
//      pr(is_v);
//     std::cout << "\n";
//     pr(is);
//      std::cout << "\n";
//      std::cout << is.capacity() << " - " << is_v.capacity() << " | " <<
//      is.size() << " - " << is_v.size() << "\n";

//     //  is.emplace_back(10,20,20);
//     //  pr(is);

//     std::vector<std::string> a(5);
//     a.push_back("abc");
//     pr(a);
//     std::cout<<"size : " << a.size() << "\n";
//   //  a.emplace_back("abc","abbc");
//     pr(a);
//         std::cout<<"size : " << a.size() << "\n";
//     std::cout << "\n";
//      s21_vector<std::string> b(5);
//     b.push_back("abc");
//         std::cout<<"size : " << b.size() << "\n";
//     pr(b);
//   //  b.emplace_back("abc","abbc");
//     pr(b);
//         std::cout<<"size : " << b.size() << "\n";
//     std::cout << "\n";
//     pr(is);
//     std::cout << is.size() << " " << is.capacity() << "\n";
//     is.erase(is.end() - 1);
//     std::cout << "\n";
//     pr(is);
//      std::cout << is.size() << " " << is.capacity() << "\n";

//      std::cout << "------------------\n";

//      std::vector<std::string> z;
//      s21_vector<std::string> z_v;
//      z.push_back("abc");
//      z.push_back("cdv");
//      z.push_back("321");

//       z_v.push_back("abc");
//      z_v.push_back("cdv");
//       z_v.push_back("321");
//      pr(z);
//     std::cout << "\n";

//      pr(z_v);
// std::cout << "\n";
//       std::cout << z.size() << " " << z.capacity() << "\n";
//       std::cout << z_v.size() << " " << z_v.capacity() << "\n";
//  //     z_v.erase(z_v.begin() + 1);
//       //std::cout << *(z_v.begin() + 1) << "\n";
//       pr(z_v);
//       std::cout << "\n";
//       std::cout << "===========\n";
//       auto it_v = z_v.insert(z_v.end(),"100");
//       pr(z_v);
//      std::cout << *it_v << "\n";
//       std::cout << "\n";
//       auto it_o = z.insert(z.end(),"100");
//       pr(z);
//       std::cout << *it_o<<"\n";
//         std::cout << "===========\n";
//         s21_vector<std::string>  mm = {"anc","dff","ff"};
//         std::vector<std::string>  m = {"anc","dff","ff"};
//         pr(mm);
//               std::cout << "\n";

//        mm.reserve(10);

//        auto itvv =  mm.insert_many(mm.end(),"aaa","bbbb","ccccc");

//        std::cout << *itvv << "\n";

//         pr(mm);

//         mm.insert_many_back("A1","B2","B3");

//         std::cout << "\n";
//         pr(mm);

//         std::cout << "\n";
//         pr(m);
//        auto nn =  m.erase(m.end()-1);

//     std::cout << *nn << "===";
//         std::cout << "\n";

//         pr(m);

//     // int * p = v.data();
//     // std::cout << *(p+9);
//     // std::vector<int>::iterator it = vv.begin();
//     // std::cout << *it;
//     // s21_vector<int>::iterator it;
//     // std::cout << *it;

//     // std::vector<int> b(55);
//     // std::cout << b.at(100);

// }

// #include <vector>
// #include "s21_containers.h"

// int main() {
//   s21::vector<int> s21_v1{1, 2, 3};
//   s21::vector<int> s21_v2{4, 5, 6};
//   s21_v2 = std::move(s21_v1);
// }

// #include <iostream>
// #include <vector>

// #include "s21_vector.h"
// struct Base {
//   Base() { print(); }
//   virtual void print() { std::cout << "Base\n"; }
//   ~Base() { print(); }
// };

// struct Derived : Base {
//   Derived() { print(); }
//   void print() override { std::cout << "Derived\n"; }
//   ~Derived() { print(); }
// };

// int main() {
//   Base* base = new Derived();
//   base->print();

//   delete base;

//   s21::vector<int> v{1, 23, 4};
//   v.swap(v);
//   for (auto n : v) {
//     std::cout << n << " ";
//   }
// }
////// LIST ==============
                    // #include "s21_vector.h"
                    // #include "s21_list.h"
                    // #include <iostream>
                    // #include <list>
                    // #include <string>
                    // #include <iterator>


                    // template <typename value_type>
                    // bool compare_lists(s21::list<value_type> my_list,
                    //                    std::list<value_type> std_list) {
                    //   bool result = true;
                    //   if (my_list.size() == std_list.size()) {
                    //     auto my_it = my_list.begin();
                    //     auto std_it = std_list.begin();
                    //     for (size_t i = 0; i != my_list.size(); ++i) {
                    //       if (*my_it != *std_it) {
                    //         result = false;
                    //         break;
                    //       }
                    //       ++my_it;
                    //       ++std_it;
                    //     }
                    //   } else {
                    //     result = false;
                    //   }
                    //   return result;
                    // }



                    // int main() { 

                    //     s21::list<std::string> l {"ab423423423432432c","bbc","ddd","321"};
                    //     l.print_data();
                    //     l.insert(l.begin(),"ffff");
                    //     l.push_back("fffff");
                    //     l.print_data();
                    //     s21::list<std::string> v(l);
                    //     std::cout << "\n";
                    //      v.print_data();
                    // std::cout << "\n";
                    //      s21::list<std::string> m(v);
                    //      m.print_data();
                    //      m.erase(++(m.begin()));
                    //      std::cout << "====ERASE CHECK\n";

                    //           m.print_data();
                    //     std::cout << "====CLEAR CHECK\n";
                    //  //   m.clear();
                    //     std::cout << "====INSERT CHECK\n";
                    //     std::cout << "BEFORE:\n";
                    //     l.print_data();
                    //     std::cout<< "AFTER:\n";
                    //     l.insert(++l.end(),"new elem");
                    //     l.print_data();
                    //    l.pop_back();
                    //     l.pop_back();
                    //     l.pop_back();
                    //     l.pop_back();
                    //     l.pop_back();
                    //     l.push_front("new elem");
                    //     l.pop_front();
                    //     l.pop_front();
                    //     l.pop_back();



                    //    l.print_data();
                    //    l.swap(m);
                    //    std::cout <<"AFTER SWAP FIRST\n";
                    //      l.print_data();
                    //    std::cout <<"AFTER SWAP SECOND\n";
                    //    m.print_data();
                    //    std::cout <<"copy constrcution\n";




                    //   s21::list<std::string> copy(l);
                    //    copy.print_data();
                    //    std::cout << "-----\n";
                    //    copy.push_back("1");
                    //    copy.push_back("2");
                    //    copy.push_back("3");
                    //    copy.push_back("4");
                    //    copy.push_back("5");
                    //     copy.push_back("6");
                    //    copy.print_data();
                    //    copy.reverse();
                    //    std::cout << "-----AFTER RESERVE\n";
                    //    copy.print_data();
                    //       std::cout << "-----SORT\n";
                    //       s21::list<int> l_s {23,432,123,43,45654,21,32,3423,542,234,2,3,45,2,3434,542,2,0,-32,432};
                    //       l_s.print_data(); 
                    //       l_s.sort();
                    //    std::cout << "-----AFTER SORT\n";
                    //    l_s.print_data();
                    //    std::cout << "-----NEW SORT\n";
                    //     s21::list<int> l_s2 {1,3,5,6,2,4,-444,100000,200000,-213,32};
                    //       l_s2.print_data(); 
                    //        auto ittt = --l_s2.end();
                    //           std::cout << "---" << *ittt << "\n";
                    //       l_s2.sort();
                    //    std::cout << "-----AFTER SORT\n";
                    //    l_s2.print_data();
                    //    std::cout << "-----AFTER MERGE\n";
                    //    l_s.merge(l_s2);
                    //    l_s.print_data();
                    //    l_s2.print_data();
                    //       std::cout << "---" << *ittt << "\n";


                    //     auto f = []( auto & n ){ for ( auto& i : n) { std::cout << i <<"\n";}};

                    //       std::list<int> ex {1,2,3,4,5};
                    //       std::list<int> ex1 {11,22,33};
                    //       auto tt = ex.end();

                    //       ex.splice(tt,ex1);
                    //       f(ex);
                    //       f(ex1);
                          
                    //          std::cout << "-----SPLICE\n";
                    //         s21::list<int> ex_ {1,2,3,4,5};
                    //       s21::list<int> ex_1 {11,22,33};
                    //             auto tt_ = ex_.cend();
                    //       ex_.splice(tt_,ex_1);
                    //       f(ex_);
                    //       f(ex_1);

                    //   std::cout << "-----BEFORE UNIUE\n";
                    //    // l_s.push_back(200000);

                    //     s21::list<int> l_ss {0,0,0};

                    //      l_ss.print_data();
                    //       std::cout << "-----AFTER UNIQUE\n";
                    //       l_ss.unique();
                    //       l_ss.print_data();

                    //  std::cout << "-----AFTER INSERT MANY\n";
                    //     l_ss.insert_many(++l_ss.cbegin(),1,2,3,4,5,0);
                    //     l_ss.print_data();
                    //      std::cout << "-----AFTER INSERT MANY BACK\n";
                    //      l_ss.insert_many_back(10,11,223,342);
                    //      f(l_ss);
                    //         std::cout << "-----AFTER INSERT MANY FRONT\n";
                    //      l_ss.insert_many_front(999,99,213,3213213);
                    //      f(l_ss);





//      s21::list<int> my_list{1, 2, 3, 4, 5};
//   std::list<int> std_list{1, 2, 3, 4, 5};
//   f(my_list);
//   f(std_list);
//   std::cout << "RESULT: " << compare_lists(my_list,std_list);


//  s21::list<int> my_list{1, 2, 3};
//   s21::list<int> my_list_copy(my_list);
//   s21::list<int> my_list_move(std::move(my_list));
// std::cout << "----\n";
//   s21::list<int> my_list1{1, 9999, 20000};
//   s21::list<int> my_list2;
//   my_list1.splice(my_list1.cbegin(), my_list2);

//   std::list<int> std_list1{1, 9999, 20000};
//   std::list<int> std_list2;
//   std_list1.splice(std_list1.cbegin(), std_list2);
//    f(std_list2);




    // s21::list<std::string>::ListIterator it = m.begin();
    // std::cout << *(++it) << "\n";

    // std::cout << m.back() << "\n";
    // std::cout << m.empty()<< "\n";
    
  //  m.front() = "first element";
    //std::cout << m.front() << "\n";





    // std::string a = "abc";
    // a.~string();
    // std::cout << a;

    // auto pr = [](auto& n) { for (const auto v : n) std::cout << v << " "; };

    // s21::vector<std::string> v = {"abc","bcd"};

    // pr(v);

    // v.~auto();

    // pr(v);

//}



#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <array>

#include "s21_array.h"


#include "s21_containers.h"


// // TEST(Queue, Operator_Move) {
// //   s21::queue<int> our_queue_int = {1, 2, 3};
// //   std::queue<int> std_queue_int;
// //   std_queue_int.push(1);
// //   std_queue_int.push(2);
// //   std_queue_int.push(3);
// //   s21::queue<int> our_queue_empty;
// //   std::queue<int> std_queue_empty;
// //    our_queue_empty = std::move(our_queue_int);
// //   // std_queue_empty = std::move(std_queue_int);
// //   // EXPECT_EQ(our_queue_empty.front(), std_queue_empty.front());
// //   // EXPECT_EQ(our_queue_empty.back(), std_queue_empty.back());
// //   // EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
// // }





// int main(int argc, char* argv[]) {
//   testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }

// int main() {

//   auto f = [] (auto& v) { 
//     for (auto n : v) { 
//       std::cout << n << " ";
//     }
//   };

//   s21::list<int> a{1,2,4,3,4};
//   s21::list<int> b{3,4,5,3};
//   b = std::move(a);
//   f(b);
//   //f(a);


// }

int main() { 

  std::array<std::string,3> a {"aaaaaaaaaaaaaaaaa","cccc","cdfd"}; 
  s21::array<std::string,3> b {"aaaaaaaaaaaaaaaaa","cccc","cdfd"};

  std::array<std::string,3> c {"eweer","ererere","wrerer"};
  c = std::move(a);
  s21::array<std::string,3> d {"eweer","ererere","wrerer"};
  d = std::move(b);

  auto f = [] (auto v) { 
    for (auto a : v ) std::cout << a << " ";
    std::cout << "\n";
  };

  d.print();
 // d.print();
 f(c);
  a.swap(c);
  b.swap(d);

  std::cout << "=========\n" << a.size() << "-----" << c.size() << "\n";
  std::cout << "=========\n" << b.size() << "-----" << d.size() << "\n";
  std::cout << "=========\n";
  f(a);
  b.print();
  f(c);
  d.print();
    std::cout << "=========\n";
 std::array<int,3> t {1,2,3};
 s21::array<int,3> tt {1,2,3};

    f(t);
    f(tt);
    auto it = tt.end();
       std::cout << "=========\n";
       std::cout << *(--it);


  
  

}