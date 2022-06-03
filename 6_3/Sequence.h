// #include<string>

namespace CS52{
    class Sequence : public Container{
        public:
            virtual int size() const = 0 ;
            virtual int capcity() const = 0;
            virtual std::string type() const = 0;
            virtual ~Sequence() {}
    }
}



std::string CS52::Sequence::type(){
    std::string ret = "CS52::Container";
    return ret;
}