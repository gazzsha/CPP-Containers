#include <iostream> 
#include "s21_vector.h"
#include <vector>
#include <algorithm>

int main() { 
    
    s21_vector<int> n(10); 
    s21_vector <int> v = n;
    std::vector<int> vv(10);


   std::cout << v.capacity();
   std::cout << v.at(5);
   v[9] = 10;  
    
    for (auto i = 0; i < v.size(); i++) { 
        std::cout << v[i] << " ";
    }

    std::cout << "\n";
    s21_vector<int>::iterator it = v.begin();
    *it = 2131;
    std::cout << *it; 
    s21_vector<std::string> ss;
   std::for_each(v.begin(), v.end(), [](const int n) { std::cout << n << ' '; });
   std::cout << "\n";
   std::cout << ss.empty();

   std::cout << "\n";

   s21_vector<std::string> c; 
   std::vector<std::string> cc;
   std::cout << c.max_size() << " --- " << cc.max_size();
   std::cout << "\n";
    std::vector<std::string> ss1(5);
   s21_vector<std::string> ss_v(5);
  std::cout << ss1[1];
  std::cout << ss_v[1];
     std::cout << "\n";
 // for (auto n : ss1) std::cout<<n;
  
   std::cout << ss1.capacity() << " - " << ss_v.capacity() << "\n";
   ss1.reserve(10);
   ss_v.reserve(10);
     std::cout << ss1.capacity() << " - " << ss_v.capacity() << " | " << ss1.size() << " - " << ss_v.size() << "\n";
     ss1.shrink_to_fit();
     ss_v.shrink_to_fit();
     std::cout << ss1.capacity() << " - " << ss_v.capacity() << " | " << ss1.size() << " - " << ss_v.size() << "\n";
     ss1.clear();
     ss_v.clear();
     std::cout << ss1.capacity() << " - " << ss_v.capacity() << " | " << ss1.size() << " - " << ss_v.size() << "\n";

    std::cout << "-------------------------\n";

    auto pr = [](auto& n) { for (const auto v : n) std::cout << v << " "; };

    s21_vector<int> is_v(5);
    std::vector<int> is(5);

    pr(is_v);
    std::cout << "\n";
    pr(is);
     std::cout << "\n";

    is_v.pop_back();
    is.pop_back();

    pr(is_v);
    std::cout << "\n";
    pr(is);
     std::cout << "\n";
     std::cout << is.capacity() << " - " << is_v.capacity() << " | " << is.size() << " - " << is_v.size() << "\n";
     s21_vector<int>::iterator it1_v = is_v.end();
     std::vector<int>::iterator it1 = is.end();
     *(--it1_v) = 5;
     *(--it1) = 5;
         std::cout << "\n";
     pr(is_v);
    std::cout << "\n";
    pr(is);
     std::cout << "\n";
     is.push_back(100);
     is_v.push_back(100);
          is.push_back(50);
     is_v.push_back(50);
          is.push_back(20);
     is_v.push_back(20);
          std::cout << "\n";
     pr(is_v);
    std::cout << "\n";
    pr(is);
     std::cout << "\n";
     std::cout << is.capacity() << " - " << is_v.capacity() << " | " << is.size() << " - " << is_v.size() << "\n";

    //  is.emplace_back(10,20,20);
    //  pr(is);

    std::vector<std::string> a(5);
    a.push_back("abc");
    pr(a);
    std::cout<<"size : " << a.size() << "\n";
  //  a.emplace_back("abc","abbc");
    pr(a);
        std::cout<<"size : " << a.size() << "\n";
    std::cout << "\n";
     s21_vector<std::string> b(5);
    b.push_back("abc");
        std::cout<<"size : " << b.size() << "\n";
    pr(b);
  //  b.emplace_back("abc","abbc");
    pr(b);
        std::cout<<"size : " << b.size() << "\n";
    std::cout << "\n";
    pr(is);
    std::cout << is.size() << " " << is.capacity() << "\n";
    is.erase(is.end() - 1);
    std::cout << "\n";
    pr(is);
     std::cout << is.size() << " " << is.capacity() << "\n";

     std::cout << "------------------\n";

     std::vector<std::string> z;
     s21_vector<std::string> z_v; 
     z.push_back("abc");
     z.push_back("cdv");
     z.push_back("321");


      z_v.push_back("abc");
     z_v.push_back("cdv");
      z_v.push_back("321");
     pr(z);
    std::cout << "\n";

     pr(z_v);
std::cout << "\n";
      std::cout << z.size() << " " << z.capacity() << "\n";
      std::cout << z_v.size() << " " << z_v.capacity() << "\n";
 //     z_v.erase(z_v.begin() + 1);
      //std::cout << *(z_v.begin() + 1) << "\n";
      pr(z_v);
      std::cout << "\n";
      std::cout << "===========\n";
      auto it_v = z_v.insert(z_v.end(),"100");
      pr(z_v);
     std::cout << *it_v << "\n";
      std::cout << "\n";
      auto it_o = z.insert(z.end(),"100");
      pr(z);
      std::cout << *it_o<<"\n";
        std::cout << "===========\n";
        s21_vector<std::string>  mm = {"anc","dff","ff"};
        std::vector<std::string>  m = {"anc","dff","ff"};
        pr(mm);
              std::cout << "\n";

       mm.reserve(10);

       auto itvv =  mm.insert_many(mm.end(),"aaa","bbbb","ccccc");

       std::cout << *itvv << "\n";

        pr(mm);

        mm.insert_many_back("A1","B2","B3");

        std::cout << "\n";
        pr(mm);

     



    




    // int * p = v.data(); 
    // std::cout << *(p+9);
    // std::vector<int>::iterator it = vv.begin(); 
    // std::cout << *it;
    // s21_vector<int>::iterator it; 
    // std::cout << *it;



    // std::vector<int> b(55);
    // std::cout << b.at(100);

}