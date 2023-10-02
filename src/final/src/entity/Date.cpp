#include "Date.h"

Date::Date(
    short year,
    short month,
    short day
) : year(year), month(month), day(day) {
}

short Date::getYear() const {
    return year;
}

short Date::getMonth() const {
    return month;
}

short Date::getDay() const {
    return day;
}