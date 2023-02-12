#include <vector>
#include <iostream>

//#define STD

#ifdef STD
#define NS std
#else
#define NS ft
#endif

int main()
{
    std::vector<int> myVector;
    std::cout << "Capacité initiale : " << myVector.capacity() << std::endl;
// #ifdef DEBUG
    for (int i = 0; i < 5; ++i)
    {
        myVector.push_back(i);
        std::cout << "Capacité : " << myVector.capacity() << " et la size : " << myVector.size() << std::endl;
    }
// #endif
    std::vector<int>::iterator it;
    it = myVector.begin();
    myVector.insert(it, {10,1,1,1});
    // myVector.push_back(25);
    // myVector.push_back(25);
        // myVector.push_back(32);
        // myVector.push_back(33);
    std::cout << "Capacité : " << myVector.capacity() << " et la size : " << myVector.size() << std::endl;
    std::cout << "max size : " << myVector.max_size() << std::endl;

    // // myVector.clear();
    // // myVector.pop_back();
    try{
        myVector.reserve(2147999999);
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    // std::cout << "Capacité : " << myVector.capacity() << " et la size : " << myVector.size() << std::endl;
    return 0;
}


// int main ()
// {
//   std::vector<int> myvector;

//   // set some content in the vector:
//   for (int i=0; i<100; i++) myvector.push_back(i);

//   std::cout << "size: " << myvector.size() << "\n";
//   std::cout << "capacity: " << myvector.capacity() << "\n";
//   std::cout << "max_size: " << myvector.max_size() << "\n";
//   return 0;
// }


// vector::reserve
// #include <iostream>
// #include <vector>

// int main ()
// {
//   std::vector<int>::size_type sz;

//   std::vector<int> foo;
//   sz = foo.capacity();
//   std::cout << "making foo grow:\n";
//   for (int i=0; i<100; ++i) {
//     foo.push_back(i);
//     if (sz!=foo.capacity()) {
//       sz = foo.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }

//   std::vector<int> bar;
//   sz = bar.capacity();
//   bar.reserve(-1);   // this is the only difference with foo above
//   std::cout << "making bar grow:\n";
//   for (int i=0; i<100; ++i) {
//     bar.push_back(i);
//     if (sz!=bar.capacity()) {
//       sz = bar.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }
//   return 0;
// }