// #include<string>

namespace CS52{
    class Sequence {
        public:
            virtual int size() const = 0 ;
            virtual int capcity() const = 0;
            virtual std::string type() const =0;
            virtual ~Sequence() {};
    };

}

