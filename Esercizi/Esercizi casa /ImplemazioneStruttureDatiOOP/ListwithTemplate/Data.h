#ifndef DATA
#define DATA

template <typename T>
class Data {
private:
    T value;
public:
    explicit Data(T value);
    T getValue();
    void setValue(T value);
};
#endif // DATA_H
