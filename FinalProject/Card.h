#include <string>
class Card{
    private:
        std::string suite;
        std::string value;
    public:
        std::string getSuite();
        void setSuite(std::string value);
        std::stirng getValue();
        void setValue(std::string name);
}