#ifndef ADVANCED_CPP_BHCC_DATE_H
#define ADVANCED_CPP_BHCC_DATE_H

class Date {
private:
    short year;
    short month;
    short day;
public:
    Date(short year, short month, short day);

    [[nodiscard]] short getYear() const;

    [[nodiscard]] short getMonth() const;

    [[nodiscard]] short getDay() const;
};

#endif
