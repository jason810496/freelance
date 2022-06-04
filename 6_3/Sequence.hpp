#include<string>

namespace CS52{
    class Sequence{
        public:
            virtual int size() const = 0 ;
            virtual int capacity() const = 0;
            virtual std::string type() const =0;
            virtual ~Sequence() {};
    };
    // class Container{
    //     public:
    //         std::string type() const ;
    // };  

}


// std::string CS52::Container::type() const {
    
//     return "CS52::Container";
// }
