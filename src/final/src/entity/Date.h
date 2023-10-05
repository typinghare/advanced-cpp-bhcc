#ifndef ADVANCED_CPP_BHCC_DATE_H
#define ADVANCED_CPP_BHCC_DATE_H

class Date {
private:
    short year;
    short month;
    short day;
public:
    /**
     * Creates a date.
     * @param year The year of this date.
     * @param month The month of this date.
     * @param day The day of this date.
     */
    Date(short year, short month, short day);

    /**
     * Returns the year of this date.
     * @return the year of this date.
     */
    [[nodiscard]] short getYear() const;

    /**
     * Returns the month of this date.
     * @return the month of this date.
     */
    [[nodiscard]] short getMonth() const;

    /**
     * Returns the day of this date.
     * @return the day of this date.
     */
    [[nodiscard]] short getDay() const;
};

#endif
